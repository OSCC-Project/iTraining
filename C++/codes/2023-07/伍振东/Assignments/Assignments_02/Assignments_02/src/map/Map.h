#ifndef MAP_H_
#define MAP_H_
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<iostream>
#include "Point.h"

/* Map类
   包含整个地图的大小，和所有Point
*/
class Cmp {
public:
    bool operator()(const Point& a, const Point& b) {
        if (a._f == b._f) {
            return a._h < b._h;
        }
        return a._f > b._f;
    }
};

// 维护一个open的队列
class Map {
private:
    int _length;
    int _weight;
    Xy _first;
    Xy _final;
    std::vector<std::vector<Point>> _map;
    std::priority_queue<Point> _point_open;
    std::vector<Xy> _abs;
    std::vector<Xy> _path;
    bool _haveway = 1;
public:
    Map();
    Map(int m_length, int m_weight);

    void insertAbs(int x, int y)noexcept;
    void insertFirst(int x, int y);
    void insertFinal(int x, int y);
    void deleteAbs(int x, int y)noexcept;
    // 检测点是否在图区域内部
    bool isOnBoard(Xy xy);

    // 计算两点之间的斜线距离
    int twoPointDistance(Xy point1, Xy point2);
    // 计算代价g的增量距离
    int gAdd(Xy point1, Xy point2);

    // A-Star路径搜索
    void aStar();
    void getPath();
    // 清楚所有设置
    void reStart();

    friend std::ostream& operator<<(std::ostream& os, Map& m_map);
};

#endif // !MAP_H_