#include "plorg.h"
#include <cstring>
#include <iostream>

Plorg::Plorg() {
  strcpy(_name, "Plorga");
  _CI = 50;
}

Plorg::Plorg(const char *name) { strcpy(_name, name); }

Plorg::~Plorg() {}

void Plorg::changePlorg(const int c) { _CI = c; }

void Plorg::showPlorg() const {
  std::cout << "the name is " << _name << std::endl;
  std::cout << "the CI is " << _CI << std::endl;
}