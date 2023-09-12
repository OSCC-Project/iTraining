#include "cow.h"
#include <cstring>
#include <iostream>
#include <string.h>

Cow::Cow() {
  strcpy(_name, "no name");
  _hobby = new char[20];
  strcpy(_hobby, "no hobby");
  _weight = 0.0;
}

Cow::Cow(const char *nm, const char *ho, double wt) {
  strcpy(_name, nm);
  _hobby = new char[strlen(nm) + 1];
  strcpy(_hobby, ho);
  _weight = wt;
}

Cow::Cow(const Cow &c) {
  strcpy(_name, c._name);
  _hobby = new char[strlen(c._hobby) + 1];
  strcpy(_hobby, c._hobby);
  _weight = c._weight;
}

Cow::~Cow() { delete[] _hobby; }

Cow &Cow::operator=(const Cow &c) {
  if (this == &c) {
    return *this;
  }
  delete[] _hobby;
  strcpy(_name, c._name);
  _hobby = new char[(strlen(c._hobby) + 1)];
  strcpy(_hobby, c._hobby);
  _weight = c._weight;
  return *this;
}

void Cow::showCow() const {
  std::cout << "_name : " << _name << std::endl;
  std::cout << "_hobby : " << _hobby << std::endl;
  std::cout << "weght : " << _weight << std::endl;
}