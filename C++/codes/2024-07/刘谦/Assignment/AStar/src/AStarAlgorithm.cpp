/**
 * @file AStarAlgorithm.cpp
 * @author liuqian
 * @brief
 * @version 0.1
 * @date 2024-7-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "AStarAlgorithm.h"
#include <cmath>
#include <vector>
#include <algorithm>

/**
 * @brief the heuristic between two nodes on a grid map
 * 
 * @param a node
 * @param b node
 * 
 * @return the heuristic between two nodes
 */
int AStarAlgorithm::heuristic(const Node& a, const Node& b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

/**
 * @brief get the neighbor nodes of current node
 * 
 * @param map the grid map with obstacles
 * 
 * @param node current node
 * 
 * @return the neighbor nodes
 */
std::vector<Node> AStarAlgorithm::getNeighbors(const GridMap& map,
                                        const Node& node) {
    std::vector<Node> neighbors;
    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };

    for (const auto& direction : directions) {
        int newX = node.x + direction.first;
        int newY = node.y + direction.second;

        if (map.isWithinBounds(newX, newY) && !map.isObstacle(newX, newY)) {
            neighbors.emplace_back(newX, newY);
        }
    }
    return neighbors;
}

/**
 * @brief reconstruct the optimal path 
 * 
 * @param current the goal node
 * 
 * @return the optimal path 
 */
std::vector<Node> AStarAlgorithm::reconstructPath(Node* current) {
    std::vector<Node> path;
    while (current != nullptr) {
        path.push_back(*current);
        current = current->parent;

    }
    std::reverse(path.begin(), path.end());
    return path;
}

/**
 * @brief find the node in the list
 * 
 * @param list the list of nodes 
 * 
 * @param node the node being searched for
 * 
 * @return the node if the node is in the list
 * @return nullptr if the node isn't in the list
 */
Node* AStarAlgorithm::findNodeInList(std::vector<Node*>& list,
                                const Node& node) {
    for (auto& n : list) {
        if (*n == node) {
            return n;
        }
    }
    return nullptr;
}


/**
 * @brief find the optimal path
 * 
 * @param map the grid map with obstacles
 * 
 * @param start the starting node of the path
 * @param goal the goal node of the path
 * 
 * @return the path
 * 
 */
std::vector<Node> AStarAlgorithm::findPath(const GridMap& map,
                                    const Node& start, const Node& goal) {
    std::vector<Node*> openSet;
    std::vector<Node*> closedSet;

    Node* startNode = new Node(start.x, start.y);
    startNode->g = map.getWeight(start.x, start.y);
    startNode->h = heuristic(start, goal);
    startNode->f = startNode->g + startNode->h;
    openSet.push_back(startNode);

    while (!openSet.empty()) {
        auto currentIt = std::min_element(openSet.begin(), openSet.end(),
                                         [](Node* a, Node* b) {
            return a->f < b->f;
        });
        Node* current = *currentIt;

        if (*current == goal) {
            return reconstructPath(current);
            for (Node* node : openSet) delete node;
            for (Node* node : closedSet) delete node;
        }

        openSet.erase(currentIt);
        closedSet.push_back(current);

        for (auto& neighbor : getNeighbors(map, *current)) {
            if (findNodeInList(closedSet, neighbor)) continue;

            double tentative_gScore = current->g + map.getWeight(neighbor.x,
                                                        neighbor.y);

            Node* neighborNode = findNodeInList(openSet, neighbor);
            if (!neighborNode) {
                neighborNode = new Node(neighbor.x, neighbor.y);
                neighborNode->parent = current;
                openSet.push_back(neighborNode);
            }

            if (tentative_gScore < neighborNode->g) {
                neighborNode->g = tentative_gScore;
                neighborNode->h = heuristic(*neighborNode, goal);
                neighborNode->f = neighborNode->g + neighborNode->h;
                neighborNode->parent = current;
            }
        }
    }
    for (Node* node : openSet) delete node;
    for (Node* node : closedSet) delete node;
    return std::vector<Node>();
}
