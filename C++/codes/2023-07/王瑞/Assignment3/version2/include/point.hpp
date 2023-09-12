/**
 * @file Point.hpp
 * @author wangrui
 * @brief
 * @version 0.1
 * @date 2023-08-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include <cmath>
#include <iostream>
#include <vector>

/**
 *  @brief class Point
 *
 * @param _x,_y ///<Point (x,y)
 * @param _g    ///<the loss from the starting point to this point
 * @param _h    ///<the loss from this point to the ending point
 * @param _f    ///<the total loss
 * @param _pre_point ///<the parent of this point
 * @param _is_obstacle ///<mark whether this point is an obstacle
 * @param _is_inopenlist  ///<mark whether this point is in the open list
 * @param _is_incloselist ///<mark whether this point is in the close list
 */
namespace mypoint {
class Point {
public:
  explicit Point()
      : _x(0), _y(0), _g(0), _h(0), _f(0), _pre_point(nullptr), _is_obstacle(0),
        _is_inopenlist(false), _is_incloselist(false) {}
  explicit Point(int x, int y, const int obstacle)
      : _x(x), _y(y), _g(0), _h(0), _f(0), _pre_point(nullptr),
        _is_obstacle(obstacle), _is_inopenlist(false), _is_incloselist(false) {}
  ~Point() //= default;
  {
    if (_pre_point != nullptr) {
      _pre_point = nullptr;
    }
  }

  Point(const Point &point);
  Point &operator=(const Point &point);
  int get_X() const { return _x; }
  void set_X(const int x) { _x = x; }
  int get_Y() const { return _y; }
  void set_Y(const int y) { _y = y; }
  int get_G() const { return _g; }
  void set_G(const Point *prepoint);
  int get_H() const { return _h; }
  void set_H(Point *end);
  int get_F() const { return _f; }
  void set_F() { _f = _g + _h; }
  Point *get_pre() const { return _pre_point; }
  void set_Pre(Point *point) { _pre_point = point; }
  int get_Obstacle() const { return _is_obstacle; }
  void set_Obstacle(const int obstacle) { _is_obstacle = obstacle; }
  bool isInOpenlist() const { return _is_inopenlist; }
  void set_inopenlist() { _is_inopenlist = true; }
  void set_outopenlist() { _is_inopenlist = false; }
  bool isInCloselist() const { return _is_incloselist; }
  void set_incloslist() { _is_incloselist = true; }

private:
  int _x;
  int _y;
  int _g;
  int _h;
  int _f;
  Point *_pre_point = nullptr;
  int _is_obstacle;
  bool _is_inopenlist;
  bool _is_incloselist;
};
} // namespace mypoint
