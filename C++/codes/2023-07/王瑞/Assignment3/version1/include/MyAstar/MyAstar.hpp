/**
 * @file MyAStar.hpp
 * @author wangrui
 * @brief
 * @version 0.1
 * @date 2023-07-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef MYAStar_H_
#define MYAStar_H_

#include <cmath>
#include <iostream>
#include <list>
#include <random>
#include <vector>

static const int str_cost = 10;  ///< Straight run loss
static const int dia_cost = 14;  ///< Diagonal travel loss

/**
 *  @brief class Point
 *
 * @param _x,_y ///<Point (x,y)
 * @param _g    ///<the loss from the starting point to this point
 * @param _h    ///<the loss from this point to the ending point
 * @param _f    ///<the total loss
 * @param _pre_point ///<the parent of this point
 * @param _is_obstacle ///<mark whether this point is an obstacle
 * @param _is_in_openlist  ///<mark whether this point is in the open list
 * @param _is_in_closelist ///<mark whether this point is in the close list
 */
namespace Assignment2
{
  class Point
  {
   public:
    explicit Point()
        : _x(0),
          _y(0),
          _g(0),
          _h(0),
          _f(0),
          _pre_point(nullptr),
          _is_obstacle(0),
          _is_in_openlist(false),
          _is_in_closelist(false)
    {
    }
    explicit Point(int x, int y, const int obstacle)
        : _x(x),
          _y(y),
          _g(0),
          _h(0),
          _f(0),
          _pre_point(nullptr),
          _is_obstacle(obstacle),
          _is_in_openlist(false),
          _is_in_closelist(false)
    {
    }
    ~Point()  //= default;
    {
      if (_pre_point != nullptr)
      {
        _pre_point = nullptr;
      }
    }

    inline Point(const Point &point);

    inline Point &operator=(const Point &point);

    inline int get_X() const
    {
      return _x;
    }
    inline void set_X(const int x)
    {
      _x = x;
    }
    inline int get_Y() const
    {
      return _y;
    }
    inline void set_Y(const int y)
    {
      _y = y;
    }
    inline int get_G() const
    {
      return _g;
    }
    inline void set_G(const Point *prepoint);
    int get_H() const
    {
      return _h;
    }
    inline void set_H(Point *end);
    inline int get_F() const
    {
      return _f;
    }
    inline void set_F()
    {
      _f = _g + _h;
    }
    inline Point *get_pre_point() const
    {
      return _pre_point;
    }
    inline void set_pre_point(Point *point)
    {
      _pre_point = point;
    }
    inline int get_is_obstacle() const
    {
      return _is_obstacle;
    }
    inline void set_Obstacle(const int obstacle)
    {
      _is_obstacle = obstacle;
    }
    inline bool isInOpenlist() const
    {
      return _is_in_openlist;
    }
    inline void set_in_openlist(bool flag)
    {
      _is_in_openlist = flag;
    }
    inline void set_outopenlist()
    {
      _is_in_openlist = false;
    }
    inline bool isInCloselist() const
    {
      return _is_in_closelist;
    }
    inline void set_incloslist()
    {
      _is_in_closelist = true;
    }

   private:
    int _x;
    int _y;
    int _g;
    int _h;
    int _f;
    Point *_pre_point = nullptr;
    int _is_obstacle;
    bool _is_in_openlist;
    bool _is_in_closelist;
  };

  /**
   * @brief class AStar
   *
   * @param _map ///<storage the map
   * @param _open_list
   * @param _close_list
   */
  class AStar
  {
   public:
    explicit AStar() : _map({}), _open_list({}), _close_list({})
    {
    }
    explicit AStar(const std::vector<std::vector<int>> themap);
    ~AStar()  //= default;
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
    Point *findMinFPoint();
    void set_ObtPointtoOpenlist(Point *point, Point *end);
    bool startAStar(Point *start, Point *end);
    std::vector<Point *> set_Path(bool flag, Point *end);
    void show_Path(bool flag, std::vector<Point *> path);
    void get_cost(Point *end)
    {
      std::cout << "The path's cost is:" << end->get_G() << std::endl;
    }
    std::vector<Point> &operator[](const int ind)
    {
      return _map[ind];
    }

   private:
    std::vector<std::vector<Point>> _map;
    std::list<Point *> _open_list;
    std::list<Point *> _close_list;
  };

  class TestMap
  {
   public:
    TestMap() = default;
    ~TestMap()
    {
      _testmap.clear();
      _testmap.shrink_to_fit();
    }
    void set_TestMap(const int rows, const int cols, const double obstacleRatio);
    std::vector<std::vector<int>> get_TestMap()
    {
      return _testmap;
    }

   private:
    std::vector<std::vector<int>> _testmap;
  };

}  // namespace Assignment2
#endif