#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Team.h"

Team::Team(string location, string name) {
  teamName = name;
  teamLocation = location;
  numPlayers = 0;
  playersCapacity = 1;  
  players = new Player[playersCapacity];
}

Team::Team() {
  teamName = "";
  teamLocation = "";
  numPlayers = 0;
  playersCapacity = 1;  
  players = new Player[playersCapacity];
}

Team::~Team() {
  delete []players;
}

Team &Team::operator=(const Team &teamCopy) {
  if (this == &teamCopy) {
    return *this;
  }

  delete []players;
  teamLocation = teamCopy.teamLocation;
  teamName = teamCopy.teamName;
  numPlayers = teamCopy.numPlayers;
  playersCapacity = teamCopy.playersCapacity;
  players = new Player[playersCapacity];

  for (int i = 0; i < numPlayers; ++i) {
    players[i] = teamCopy.players[i];
  }

  return *this;
}

Team::Team(const Team &teamCopy) {
  teamLocation = teamCopy.teamLocation;
  teamName = teamCopy.teamName;
  numPlayers = teamCopy.numPlayers;
  playersCapacity = teamCopy.playersCapacity;
  players = new Player[playersCapacity];

  for (int i = 0; i < numPlayers; ++i) {
    players[i] = teamCopy.players[i];
  }

}

string Team::getNickName() {
  return teamName;
}

int Team::getNumPlayers() {
  return numPlayers;
}

void Team::setTeamName(string name) {
  teamName = name;
}

void Team::setTeamLocation(string name) {
  teamLocation = name;
}

void Team::addPlayer(const Player &player) {
  if (numPlayers == playersCapacity) {
    playersCapacity = playersCapacity * 2;
  }
  Player *tempPlayers;
  tempPlayers = new Player[playersCapacity];
  for (int i = 0; i < numPlayers; ++i) {
    tempPlayers[i] = players[i];
  }
  delete []players;
  tempPlayers[numPlayers] = player;
  numPlayers++;
  players = tempPlayers;
}
/*
void Team::addPlayerWithTeam(Player &player, const string &career) {
  if (numPlayers == playersCapacity) {
    playersCapacity = playersCapacity * 2;
  }
  Player *tempPlayers;
  tempPlayers = new Player[playersCapacity];
  for (int i = 0; i < numPlayers; ++i) {
    tempPlayers[i] = players[i];
  }
  delete []players;
  player.addCareer(career);
  tempPlayers[numPlayers] = player;
  numPlayers++;
  players = tempPlayers;
}
*/

void Team::showTeam() {
  cout << teamLocation << " " << teamName << "";
}

void Team::showTeamArray() {
  for (int i = 0; i < numPlayers; ++i) {
    players[i].showPlayer();
  }
}

Player &Team::getPlayer(string name) {
  int g;
  int index;
  for (g = 0; g < numPlayers; ++g) {
    if (name == players[g].getLastName()) { //in team
      index = g;
    }
  }
  //cout << players[index].getLastName() << endl;
  return players[index];
}

void Team::removePlayer(string name) {
  for (int i = 0; i < numPlayers; ++i) {
    if (name == players[i].getLastName()) {
      //delete players[i];
      for (int j = i; j < numPlayers - 1; ++j) {
        players[j] = players[j+1];
      }
    }
  }
  numPlayers--;
}

void Team::showNumPlayers() {
  cout << " (" << numPlayers << " players)" << endl;
}

bool Team::doesPlayerExist(string name) {
  bool exists = false;
  for (int k = 0; k < numPlayers; ++k) {
    if (name == players[k].getLastName()) {
      exists = true;
    }
  }
  return exists;
}

bool Team::doesNumberExist(int num) {
  bool exists = false;
  for (int k = 0; k < numPlayers; ++k) {
    if (num == players[k].getPlayerNumber()) {
      exists = true;
    }
  }
  return exists;
}

int Team::getLowestNumber() {
  int min = 1;
  //check for a zero, if no zero return zero
  for (int i = 0; i <= numPlayers; ++i) {
    if (players[i].getPlayerNumber() == min) {
      min++;
      //continue;
      i = 0;
    }
  }
  return min;
}
  
/*
int Team::getLowestNumber() {
  int min = 0;
  min = players[0].getPlayerNumber();
  for (int i = 0; i < numPlayers; ++i) {
    if (players[i].getPlayerNumber() > min) {
      min = players[i].getPlayerNumber() - 1;
    }
  }
  return min;
}
*/


  //this is close to working but need case where all of the below are taken. ex player #0,1,2,3 and you try to add #2. it defaults to 0
  //also need to add prefnum to player params
  //i think that should be it
