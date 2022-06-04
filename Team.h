#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
#include "Player.h"

class Team {
  
 public:
  Team(string location, string name);
  Team();
  ~Team();
  Team &operator=(const Team &playersCopy);
  Team(const Team &playersCopy);
  string getNickName();
  int getNumPlayers();
  void setTeamName(string name);
  void setTeamLocation(string name);
  void addPlayer(const Player &player);
  void showTeam();
  void showTeamArray();
  Player &getPlayer(string name);
  void removePlayer(string name);
  void showNumPlayers();
  bool doesPlayerExist(string name);
  bool doesNumberExist(int num);
  int getLowestNumber();

 private:
  Player *players;
  string teamName = "";
  string teamLocation = "";
  int numPlayers = 0;
  int playersCapacity = 1;
  
};

#endif
