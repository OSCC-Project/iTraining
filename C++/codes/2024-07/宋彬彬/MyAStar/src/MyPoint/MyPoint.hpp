#ifndef MYPOINT_HPP
#define MYPOINT_HPP

#include<iostream>


/// @brief 点类，用于记录地图上的点及其父节点、存储f值以及一些地图的点属性
class MyPoint
{
public:
    MyPoint(int x,int y,int id);
    ~MyPoint();

    int get_coordinate_X() const;
    int get_coordinate_Y() const;
    void set_obstruction_station(bool obs_station);
    void set_visit_station(bool visit_station);
    int get_id();

    void set_end_point();
    bool is_end_point();
    void set_start_point();
    bool is_start_point();
    bool get_obstruction_station();

    /// @brief 用于保存路径，因为用的是广度优先，所以知道终点和起点就能回溯整条路径
    /// @param p 点节点
    void set_father_point(MyPoint *p);
    MyPoint *get_father_point();

    /// @brief 设置保存f值，每个点的f值只算一遍
    void set_f_value(double v);
    double get_f_value();

private:
    int _coordinate_X;
    int _coordinate_Y;
    bool _is_obstruction;
    bool _has_visit;
    int _id;
    bool _end_point;
    bool _start_point;
    MyPoint * _father_point;
    double _f_value;

};

#endif