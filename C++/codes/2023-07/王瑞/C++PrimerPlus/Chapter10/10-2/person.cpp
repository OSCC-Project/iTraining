#include "person.h"
#include <cstring>
#include <iostream>

Person::Person(const std::string &ln, const char *fn) {
  lname = ln;
  strcpy(fname, fn);
}

void Person::showPerson() const {
  std::cout << fname << " " << lname << std::endl;
}

void Person::formalShowPerson() const {
  std::cout << lname << " " << fname << std::endl;
}