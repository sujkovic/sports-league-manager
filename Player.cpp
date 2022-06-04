#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Player.h"

Player::Player(string fName, string lName, unsigned int num) {
  firstName = fName;
  lastName = lName;
  jerseyNumber = num;
  prefNum = 0;
  recentNum = 0;
  numCareers = 0;
  careersCapacity = 1;
  playerTeam = "";
  careers = new string[careersCapacity];
}

Player::Player() {
  firstName = "";
  lastName = "";
  jerseyNumber = -1;
  prefNum = 0;
  recentNum = 0;
  numCareers = 0;
  careersCapacity = 1;
  playerTeam = "";
  careers = new string[careersCapacity];
}

Player::~Player() {
  delete []careers;
}

Player &Player::operator=(const Player &c) {
  if (this == &c) {
    return *this;
  }

  delete []careers;
  firstName = c.firstName;
  lastName = c.lastName;
  jerseyNumber = c.jerseyNumber;
  prefNum = c.prefNum;
  recentNum = c.recentNum;
  numCareers = c.numCareers;
  careersCapacity = c.careersCapacity;
  playerTeam = c.playerTeam;
  careers = new string[careersCapacity];

  for (int i = 0; i < numCareers; ++i) {
    careers[i] = c.careers[i];
  }

  return *this;
}

Player::Player(const Player &c) {
  firstName = c.firstName;
  lastName = c.lastName;
  jerseyNumber = c.jerseyNumber;
  prefNum = c.prefNum;
  recentNum = c.recentNum;
  numCareers = c.numCareers;
  careersCapacity = c.careersCapacity;
  playerTeam = c.playerTeam;
  careers = new string[careersCapacity];

  for (int i = 0; i < numCareers; ++i) {
    careers[i] = c.careers[i];
  }  
}

void Player::showPlayer() {
  cout << lastName << ", " << firstName << " (#" << jerseyNumber << ")" << endl;
}

void Player::setPlayerFirstName(string name) {
  firstName = name;
}
void Player::setPlayerLastName(string name) {
  lastName = name;
}
void Player::setPlayerNumber(int num) {
  jerseyNumber = num;
}
void Player::setPlayerTeam(string name) {
  playerTeam = name;
}
void Player::setPrefNum(int num) {
  prefNum = num;
}
void Player::setRecentNum(int num) {
  recentNum = num;
}

string Player::getLastName() {
  return lastName;
}

int Player::getPlayerNumber() {
  return jerseyNumber;
}

int Player::getPrefNum() {
  return prefNum;
}

string Player::getPlayerTeam() {
  return playerTeam;
}

int Player::getRecentNum() {
  return recentNum;
}

void Player::addCareer(string name, int num) {
  if (numCareers == careersCapacity) {
    careersCapacity = careersCapacity * 2;
  }
  string *tempCareers;
  tempCareers = new string[careersCapacity];
  for (int i = 0; i < numCareers; ++i) {
    tempCareers[i] = careers[i];
  }
  delete []careers;
  string numString = to_string(num);
  tempCareers[numCareers] = name + " (#" + numString + ")";
  numCareers++;
  careers = tempCareers;
}

void Player::showCareerArray() {
  for (int i = 0; i < numCareers; ++i) {
    cout << careers[i] << endl;
  }
}
