#ifndef MAP_H_
#define MAP_H_
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<iostream>
#include <QApplication>
#include <qpainter.h>
#include <qpen.h>
#include <qwidget.h>
#include<QMouseEvent>
#include "Point.h"

/* Map类
   包含整个地图的大小，和所有Point
*/

// 维护一个open的队列
class Map : public QWidget{
private:
    int _length;
    int _weight;
    Xy _first;
    Xy _final;
    std::vector<std::vector<Point>> _map;
    std::priority_queue<Point> _point_open;
    std::vector<Xy> _path;
    bool _haveway = 1;
public:
    Map();
    Map(int m_length, int m_weight);

    void insertAbs(int x, int y);
    void insertFirst(int x, int y);
    void insertFinal(int x, int y);
    void deleteAbs(int x, int y);
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

// 前端界面
protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event);

public:
    // 基坐标
    int start_x = 10;
    int start_y = 10;

    // 网格大小
    int gsize = 50;

    bool start_button = 0;
    bool final_button = 0;
    bool abs_button = 0;
    bool a_star_button = 0;
    bool clear_button = 1;
    bool restart_button = 0;
    int last_x = 0;
    int last_y = 0;
};

#endif // !MAP_H_