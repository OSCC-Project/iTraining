/**
 * @file Node.h
 * @author liuqian
 * @brief
 * @version 0.1
 * @date 2024-7-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef NODE_H_
#define NODE_H_

#include <limits>

/**
 * @brief class Node
 * 
 * @param x 
 * @param y
 */
class Node {
public:
    int x, y;
    double g, h, f;
    Node* parent;

    Node(int x, int y) : x(x), y(y), g(std::numeric_limits<double>::infinity()),
                        h(0), f(0), parent(nullptr) {}

    bool operator==(const Node& other) const {
        return x == other.x && y == other.y;
    }
};

#endif  // NODE_H_
