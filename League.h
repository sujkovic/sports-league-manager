#ifndef LEAGUE_H
#define LEAGUE_H
#include <iostream>
#include <stdlib.h>
#include "Team.h"

class League {
 public:
  League(); 
  ~League();
  void addTeam(const Team &team);
  Team &compareTeam(string name);
  void showLeague();
  bool checkDuplicate(string name);
  bool doesTeamExist(string name);
  Player &findPlayer(string name);
  Team *agents;
 private:
  Team *teams;
  int teamsLength = 0;
  int teamsCapacity = 1;
  string nickName = "";
};
#endif
