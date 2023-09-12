#include "golf.h"
#include <cstring>
#include <iostream>

Golf::Golf() {
  std::cout << "Please enter the Golf's fullname: \n";
  std::cin >> fullname;
  std::cout << "Please enter the Golf's handicap: \n";
  std::cin >> handicap;
}

Golf::Golf(const char *name, int hc) {
  strcpy(this->fullname, name);
  handicap = hc;
}

Golf::~Golf() {}

void Golf::setHandicap(const int hc) { handicap = hc; }

void Golf::showGolf() const {
  std::cout << "the Golf's information is as follows: " << std::endl;
  std::cout << "the fullname is: " << this->fullname << std::endl;
  std::cout << "the handicap is: " << handicap << std::endl;
}