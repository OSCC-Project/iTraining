#include "complex0.h"
#include <iostream>

Complex::Complex() {
  _real = 0.0;
  _ima = 0.0;
}

Complex::Complex(const double a, const double b) {
  _real = a;
  _ima = b;
}

Complex::~Complex() {}

Complex operator+(const Complex &a, const Complex &b) {
  Complex x(a._real + b._real, a._ima + b._ima);
  return x;
}

Complex operator-(const Complex &a, const Complex &b) {
  Complex x(a._real - b._real, a._ima - b._ima);
  return x;
}

Complex operator*(const Complex &a, const Complex &b) {
  Complex mult(a._real * b._real - a._ima * b._ima,
               a._real * b._ima + a._ima * b._real);
  return mult;
}

Complex operator*(double x, const Complex &a) {
  return Complex(a._real * x, a._ima * x);
}
Complex operator~(const Complex &a) { return Complex(a._real, -a._ima); }

std::ostream &operator<<(std::ostream &os, const Complex &c) {
  os << "( " << c._real << " , " << c._ima << " )" << std::endl;
  return os;
}

std::istream &operator>>(std::istream &is, Complex &c) {
  std::cout << "_real: ";
  is >> c._real;
  if (!is) {
    return is;
  }
  std::cout << "_ima: ";
  is >> c._ima;
  return is;
}