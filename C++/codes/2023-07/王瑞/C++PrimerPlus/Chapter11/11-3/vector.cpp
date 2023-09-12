#include "vector.h"
#include <cmath>

using std::atan;
using std::atan2;
using std::cos;
using std::sin;
using std::sqrt;

namespace VECTOR {
const double Rad_to_deg = 45.0 / atan(1.0);

void Vector::setMag() { _mag = sqrt(_x * _x + _y * _y); }

void Vector::setAng() {
  if (_x == 0.0 && _y == 0.0) {
    _ang = 0.0;
  } else {
    _ang = atan2(_y, _x);
  }
}

void Vector::setX() { _x = _mag * cos(_ang); }

void Vector::setY() { _y = _mag * sin(_ang); }

Vector::Vector() {
  _x = _y = _mag = _ang = 0.0;
  mode = RECT;
}

Vector::Vector(double n1, double n2, Mode form) {
  mode = form;
  if (form == RECT) {
    _x = n1;
    _y = n2;
    setMag();
    setAng();
  } else if (form == POL) {
    _mag = n1;
    _ang = n2 / Rad_to_deg;
    setX();
    setY();
  } else {
    std::cout << "Incorrect 3rd argument to Vector() -- ";
    std::cout << "vector set to 0\n";
    _x = _y = _mag = _ang = 0.0;
    mode = RECT;
  }
}

void Vector::resetVector(double n1, double n2, Mode form) {
  mode = form;
  if (form == RECT) {
    _x = n1;
    _y = n2;
    setMag();
    setAng();
  } else if (form == POL) {
    _mag = n1;
    _ang = n2 / Rad_to_deg;
    setX();
    setY();
  } else {
    std::cout << "Incorrect 3rd argument to Vector() -- ";
    std::cout << "vector set to 0\n";
    _x = _y = _mag = _ang = 0.0;
    mode = RECT;
  }
}

Vector::~Vector() {}

void Vector::setPolarMode() { mode = POL; }

void Vector::rectMode() { mode = RECT; }

Vector Vector::operator+(const Vector &b) const {
  return Vector(_x + b._x, _y + b._y);
}

Vector Vector::operator-(const Vector &b) const {
  return Vector(_x - b._x, _y - b._y);
}

Vector Vector::operator-() const { return Vector(-_x, -_y); }

Vector Vector::operator*(double n) const { return Vector(n * _x, n * _y); }

Vector operator*(double n, const Vector &a) { return a * n; }

std::ostream &operator<<(std::ostream &os, const Vector &v) {
  if (v.mode == Vector::RECT) {
    os << "(_x,_y) = (" << v._x << ", " << v._y << ")";
  } else if (v.mode == Vector::POL) {
    os << "(m,a) = (" << v._mag << ", ";
    os << v._ang * Rad_to_deg << ")";
  } else {
    os << "Vector object mode is invalid";
  }
  return os;
}
} // namespace VECTOR
