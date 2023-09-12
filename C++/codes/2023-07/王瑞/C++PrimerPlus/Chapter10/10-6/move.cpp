#include "move.h"
#include <iostream>

Move::Move(double a, double b) {
  _x = a;
  _y = b;
}

void Move::showMove() const {
  std::cout << "x = " << _x << std::endl;
  std::cout << "_y = " << _y << std::endl;
}

Move &Move::addMove(const Move &m) const {
  static Move n;
  n._x = m._x + this->_x;
  n._y = m._y + this->_y;
  return n;
}

void Move::resetMove(double a, double b) {
  _x = a;
  _y = b;
}