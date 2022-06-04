#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Parser.h"
#include "League.h"
#include "Team.h"
#include "Player.h"


Team playerTeam;
Player ourPlayer;
League league;
bool isDuplicate;
int tempNum;
string tempString;
string line;
int int_param;
Team *agents = new Team("Free", "Agents");

//Parser fuctions
void do_team(string loc, string name) {
	playerTeam.setTeamName(name);			//setters
	playerTeam.setTeamLocation(loc);

	isDuplicate = league.checkDuplicate(name);		//adding team
	if (isDuplicate == true) {
  		cout << "Duplicate team nickname " << name << " not added" << endl;
	}
	else if (name != "") {
		league.addTeam(playerTeam);
	}
}

void do_player(string fname, string lname, int num, string tname) {	
	string playerCareer;											
		if (league.doesTeamExist(tname) == false) {
		cout << "Could not add the player to team " << tname;
		}
		else {	
			ourPlayer.setPlayerFirstName(fname);
  			ourPlayer.setPlayerLastName(lname);
			if (league.compareTeam(tname).doesNumberExist(num) == false) {
				ourPlayer.setPlayerNumber(num);
				ourPlayer.setPrefNum(num);
				ourPlayer.setRecentNum(num);
			}
			else {
				ourPlayer.setPlayerNumber(league.compareTeam(tname).getLowestNumber());
				ourPlayer.setPrefNum(league.compareTeam(tname).getLowestNumber());
				ourPlayer.setRecentNum(league.compareTeam(tname).getLowestNumber());
			}
			ourPlayer.setPlayerTeam(tname);
  			league.compareTeam(tname).addPlayer(ourPlayer);
			league.compareTeam(tname).getPlayer(lname).addCareer(tname, league.compareTeam(tname).getPlayer(lname).getPlayerNumber());
		}
}

void do_playerWithoutTeam(string fname, string lname, int num) {
	ourPlayer.setPlayerFirstName(fname);
	ourPlayer.setPlayerLastName(lname);
	ourPlayer.setPlayerNumber(num);
	ourPlayer.setPrefNum(num);
  	agents->addPlayer(ourPlayer);

}

void do_league() {
	league.showLeague();
}

void do_roster(string team) {

	if (league.doesTeamExist(team) == false) {
		cout << "Could not find team with nickname of " << team << endl;
	}
	else {
		league.compareTeam(team).showTeam();
		cout << endl << "Players:";
		cout << endl;
		league.compareTeam(team).showTeamArray();
	}
}

void do_showFreeAgents() {
	cout << "Free Agents:" << endl;
	agents->showTeamArray();
}

void do_releasePlayer(string name, string team) {
	if (league.doesTeamExist(team) == false) {
		cout << "Team " << team << " does not exist." << endl;
	}
	else if (league.compareTeam(team).doesPlayerExist(name) == false) {
		cout << "Player " << name << " is not currently on team " << team << endl;
	}
	else {
		agents->addPlayer(league.compareTeam(team).getPlayer(name));
		league.compareTeam(team).removePlayer(name);							
		cout << "Release " << name << " from " << team << endl;
		cout << "Player " << name << " added to free agents" << endl;
	}
}

void do_signPlayer(string name, string team) {
	if (league.doesTeamExist(team) == false) {
		cout << "Team " << team << " does not exist." << endl;
	}
	else if (agents->doesPlayerExist(name) == false) {
		cout << "Player " << name << " is not a free agent." << endl;
	}
	else {
		if (league.compareTeam(team).doesNumberExist(agents->getPlayer(name).getPrefNum()) == false) {
			agents->getPlayer(name).setPlayerNumber(agents->getPlayer(name).getPrefNum());
			agents->getPlayer(name).setRecentNum(agents->getPlayer(name).getPrefNum());
		}
		else {
			if (league.compareTeam(team).doesNumberExist(agents->getPlayer(name).getRecentNum()) == false) {
				agents->getPlayer(name).setPlayerNumber(agents->getPlayer(name).getRecentNum());
			}
			else {
				agents->getPlayer(name).setPlayerNumber(league.compareTeam(team).getLowestNumber());
				agents->getPlayer(name).setRecentNum(league.compareTeam(team).getLowestNumber());
			}
		}
		agents->getPlayer(name).addCareer(team, agents->getPlayer(name).getPlayerNumber());
		league.compareTeam(team).addPlayer(agents->getPlayer(name));
		agents->removePlayer(name);
	}
}

