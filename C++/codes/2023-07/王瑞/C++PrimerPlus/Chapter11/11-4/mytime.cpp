#include "mytime.h"
#include <iostream>

void MyTime::addMin(int m) {
  _minutes += m;
  if (_minutes / 60 > 0) {
    _minutes = _minutes + _hours * 60;
    _hours = _minutes / 60;
    _minutes = _minutes % 60;
  }
}

void MyTime::addHr(int h) { _hours += h; }

void MyTime::resetTime(int h, int m) {
  _hours = h;
  _minutes = m;
}

MyTime operator+(const MyTime &t1, const MyTime &t2) {
  MyTime sum;
  sum._minutes = t1._minutes + t2._minutes;
  sum._hours = t1._hours + t2._hours + sum._minutes / 60;
  sum._minutes = sum._minutes % 60;
  return sum;
}

MyTime operator-(const MyTime &t1, const MyTime &t2) {
  MyTime diff;
  int tot1, tot2;
  tot1 = t1._hours * 60 + t1._minutes;
  tot2 = t2._hours * 60 + t2._minutes;
  diff._hours = (tot1 - tot2) / 60;
  diff._minutes = (tot1 - tot2) % 60;
  return diff;
}

MyTime operator*(double m, const MyTime &t) {
  MyTime result;
  long totalminutes = t._hours * m * 60 + t._minutes * m;
  result._minutes = totalminutes % 60;
  result._hours = totalminutes / 60;
  return result;
}

MyTime operator*(const MyTime &t, double n) {
  MyTime result;
  long totalminutes = t._hours * n * 60 + t._minutes * n;
  result._minutes = totalminutes % 60;
  result._hours = totalminutes / 60;
  return result;
}

std::ostream &operator<<(std::ostream &os, const MyTime &t) {
  os << t._hours << " hour " << t._minutes << "minutes.";
  return os;
}