/**
 * @file RandomMap.cpp
 * @author liuqian
 * @brief create a random map
 * @version 0.1
 * @date 2024-7-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "GridMap.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void RandomMap(GridMap& map, Node& start, Node& goal) {
    std::srand(std::time(nullptr));

    int width = std::rand() % 20 + 5;
    int height = std::rand() % 20 + 5;

    map = GridMap(width, height);

    int numObstacles = (width * height) / 10;
    for (int i = 0; i < numObstacles; ++i) {
        int x = std::rand() % width;
        int y = std::rand() % height;
        map.setObstacle(x, y);
    }

    int maxWeight = 10;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (!map.isObstacle(x, y)) {
                int weight = std::rand() % maxWeight + 1;
                map.setWeight(x, y, weight);
            }
        }
    }

    start = Node(std::rand() % width, std::rand() % height);
    goal = Node(std::rand() % width, std::rand() % height);

    while (map.isObstacle(start.x, start.y)) {
        start = Node(std::rand() % width, std::rand() % height);
    }
    while (map.isObstacle(goal.x, goal.y)) {
        goal = Node(std::rand() % width, std::rand() % height);
    }

    std::cout << "Start point: (" << start.x<< ", "
        << start.y << ")" << std::endl;
    std::cout << "Goal point: (" << goal.x << ", "
        << goal.y << ")" << std::endl;

}

