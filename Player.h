#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class Player {
 public:
  Player(string fName, string lName, unsigned int num);
  Player();
  ~Player();
  Player &operator=(const Player &c);
  Player(const Player &c);
  void showPlayer();
  void setPlayerFirstName(string name);
  void setPlayerLastName(string name);
  void setPlayerNumber(int num);
  void setPlayerTeam(string name);
  void setPrefNum(int num);
  void setRecentNum(int num);
  string getLastName();
  int getPlayerNumber();
  string getPlayerTeam();
  int getPrefNum();
  int getRecentNum();
  void addCareer(string name, int num);
  void showCareerArray();
  void showCareer();
 private:
  string *careers;
  int numCareers = 0;
  int careersCapacity = 1;
  string firstName = "";
  string lastName = "";
  string playerTeam = "";
  unsigned int jerseyNumber = -1;
  int prefNum = 0;
  int recentNum = 0;
};

#endif
