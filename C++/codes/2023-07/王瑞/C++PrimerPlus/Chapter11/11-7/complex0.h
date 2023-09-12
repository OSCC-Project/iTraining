#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class Complex {
public:
  Complex();
  Complex(const double a, const double b);
  ~Complex();
  friend Complex operator+(const Complex &a, const Complex &b);
  friend Complex operator-(const Complex &a, const Complex &b);
  friend Complex operator*(const Complex &a, const Complex &b);
  friend Complex operator*(double x, const Complex &a);
  friend Complex operator~(const Complex &a);
  friend std::ostream &operator<<(std::ostream &os, const Complex &c);
  friend std::istream &operator>>(std::istream &is, Complex &c);

private:
  double _real;
  double _ima;
};

#endif