void do_career(string name) {
	if (agents->doesPlayerExist(name) == true) {
		cout << "Career of " << name << endl;
		agents->getPlayer(name).showCareerArray();
	}
	else {
		cout << "Career of " << name << endl;
		league.findPlayer(name).showCareerArray();
	}
}

int main() {

	while (1) {						//	Menu loop	//
	  cout << endl << "Enter a command: " << endl << "Choose from " << endl;
	  cout << "   Team <location> <team-nickname>" << endl;
  	  cout << "   Player <firstname> <lastname> <number> [<team-nickname>]" << endl;
  	  cout << "   League" << endl;
  	  cout << "   Roster [<team-nickname>]" << endl;
  	  cout << "   Release <lastname> <team-nickname>" << endl;
  	  cout << "   Sign <lastname> <team-nickname>" << endl;
  	  cout << "   Career <lastname>" << endl;
  	  cout << "   Trade" << endl;
  	  cout << "   Quit" << endl;
  	  cout << ": ";
	  getline(cin, line);
  	  Parser command(line);
	  if (command.getOperation().empty()) {
	  	if (cin.fail()) {break;}
	  	continue;
  	  }

      if (command.getOperation() == "Team") {				//	Team	//
		  if (command.numArgs() < 2) {
			  cout << endl << MISSING_ARGS << endl;
		  }
		  else {
			do_team(command.getArg1(), command.getArg2());
		  if (command.numArgs() > 2) {
			  cout << endl << "Ignoring " << UNEXPECTED_ARGS << endl;
		  }
	  }
	  }

      else if (command.getOperation() == "Player") {		//	Players	//
	  	  if (command.numArgs() < 3) {
			  cout << endl << MISSING_ARGS << endl;
		  }											
		  else if (command.numArgs() == 3) {
			  if (Parser::isInteger(command.getArg3())) {
				  int_param = stoi(command.getArg3());
				  do_playerWithoutTeam(command.getArg1(), command.getArg2(), int_param);
			  }
			  else {
				  cout << "Error: arg3: " << command.getArg3() << " is not an integer" << endl;
			  }
		  }
		  else if (command.numArgs() == 4) {
			  if (Parser::isInteger(command.getArg3())) {
				  int_param = stoi(command.getArg3());
				  do_player(command.getArg1(), command.getArg2(), int_param, command.getArg4());
			  }
			  else {
				  cout << "Error: arg3: " << command.getArg3() << " is not an integer" << endl;
			  }
		  }
		  else if (command.numArgs() > 4) {
			  cout << endl << "Ignoring " << UNEXPECTED_ARGS << endl;
		  }
      }

      else if (command.getOperation() == "League") {					//	League	//
		do_league();
		if (command.numArgs() > 0) {
			cout << endl << "Ignoring " << UNEXPECTED_ARGS << endl;
		}
      }

      else if (command.getOperation() == "Roster") {					//	Roster	//
		if (command.numArgs() == 0) {
			do_showFreeAgents();
		}
		else {
		  do_roster(command.getArg1());
		  if (command.numArgs() > 1) {
			cout << endl << "Ignoring " << UNEXPECTED_ARGS << endl;
		}
      }
	  }

	  else if (command.getOperation() == "Release") {
		  if (command.numArgs() < 2) {
			  cout << endl << MISSING_ARGS << endl;
		  }
		  else  {
		  do_releasePlayer(command.getArg1(), command.getArg2());
		  if (command.numArgs() > 2) {
			  cout << endl << "Ignoring " << UNEXPECTED_ARGS << endl;
		  }
	  }
	  }

	  else if (command.getOperation() == "Sign") {
		  if (command.numArgs() < 2) {
			  cout << endl << MISSING_ARGS << endl;
		  }
		  else  {
		  do_signPlayer(command.getArg1(), command.getArg2());
		  if (command.numArgs() > 2) {
			  cout << endl << "Ignoring " << UNEXPECTED_ARGS << endl;
		  }
	  }
	  }

	  else if (command.getOperation() == "Career") {
		  if (command.numArgs() < 1) {
			  cout << endl << MISSING_ARGS << endl;
		  }
		  else {
		  do_career(command.getArg1());
		  if (command.numArgs() > 1) {
			  cout << endl << "Ignoring " << UNEXPECTED_ARGS << endl;
		  }
	  }
	  }


      else if (command.getOperation() == "Quit") {					//	Quit   //
		break;
      }

      else {										//	Error checking	//
		cout << "Command " << command.getOperation() << " not recognized. Please try again." << endl;
	  }

    }
	
	delete agents;
}
