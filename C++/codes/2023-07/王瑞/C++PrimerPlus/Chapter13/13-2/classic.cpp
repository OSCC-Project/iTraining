#include "classic.h"
#include <cstring>
#include <iostream>

Cd::Cd(char *s1, char *s2, int n, double x) {
  this->_performers = new char[strlen(s1) + 1];
  this->_label = new char[strlen(s2) + 1];
  strcpy(this->_performers, s1);
  strcpy(this->_label, s2);
  this->_selections = n;
  this->_playtime = x;
}

Cd::Cd(const Cd &d) {
  if (this != nullptr) {
    delete[] this->_performers;
    delete[] this->_label;
    this->_performers = nullptr;
    this->_label = nullptr;
  }
  this->_performers = new char[strlen(d._performers) + 1];
  this->_label = new char[strlen(d._label) + 1];
  strcpy(this->_performers, d._performers);
  strcpy(this->_label, d._label);
  this->_selections = d._selections;
  this->_playtime = d._playtime;
}

Cd::Cd() {
  this->_performers = nullptr;
  this->_label = nullptr;
  this->_selections = 0;
  this->_playtime = 0;
}

Cd::~Cd() {
  if (this != nullptr) {
    delete[] this->_performers;
    delete[] this->_label;
    this->_performers = nullptr;
    this->_label = nullptr;
  }
}

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
  if (this != nullptr) {
    delete[] this->_performers;
    delete[] this->_label;
    this->_performers = nullptr;
    this->_label = nullptr;
  }
  this->_performers = new char[strlen(d._performers) + 1];
  this->_label = new char[strlen(d._label) + 1];
  strcpy(this->_performers, d._performers);
  strcpy(this->_label, d._label);
  this->_selections = d._selections;
  this->_playtime = d._playtime;
  return *this;
}

Classic::Classic(char *s0, char *s1, char *s2, int n, double x)
    : Cd(s1, s2, n, x) {
  this->_mainworks = new char[strlen(s0) + 1];
  strcpy(this->_mainworks, s0);
}

Classic::Classic(char *s0, Cd &rs) : Cd(rs) {
  this->_mainworks = new char[strlen(s0) + 1];
  strcpy(this->_mainworks, s0);
}

Classic::Classic() : Cd() { this->_mainworks = nullptr; }

Classic::~Classic() {
  if (this != nullptr) {
    delete[] this->_mainworks;
    this->_mainworks = nullptr;
  }
}

void Classic::reportInfo() const {
  std::cout << "_mainworks: " << this->_mainworks << std::endl;
  Cd::reportInfo();
}

Classic &Classic::operator=(const Classic &d) {
  if (this == &d) {
    return *this;
  }
  if (this != nullptr) {
    delete[] this->_mainworks;
    this->_mainworks = nullptr;
  }
  this->_mainworks = new char[strlen(d._mainworks) + 1];
  strcpy(this->_mainworks, d._mainworks);
  Cd::operator=(d);
  return *this;
}