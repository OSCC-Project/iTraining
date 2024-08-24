/**
 * @file GridMap.h
 * @brief 
 * @author liuqian
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef GRIDMAP_H_
#define GRIDMAP_H_

#include <vector>
#include "Node.h"

/**
 * @brief class obstaclesmap
 * 
 * @param width the width of obstacles map
 * @param height the height of obstacles map
 */
class GridMap {
public:
    GridMap(int width, int height);
    bool isObstacle(int x, int y) const;
    void setObstacle(int x, int y);
    bool isWithinBounds(int x, int y) const;

    void display(const std::vector<Node>& path) const;
    int width;
    int height;
    int getWidth() const;
    int getHeight() const;
    void setWeight(int x, int y , int weight);
    int getWeight(int x, int y ) const;
    std::vector<std::vector<int>> obstacles;
    std::vector<std::vector<int>> weights;

};

#endif  // GRIDMAP_H_
