/**
 * @file Graph.h
 * @brief 这是Graph类的头文件
 * 1. Graph(int w = 4, int h = 8)：构造函数，初始化图的宽和高，默认值为4和8
 * 2. set_Weight()：设置权重，随机生成0-9之间的随机数
 * 3. get_Width()：获取图的宽
 * 4. get_length()：获取图的长
 * 
 */



#pragma once
#include "public_header.h"

class Astar; // 前向声明

class Graph {
public:
    /**
     * @brief 声明了Graph类的友元类Astar
     * 
     */
    friend class Astar;
    /**@brief 这个构造函数初始化图的宽和高
     * 
    */
    Graph(int w = 4, int h = 8);
    /**
     * @brief Set the Weight object
     * 
     */
    void set_Weight();
    /**
     * @brief Get the Width object
     * 
     * @return int 
     */
    int get_Width();
    /**
     * @brief Get the length object
     * 
     * @return int 
     */
    int get_length();
    /**
     * @brief Get the Weight object
     * 
     * @param x 输入的x的坐标
     * @param y 输入的y的坐标
     * @return int 得到的权重
     */
    int get_Weight(int x, int y);

    ~Graph();

private:
    int _width;
    int _length;
    std::vector<std::vector<int>> _Adj_Graph;
};