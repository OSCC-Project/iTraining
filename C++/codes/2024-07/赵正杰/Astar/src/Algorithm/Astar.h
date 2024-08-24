/**
 * @file Astar.h
 * @brief 这个文件是A*算法的实现文件，主要实现了A*算法的搜索路径和得到路径的算法
*/

#pragma once
#include "public_header.h"
#include "Graph.h"
#include "Visual.h"

class Astar {
    using Point = std::pair<int, int>;
    using Priority_Point = std::pair<int, Point>;
    using PriorityQueue = std::priority_queue<Priority_Point, std::vector<Priority_Point>, std::greater<Priority_Point>>;

public:
/**@param start 起点坐标
 * @param end 终点坐标
 * @param graph 图结构
 * @brief 这个函数是搜索路径的主函数，主要实现了A*算法的搜索路径算法
*/
    void search_Path(const Point start, const Point end,Graph& graph);

/**@parma end 终点坐标
 * @param start 起点坐标
 * @param graph 图结构
 * @param vis 可视化类
 * @brief 这个函数是得到路径的主函数，主要实现了A*算法的得到路径算法
*/
    void get_Path(const Point& end, const Point& start, Graph& graph, Visualization* vis = nullptr);

/**@param current 当前节点 
 * @param graph 图结构
 * @return 邻居节点的集合
*/
    std::vector<Point> Find_neighbors(const Point current,Graph& graph);
private:
    std::vector<std::pair<Point, Point>> come_from;

    
    int heuristic(Point a, Point b);
};
