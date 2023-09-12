//
//  astar.h
//  assignment3
//
//  Created by 郭帆 on 2023/7/26.
//
#ifndef ASTAR_H
#define ASTAR_H

#include <vector>

#include "astarnode.h"
#include "gridmap.h"

namespace astar {
class PathFinder {
public:
    PathFinder() : _map(nullptr), _starting_position({ 0, 0 }), _ending_position({ 0, 0 }) {}
    PathFinder(gridmap::Map<Node> & map, const point::Point2i & starting_position, const point::Point2i & ending_position) : 
                _map(&map), _starting_position(starting_position), _ending_position(ending_position) {}

    void set_starting_position(const point::Point2i starting_position) { _starting_position = starting_position; }
    void set_ending_position(const point::Point2i ending_position) { _ending_position = ending_position; }
    void sed_map(gridmap::Map<Node> & map) { _map = &map; }

    std::vector<Node *> findPath() { return findPath(*_map, _starting_position, _ending_position); };
    void showPath(const std::vector<Node *> & path) { return showPath(*_map, path); }

    static std::vector<Node *> findPath(gridmap::Map<Node> & map, Node * start_node, Node * target_node);
    static std::vector<Node *> findPath(gridmap::Map<Node> & map, point::Point2i start_position, point::Point2i end_position);
    static void showPath(gridmap::Map<Node> & map, const std::vector<Node *> & path);
private:
    point::Point2i _starting_position;
    point::Point2i _ending_position;
    gridmap::Map<Node> * _map;
};
} // astar

#endif // ASTAR_H
