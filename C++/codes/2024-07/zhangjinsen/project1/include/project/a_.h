
#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include <utility>
#include "gra.h"

class PathFindingAlgorithm {
public:
    virtual ~PathFindingAlgorithm() {}

    virtual std::vector<std::pair<int, int>> findPath(
        const Grid_& grid,
        std::pair<int, int> start,
        std::pair<int, int> goal) = 0;
};

#include <queue>
#include <cmath>
#include <unordered_map>
#include <memory>

class AStarAlgorithm : public PathFindingAlgorithm {
public:
    std::vector<std::pair<int, int>> findPath(
        const Grid_& grid,
        std::pair<int, int> start,
        std::pair<int, int> goal) override {

        std::vector<std::pair<int, int>> path;
        std::priority_queue<Node, std::vector<Node>, NodeComparator> openSet;
        std::unordered_map<int, Node> mp;
        std::unordered_map<int, bool> fl;

        Node startNode(start, nullptr, 0, h_(start, goal));
        openSet.push(startNode);
        mp[hash(start)] = startNode;

        while (!openSet.empty()) {
            Node current = openSet.top();
            openSet.pop();
            mp.erase(hash(current.position));

            if (current.position == goal) {
                while (current.parent != nullptr) {
                    path.push_back(current.position);
                    current = *current.parent;
                }
                path.push_back(start);
                std::reverse(path.begin(), path.end());
                return path;
            }

            fl[hash(current.position)] = true;

            for (const auto& direction : directions) {
                std::pair<int, int> tmp = {current.position.first + direction.first,
                                           current.position.second + direction.second};
                int flag=0;
                if (isValid(tmp, grid) && fl.find(hash(tmp)) == fl.end()) {
                    if(direction.first == 1 && direction.second == 1){
                        if(grid.getValue(current.position.first+1, current.position.second) == 1)
                            flag=1;
                        if(grid.getValue(current.position.first, current.position.second+1) == 1)
                            flag=1;
                    }
                    if(direction.first==1 && direction.second == -1){
                        if(grid.getValue(current.position.first+1, current.position.second) == 1)
                            flag=1;
                        if(grid.getValue(current.position.first, current.position.second-1) == 1)
                            flag=1;
                    }
                    if(direction.first==-1 && direction.second == -1){ 
                        if(grid.getValue(current.position.first, current.position.second-1) == 1)
                            flag=1;
                        if(grid.getValue(current.position.first+1, current.position.second) == 1)
                            flag=1;
                    }
                    if(direction.first==-1 && direction.second == 1){
                        if(grid.getValue(current.position.first-1, current.position.second) == 1)
                            flag=1;
                        if(grid.getValue(current.position.first, current.position.second+1) == 1)
                            flag=1;
                    }
                    if(flag==1) continue;
                    int tentative_gScore = current.g + 1;
                    Node neighborNode(tmp, std::make_shared<Node>(current), tentative_gScore, h_(tmp, goal));

                    if (mp.find(hash(tmp)) == mp.end() || tentative_gScore < mp[hash(tmp)].g) {
                        openSet.push(neighborNode);
                        mp[hash(tmp)] = neighborNode;
                    }
                }
            }
        }

        return path; 
    }

private:
    struct Node {
        std::pair<int, int> position;
        std::shared_ptr<Node> parent;
        int g;
        int f;

        Node() : position({0, 0}), parent(nullptr), g(0), f(0) {} 

        Node(std::pair<int, int> pos, std::shared_ptr<Node> par, int gScore, int hScore)
            : position(pos), parent(par), g(gScore), f(gScore + hScore) {}
    };

    struct NodeComparator {
        bool operator()(const Node& a, const Node& b) {
            return a.f > b.f;
        }
    };

    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    int h_(std::pair<int, int> p1, std::pair<int, int> p2) {
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }

    bool isValid(std::pair<int, int> position, const Grid_& gra) {
        int x = position.first;
        int y = position.second;
        return x >= 0 && x < gra.rows && y >= 0 && y < gra.cols && gra.getValue(x, y) == 0;
    }

    int hash(std::pair<int, int> position) const {
        return position.first * 10000 + position.second; 
    }
};

#endif // ASTAR_H
