#ifndef MYMAP_HPP
#define MYMAP_HPP

#include"../MyPoint/MyPoint.hpp"
#include<vector>
#include<math.h>

class MyMap
{
    
public:
    MyMap(int length,int width);
    ~MyMap();
    /// @brief 存储地图的数据结构
    std::vector<std::vector<MyPoint *>>_map_points;
    
    /// @brief 起点与邻点的直线距离
    /// @param p1 当前起点
    /// @param p2 邻点
    /// @return 返回直线距离
    double calculate_linear_distance(MyPoint p1,MyPoint p2);
    /// @brief 邻点与终点的曼哈顿距离，这两个函数冗余了，不需要这么细
    /// @param p1 邻点
    /// @param p2 终点
    double calculate_manhattan_distance(MyPoint p1,MyPoint p2);
    void set_map_length(int length);
    void set_map_width(int width);

    /// @brief 实例化地图节点
    void initial_map();
    void draw_map();
    
private:

    int _map_length;
    int _map_width;
    /// @brief 地图上的节点数
    int _map_points_number;
    
};



#endif