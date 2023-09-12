#include "point.hpp"
#include "astar.hpp"
namespace mypoint {
Point::Point(const Point &point) {
  _x = point._x;
  _y = point._y;
  _g = point._g;
  _h = point._h;
  _f = point._f;
  _pre_point = point._pre_point;
  _is_obstacle = point._is_obstacle;
  _is_inopenlist = point._is_inopenlist;
  _is_incloselist = point._is_incloselist;
}

Point &Point::operator=(const Point &point) {
  if (this == &point) {
    return *this;
  }
  _x = point._x;
  _y = point._y;
  _g = point._g;
  _h = point._h;
  _f = point._f;
  _pre_point = point._pre_point;
  _is_obstacle = point._is_obstacle;
  _is_inopenlist = point._is_inopenlist;
  _is_incloselist = point._is_incloselist;
  return *this;
}
/**
 * @brief Set Point G
 *
 * @param pre point
 */
void Point::set_G(const Point *prepoint) {
  if (prepoint->get_X() == this->get_X() ||
      prepoint->get_Y() == this->get_Y()) {
    this->_g = prepoint->get_G() + str_cost;
  } else {
    this->_g = prepoint->get_G() + dia_cost;
  }
}

/**
 * @brief Set Point H
 *
 * @param end point
 */
void Point::set_H(Point *end) {
  if (_x == end->get_X() || _y == end->get_Y()) {
    _h = str_cost * abs(end->get_X() - _x + end->get_Y() - _y);
  } else {
    _h = int(dia_cost *
             sqrt(pow(end->get_X() - _x, 2) + pow(end->get_Y() - _y, 2)));
  }
}
} // namespace mypoint