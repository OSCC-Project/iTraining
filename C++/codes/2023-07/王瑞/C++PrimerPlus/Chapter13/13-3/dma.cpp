#include "dma.h"
#include <cstring>

ABC::ABC() {}

ABC::~ABC() {}

baseDMA::baseDMA(const char *l, int r) {
  this->_label = new char[strlen(l) + 1];
  strcpy(this->_label, l);
  this->_rating = r;
}

baseDMA::baseDMA(const baseDMA &rs) {
  this->_rating = rs._rating;
  this->_label = new char[strlen(rs._label) + 1];
  strcpy(this->_label, rs._label);
}

baseDMA::~baseDMA() {
  if (this->_label != nullptr) {
    delete[] this->_label;
    this->_label = nullptr;
    this->_rating = 0;
  }
}

baseDMA &baseDMA::operator=(const baseDMA &rs) {
  if (this == &rs) {
    return *this;
  }
  if (this != nullptr) {
    delete[] this->_label;
    this->_label = nullptr;
    this->_rating = 0;
  }
  this->_rating = rs._rating;
  this->_label = new char[strlen(rs._label) + 1];
  strcpy(this->_label, rs._label);
  return *this;
}

std::ostream &operator<<(std::ostream &os, const baseDMA &rs) {
  os << "_label: " << rs._label << std::endl;
  os << "_rating: " << rs._rating << std::endl;
  return os;
}

void baseDMA::viewInfo() {
  std::cout << "_label: " << _label << std::endl;
  std::cout << "_rating: " << _rating << std::endl;
}

lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l, r) {
  strcpy(this->_color, c);
}

lacksDMA::lacksDMA(const char *c, const baseDMA &rs) : baseDMA(rs) {
  strcpy(this->_color, c);
}

std::ostream &operator<<(std::ostream &os, const lacksDMA &ls) {
  os << (const baseDMA &)ls;
  os << "Color: " << ls._color << std::endl;
  return os;
}

void lacksDMA::viewInfo() {
  baseDMA::viewInfo();
  std::cout << "color: " << _color << std::endl;
}

hasDMA::hasDMA(const char *s, const char *l, int r) : baseDMA(l, r) {
  _style = new char[std::strlen(s) + 1];
  strcpy(_style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs) : baseDMA(rs) {
  _style = new char[std::strlen(s) + 1];
  strcpy(_style, s);
}

hasDMA::hasDMA(const hasDMA &hs) : baseDMA(hs) {
  _style = new char[std::strlen(hs._style) + 1];
  strcpy(_style, hs._style);
}

hasDMA::~hasDMA() {
  if (this != nullptr) {
    delete[] _style;
  }
}
hasDMA &hasDMA::operator=(const hasDMA &hs) {
  if (this == &hs)
    return *this;
  baseDMA::operator=(hs);
  delete[] _style;
  _style = new char[std::strlen(hs._style) + 1];
  strcpy(_style, hs._style);
  return *this;
}

std::ostream &operator<<(std::ostream &os, const hasDMA &hs) {
  os << (const baseDMA &)hs;
  os << "Style: " << hs._style << std::endl;
  return os;
}

void hasDMA::viewInfo() {
  baseDMA::viewInfo();
  std::cout << "Style: " << _style << std::endl;
}