/**
 * @file MyAStar.cpp
 * @author wangrui
 * @brief
 * @version 0.1
 * @date 2023-07-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "astar.hpp"
#include "point.hpp"

#include <iostream>
#include <list>
#include <string>
#include <vector>
namespace myastar {

/**
 * @brief class AStar's constructing function
 *
 * @param the map
 */
AStar::AStar(std::vector<std::vector<int>> themap) {
  _map.resize(themap.size(), std::vector<mypoint::Point>(themap[0].size()));
  for (int i = 0; i < themap.size(); ++i) {
    for (int j = 0; j < themap[0].size(); ++j) {
      _map[i][j] = mypoint::Point(i, j, themap[i][j]);
    }
  }
}

/**
 * @brief Show map
 */
void AStar::showMap() {
  for (int i = 0; i < _map.size(); ++i) {
    for (int j = 0; j < _map[0].size(); ++j) {
      if (_map[i][j].get_Obstacle() == 1) {
        std::cout << " x ";
      } else if (_map[i][j].get_Obstacle() == 2) {
        std::cout << " - ";
      } else {
        std::cout << " o ";
      }
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Retrive the minimum F of the point in the open list
 *
 * @return the point
 */
mypoint::Point *AStar::findMinFPoint() {
  if (!_open_list.empty()) {
    auto minfpoint = _open_list.front();
    for (auto point : _open_list) {
      if (minfpoint->get_F() > point->get_F()) {
        minfpoint = point;
      }
    }
    return minfpoint;
  }
  return nullptr;
}

/**
 * @brief Add the surrounding obtainable point to the open list
 *
 * @param point
 * @param the end point
 */
void AStar::set_ObtPointtoOpenlist(mypoint::Point *point, mypoint::Point *end) {
  const int row = _map.size();
  const int col = _map[0].size();
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      int x = point->get_X() + i;
      int y = point->get_Y() + j;
      if (x > row - 1 || x < 0 || y > col - 1 || y < 0 || (x == 0 && y == 0)) {
        continue;
      }
      if (_map[x][y].get_Obstacle() == 1) {
        continue;
      }
      if (_map[x][y].isInCloselist()) {
        continue;
      }
      _map[x][y].set_G(point);
      _map[x][y].set_H(end);
      _map[x][y].set_F();
      _map[x][y].set_Pre(point);
      _open_list.push_back(&_map[x][y]);
      _map[x][y].set_inopenlist();
    }
  }
}

/**
 * @brief Start the AStar algorithm
 *
 * @param the start point
 * @param the end point
 *
 * @return true if the map has the successful path
 * @return false if the map doesn't have the successful path
 */
bool AStar::startAStar(mypoint::Point *start, mypoint::Point *end) {
  _open_list.push_back(start);
  start->set_inopenlist();
  while (!_open_list.empty()) {
    auto bestpoint = findMinFPoint();
    _open_list.remove(bestpoint);
    bestpoint->set_outopenlist();
    _close_list.push_back(bestpoint);
    bestpoint->set_incloslist();
    if (bestpoint->get_X() == end->get_X() &&
        bestpoint->get_Y() == end->get_Y()) {
      return true;
    } else {
      set_ObtPointtoOpenlist(bestpoint, end);
    }
  }
  return false;
}

/**
 * @brief Show the path resulting from the Astar algorithm
 *
 * @param the flag to mark whether a path is derived
 * @param the end point
 */
std::vector<mypoint::Point *> AStar::set_Path(bool flag, mypoint::Point *end) {
  std::vector<mypoint::Point *> path;
  if (flag) {
    auto end_ptr = end;
    path.push_back(end_ptr);
    end->set_Obstacle(2);
    while (end_ptr->get_pre() != nullptr) {
      path.push_back(end_ptr->get_pre());
      end_ptr = end_ptr->get_pre();
      _map[end_ptr->get_X()][end_ptr->get_Y()].set_Obstacle(2);
    }
  }
  return path;
}

void AStar::show_Path(bool flag, std::vector<mypoint::Point *> path) {
  if (flag) {
    std::cout << "The path is as follows:" << std::endl;
    for (int i = path.size() - 1; i >= 0; --i) {
      std::cout << "(" << path[i]->get_X() << "," << path[i]->get_Y() << ") ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "Sorry, there is no path." << std::endl;
  }
}

} // namespace myastar