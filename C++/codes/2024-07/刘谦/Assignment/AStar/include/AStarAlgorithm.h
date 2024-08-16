/**
 * @file AStarAlgorithm.h
 * @author liuqian
 * @brief
 * @version 0.1
 * @date 2024-7-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ASTARALGORITHM_H_
#define ASTARALGORITHM_H_

#include "Node.h"
#include "GridMap.h"
#include <vector>
#include <queue>

/**
 * @brief class AStarAlgorithm
 * 
 */
class AStarAlgorithm {
public:
    std::vector<Node> findPath(const GridMap& map, const Node& start, const Node& goal);

private:
    int heuristic(const Node& a, const Node& b);
    std::vector<Node> getNeighbors(const GridMap& map, const Node& node);
    std::vector<Node> reconstructPath(Node* current);
    Node* findNodeInList(std::vector<Node*>& list, const Node& node);
};

#endif // ASTARALGORITHM_H_
