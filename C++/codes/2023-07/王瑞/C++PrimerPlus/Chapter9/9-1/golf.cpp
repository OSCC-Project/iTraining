#include "golf.h"
#include <cstring>
#include <iostream>

void setGolf(golf &g, const char *name, int hc) {
  strcpy(g.fullname, name);
  g.handicap = hc;
}

int setGolf(golf &g) {
  std::cout << "Please enter the fullname: " << std::endl;
  std::cin.getline(g.fullname, Len);
  if (strcmp(g.fullname, "") == 0) {
    return 0;
  }
  std::cout << "Please enter the handicap: " << std::endl;
  while (!(std::cin >> g.handicap)) {
    std::cin.clear();
    while (std::cin.get() != '\n')
      continue;
    std::cout << "Please enter a number: " << std::endl;
  }
  return 1;
}

void setHandicap(golf &g, int hc) { g.handicap = hc; }

void showGolf(const golf &g) {
  std::cout << "The golf's name is " << g.fullname << std::endl;
  std::cout << "The golf's hanicap is " << g.handicap << std::endl;
}