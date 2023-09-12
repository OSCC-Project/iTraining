#include "string2.h"
#include <cctype>
#include <cstring>

int String::_num_strings = 0;

int String::HowMany() { return _num_strings; }

String::String() {
  _len = 10;
  _str = new char[_len + 1];
  strcpy(_str, "no string");
  _str[_len] = '\0';
  _num_strings++;
}

String::String(const char *s) {
  _len = strlen(s);
  _str = new char[_len + 1];
  strcpy(_str, s);
  _str[_len] = '\0';
  _num_strings++;
}

String::String(const String &s) {
  _num_strings++;
  _len = s._len;
  _str = new char[_len + 1];
  strcpy(_str, s._str);
  _str[_len] = '\0';
}

String::~String() {
  --_num_strings;
  delete[] _str;
}

void String::stringlow() {
  for (int i = 0; i < this->_len + 1; i++) {
    this->_str[i] = tolower(this->_str[i]);
  }
}

void String::stringup() {
  for (int i = 0; i < this->_len + 1; i++) {
    this->_str[i] = toupper(this->_str[i]);
  }
}

int String::has(char c) {
  int count = 0;
  for (int i = 0; i < this->_len + 1; i++) {
    if (this->_str[i] == c) {
      count++;
    }
  }
  return count;
}

String &String::operator=(const String &s) {
  if (this == &s) {
    return *this;
  }
  delete[] _str;
  _len = s._len;
  _str = new char[_len + 1];
  strcpy(_str, s._str);
  return *this;
}

String &String::operator=(const char *s) {
  delete[] _str;
  _len = strlen(s);
  _str = new char[_len + 1];
  strcpy(_str, s);
  return *this;
}

char &String::operator[](int i) { return _str[i]; }

const char &String::operator[](int i) const { return _str[i]; }

bool operator<(const String &s1, const String &s2) {
  return (strcmp(s1._str, s2._str) < 0);
}

bool operator>(const String &s1, const String &s2) {
  return (strcmp(s1._str, s2._str) > 0);
}

bool operator==(const String &s1, const String &s2) {
  return (strcmp(s1._str, s2._str) == 0);
}

std::ostream &operator<<(std::ostream &os, const String &s) {
  os << s._str;
  return os;
}

std::istream &operator>>(std::istream &is, String &s) {
  char temp[String::CINLIM];
  is.get(temp, String::CINLIM);
  if (is) {
    s = temp;
  }
  while (is && is.get() != '\n') {
    continue;
  }
  return is;
}

String String::operator+(const String &s) const {
  int tlen = _len + s._len;
  char *temp = new char[tlen + 1];
  strcpy(temp, _str);
  strcpy(temp + _len, s._str);
  temp[tlen] = '\0';
  return String(temp);
}

String String::operator+(const char *s) const {
  int tlen = _len + strlen(s);
  char *temp = new char[tlen + 1];
  strcpy(temp, _str);
  strcpy(temp + _len, s);
  temp[tlen] = '\0';
  return String(temp);
}

String operator+(const char *s1, const String &s2) { return String(s1) + s2; }