#include "classic.h"
#include <cstring>
#include <iostream>

Cd::Cd(char *s1, char *s2, int n, double x) {
  strcpy(this->_performers, s1);
  strcpy(this->_label, s2);
  this->_selections = n;
  this->_playtime = x;
}

Cd::Cd(const Cd &d) {
  strcpy(this->_performers, d._performers);
  strcpy(this->_label, d._label);
  this->_selections = d._selections;
  this->_playtime = d._playtime;
}

Cd::Cd() {
  strcpy(this->_performers, "NULL");
  strcpy(this->_label, "NULL");
  this->_selections = 0;
  this->_playtime = 0;
}

Cd::~Cd() {}

void Cd::reportInfo() const {
  std::cout << "_performers: " << this->_performers << std::endl;
  std::cout << "_label: " << this->_label << std::endl;
  std::cout << "_selections: " << this->_selections << std::endl;
  std::cout << "_playtime: " << this->_playtime << std::endl;
}

Cd &Cd::operator=(const Cd &d) {
  if (this == &d) {
    return *this;
  }
  strcpy(this->_performers, d._performers);
  strcpy(this->_label, d._label);
  this->_selections = d._selections;
  this->_playtime = d._playtime;
  return *this;
}

Classic::Classic(char *s0, char *s1, char *s2, int n, double x)
    : Cd(s1, s2, n, x) {
  strcpy(this->_mainworks, s0);
}

Classic::Classic(char *s0, Cd &rs) : Cd(rs) { strcpy(this->_mainworks, s0); }

Classic::Classic() {
  Cd();
  strcpy(this->_mainworks, "NULL");
}

Classic::~Classic() {}

void Classic::reportInfo() const {
  std::cout << "_mainworks: " << this->_mainworks << std::endl;
  Cd::reportInfo();
}

Classic &Classic::operator=(const Classic &d) {
  if (this == &d) {
    return *this;
  }
  Cd::operator=(d);
  strcpy(this->_mainworks, d._mainworks);
  return *this;
}