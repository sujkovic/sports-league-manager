#include <iostream>
#include <stdlib.h>
using namespace std;
#include "League.h"
#include "Team.h"

League::League() {
  teamsLength = 0;
  teamsCapacity = 1;
  teams = new Team[teamsCapacity];
  agents = new Team("Free", "Agents");
}

League::~League() {
  delete []teams;
  delete agents;
}

void League::addTeam(const Team &team) {
  if (teamsLength == teamsCapacity) {
    teamsCapacity = teamsCapacity * 2;
  }

  Team *tempTeam;
  tempTeam = new Team[teamsCapacity];
  for (int i = 0; i < teamsLength; ++i) {
    tempTeam[i] = teams[i];
  }

  delete []teams;
  tempTeam[teamsLength] = team;
  teamsLength++;
  teams = tempTeam;
}

Team &League::compareTeam(string name) {
  int g;
  int index;
  for (g = 0; g < teamsLength; ++g) {
    if (name == teams[g].getNickName()) { //in team
      index = g;
    }
  }
  return teams[index];
}

void League::showLeague() {
  cout << "Teams:" << teamsLength << endl;
  for (int i = 0; i < teamsLength; i++) {
    teams[i].showTeam();
    teams[i].showNumPlayers();
  }
}

bool League::checkDuplicate(string name) {
  bool dup = false;
    for (int j = 0; j < teamsLength; ++j) {
      if (name == teams[j].getNickName()) {
	      dup = true;
      }
    }
  return dup;
}

bool League::doesTeamExist(string name) {
  bool exists = false;
  for (int k = 0; k < teamsLength; ++k) {
    if (name == teams[k].getNickName()) {
      exists = true;
    }
  }
  return exists;
}


Player &League::findPlayer(string name) {
  int g;
  for (g = 0; g < teamsLength; ++g) {
    //for (int k = 0; k < )
    if (teams[g].doesPlayerExist(name) == true) {
      return teams[g].getPlayer(name);
    }
  }
}

