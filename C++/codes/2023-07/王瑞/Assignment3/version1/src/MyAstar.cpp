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

#include "MyAstar/MyAstar.hpp"

#include <iostream>
#include <list>
#include <string>
#include <vector>

namespace Assignment2
{
  Point::Point(const Point &point)
  {
    _x = point._x;
    _y = point._y;
    _g = point._g;
    _h = point._h;
    _f = point._f;
    _pre_point = point._pre_point;
    _is_obstacle = point._is_obstacle;
    _is_in_openlist = point._is_in_openlist;
    _is_in_closelist = point._is_in_closelist;
  }

  Point &Point::operator=(const Point &point)
  {
    if (this == &point)
    {
      return *this;
    }
    _x = point._x;
    _y = point._y;
    _g = point._g;
    _h = point._h;
    _f = point._f;
    _pre_point = point._pre_point;
    _is_obstacle = point._is_obstacle;
    _is_in_openlist = point._is_in_openlist;
    _is_in_closelist = point._is_in_closelist;
    return *this;
  }
  /**
   * @brief Set Point G
   *
   * @param pre point
   */
  void Point::set_G(const Point *prepoint)
  {
    if (prepoint->get_X() == this->get_X() || prepoint->get_Y() == this->get_Y())
    {
      this->_g = prepoint->get_G() + str_cost;
    }
    else
    {
      this->_g = prepoint->get_G() + dia_cost;
    }
  }

  /**
   * @brief Set Point H
   *
   * @param end point
   */
  void Point::set_H(Point *end)
  {
    if (_x == end->get_X() || _y == end->get_Y())
    {
      _h = str_cost * abs(end->get_X() - _x + end->get_Y() - _y);
    }
    else
    {
      _h = int(dia_cost * sqrt(pow(end->get_X() - _x, 2) + pow(end->get_Y() - _y, 2)));
    }
  }

  /**
   * @brief class AStar's constructing function
   *
   * @param the map
   */
  AStar::AStar(std::vector<std::vector<int>> themap)
  {
    _map.resize(themap.size(), std::vector<Point>(themap[0].size()));
    for (int i = 0; i < themap.size(); ++i)
    {
      for (int j = 0; j < themap[0].size(); ++j)
      {
        _map[i][j] = Point(i, j, themap[i][j]);
      }
    }
  }

  /**
   * @brief Show map
   */
  void AStar::showMap()
  {
    for (int i = 0; i < _map.size(); ++i)
    {
      for (int j = 0; j < _map[0].size(); ++j)
      {
        if (_map[i][j].get_is_obstacle() == 1)
        {
          std::cout << " x ";
        }
        else if (_map[i][j].get_is_obstacle() == 2)
        {
          std::cout << " - ";
        }
        else
        {
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
  Point *AStar::findMinFPoint()
  {
    if (!_open_list.empty())
    {
      auto minfpoint = _open_list.front();
      for (auto point : _open_list)
      {
        if (minfpoint->get_F() > point->get_F())
        {
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
  void AStar::set_ObtPointtoOpenlist(Point *point, Point *end)
  {
    const int row = _map.size();
    const int col = _map[0].size();
    for (int i = -1; i <= 1; ++i)
    {
      for (int j = -1; j <= 1; ++j)
      {
        int x = point->get_X() + i;
        int y = point->get_Y() + j;
        if (x > row - 1 || x < 0 || y > col - 1 || y < 0 || (x == 0 && y == 0))
        {
          continue;
        }
        if (_map[x][y].get_is_obstacle() == 1)
        {
          continue;
        }
        if (_map[x][y].isInCloselist())
        {
          continue;
        }
        _map[x][y].set_G(point);
        _map[x][y].set_H(end);
        _map[x][y].set_F();
        _map[x][y].set_pre_point(point);
        _open_list.push_back(&_map[x][y]);
        _map[x][y].set_in_openlist(true);
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
  bool AStar::startAStar(Point *start, Point *end)
  {
    _open_list.push_back(start);
    start->set_in_openlist(true);
    while (!_open_list.empty())
    {
      auto bestpoint = findMinFPoint();
      _open_list.remove(bestpoint);
      bestpoint->set_outopenlist();
      _close_list.push_back(bestpoint);
      bestpoint->set_incloslist();
      if (bestpoint->get_X() == end->get_X() && bestpoint->get_Y() == end->get_Y())
      {
        return true;
      }
      else
      {
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
  std::vector<Point *> AStar::set_Path(bool flag, Point *end)
  {
    std::vector<Point *> path;
    if (flag)
    {
      auto end_ptr = end;
      path.push_back(end_ptr);
      end->set_Obstacle(2);
      while (end_ptr->get_pre_point() != nullptr)
      {
        path.push_back(end_ptr->get_pre_point());
        end_ptr = end_ptr->get_pre_point();
        _map[end_ptr->get_X()][end_ptr->get_Y()].set_Obstacle(2);
      }
    }
    return path;
  }

  void AStar::show_Path(bool flag, std::vector<Point *> path)
  {
    if (flag)
    {
      std::cout << "The path is as follows:" << std::endl;
      for (int i = path.size() - 1; i >= 0; --i)
      {
        std::cout << "(" << path[i]->get_X() << "," << path[i]->get_Y() << ") ";
      }
      std::cout << std::endl;
    }
    else
    {
      std::cout << "Sorry, there is no path." << std::endl;
    }
  }

  void TestMap::set_TestMap(const int rows, const int cols, const double obstacleRatio)
  {
    _testmap.resize(rows, std::vector<int>(cols));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        double randomNum = dis(gen);
        int value = (randomNum < obstacleRatio) ? 1 : 0;
        _testmap[i][j] = value;
      }
    }
    _testmap[rows - 1][cols - 1] = 0;
    _testmap[0][0] = 0;
  }
}  // namespace Assignment2