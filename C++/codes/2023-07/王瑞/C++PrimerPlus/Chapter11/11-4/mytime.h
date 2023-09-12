#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

class MyTime {
private:
  int _hours;
  int _minutes;

public:
  MyTime() : _hours(0), _minutes(0) {}
  MyTime(int h, int m = 0) : _hours(h), _minutes(m) {}
  void addMin(int m);
  void addHr(int h);
  void resetTime(int h = 0, int m = 0);
  friend MyTime operator+(const MyTime &t1, const MyTime &t2);
  friend MyTime operator-(const MyTime &t1, const MyTime &t2);
  friend MyTime operator*(const MyTime &t, double n);
  friend MyTime operator*(double m, const MyTime &t);
  friend std::ostream &operator<<(std::ostream &os, const MyTime &t);
};

#endif