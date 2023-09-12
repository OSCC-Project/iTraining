/**
 * @file AStar.hpp
 * @author wangrui
 * @brief
 * @version 0.1
 * @date 2023-08-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include "point.hpp"
#include <iostream>
#include <list>
#include <vector>

static const int str_cost = 10; ///< Straight run loss
static const int dia_cost = 14; ///< Diagonal travel loss

namespace myastar {
/**
 * @brief class AStar
 *
 * @param _map ///<storage the map
 * @param _open_list
 * @param _close_list
 */
class AStar {
public:
  explicit AStar() : _map({}), _open_list({}), _close_list({}) {}
  explicit AStar(const std::vector<std::vector<int>> themap);
  ~AStar() //= default;
  {
    _map.clear();
    _map.shrink_to_fit();
    /* int openListSize = _open_list.size();
     if (openListSize > 0)
     {
       for (auto point : _open_list)
       {
         delete point;
         point = nullptr;
       }
     }
     int closeListSize = _close_list.size();
     if (closeListSize > 0)
     {
       for (auto point : _close_list)
       {
         delete point;
         point = nullptr;
       }
     }*/
  }
  void showMap();
  mypoint::Point *findMinFPoint();
  void set_ObtPointtoOpenlist(mypoint::Point *point, mypoint::Point *end);
  bool startAStar(mypoint::Point *start, mypoint::Point *end);
  std::vector<mypoint::Point *> set_Path(bool flag, mypoint::Point *end);
  void show_Path(bool flag, std::vector<mypoint::Point *> path);
  void get_cost(mypoint::Point *end) {
    std::cout << "The path's cost is:" << end->get_G() << std::endl;
  }
  std::vector<mypoint::Point> &operator[](const int ind) { return _map[ind]; }

private:
  std::vector<std::vector<mypoint::Point>> _map;
  std::list<mypoint::Point *> _open_list;
  std::list<mypoint::Point *> _close_list;
};
} // namespace myastar