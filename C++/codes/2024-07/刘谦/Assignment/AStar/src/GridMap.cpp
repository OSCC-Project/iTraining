/**
 * @file GridMap.cpp
 * @author liuqian
 * @brief
 * @version 0.1
 * @date 2024-7-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <vector>
#include "GridMap.h"


/**
 * @brief construct function
 * 
 * @param width 
 * @param height 
 */
GridMap::GridMap(int width, int height)
    : width(width), height(height), obstacles(width, std::vector<int>(height, 0)), weights(height, std::vector<int>(width, 0)) {}


/**
 * @brief determine if a node is an obstacle
 * 
 * @param x 
 * @param y 
 * 
 * @return true if the node is an obstacle
 * @return fasle if the node isn't an obstacle
 */
bool GridMap::isObstacle(int x, int y) const {
    return obstacles[x][y] == 1;
}


/**
 * @brief set an obstacle in the map
 * 
 * @param x the position of obstacle
 * @param y the position of obstacle
 */
void GridMap::setObstacle(int x, int y) {
    obstacles[x][y] = 1;
}


/**
 * @brief determine if the node is within bounds of map
 * 
 * @param x 
 * @param y 
 * 
 * @return true if the node is within bounds of map
 * @return fasle if the node isn't within bounds of map
 */
bool GridMap::isWithinBounds(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

int GridMap::getWidth() const {
    return width;
}

int GridMap::getHeight() const {
    return height;
}

void GridMap::setWeight(int x, int y, int weight) {
    if (isWithinBounds(x, y)) {
        weights[y][x] = weight;
    }
}

int GridMap::getWeight(int x, int y) const {
    if (isWithinBounds(x, y)) {
        return weights[y][x];
    }
    return -1; 
}
