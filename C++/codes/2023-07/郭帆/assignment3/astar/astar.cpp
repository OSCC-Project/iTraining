//
//  astar.cpp
//  assignment3
//
//  Created by 郭帆 on 2023/7/26.
//
#include <unordered_set>
#include <queue>
#include <array>
#include <algorithm>
#include <cmath>

#include "astar.h"
#include "myheap.h"

namespace astar {
std::vector<Node *> PathFinder::findPath(gridmap::Map<Node> & map, Node * start_node, Node * target_node) {
    myheap<Node *> open_set;
    
    map.refreshMap();

    start_node->set_status(NodeStatus::open);
    open_set.push(start_node);
    while (!open_set.empty()) {
        Node * current_node = open_set.top();
        open_set.pop();
        
        current_node->set_status(NodeStatus::closed);

        if (*current_node == *target_node) {
            std::deque<Node *> path;
            Node * current_node = target_node;
            while (*current_node != *start_node) {
                path.push_front(current_node);
                current_node = current_node->get_parent();
            }
            path.push_front(current_node);
            return std::vector<Node *>{path.begin(), path.end()};
        }

        for (auto neighbour : map.getNeighbours(*current_node)) {
            if (!neighbour->isWalkable() ||
                neighbour->get_status() == NodeStatus::closed) {
                continue;
            }

            int new_cost_to_neighbour = current_node->get_g_cost() + 
                                        current_node->distance(*neighbour) *
                                        (1.0 + current_node->get_walk_cost());
            bool is_neighbour_in_open_set = neighbour->get_status() == NodeStatus::open;
            if (new_cost_to_neighbour < neighbour->get_g_cost() || !is_neighbour_in_open_set) {
                neighbour->set_g_cost(new_cost_to_neighbour);
                neighbour->set_h_cost(neighbour->distance(*target_node));
                neighbour->set_parent(current_node);
                
                // TODO find a solution about breaking heap structure
                neighbour->set_status(NodeStatus::open);
                open_set.push(neighbour);
                // if (!is_neighbour_in_open_set) {
                //     neighbour->set_status(NodeStatus::open);
                //     open_set.push(neighbour);
                // } else {
                //     std::make_heap(open_set.begin(), open_set.end());
                // }
            }
        }
    }
    
    return {};
}

std::vector<Node *> PathFinder::findPath(gridmap::Map<Node> & map, point::Point2i start_position, point::Point2i end_position) {
    return findPath(map, &map[start_position], &map[end_position]);
}

void PathFinder::showPath(gridmap::Map<Node> & map, const std::vector<Node *> & path) {
    for (int i = 1; i < path.size(); ++i) {
        point::Point2i position = path[i-1]->get_position();
        point::Point2i diff = path[i]->get_position() - position;
        
        if (diff.x() == 0) map[position].set_display_char('-');
        else if (diff.y() == 0) map[position].set_display_char('|');
        else if (diff.x() == diff.y()) map[position].set_display_char('\\');
        else if (diff.x() == -diff.y()) map[position].set_display_char('/');
        else map[position].set_display_char(' ');
        
        std::cout << position << "->";
    }

    auto start_node = path.begin();
    map[(*start_node)->get_position()].set_display_char('*');
    auto target_node = path.end()-1;
    map[(*target_node)->get_position()].set_display_char('#');
    std::cout << (*target_node)->get_position() << " cost: " << (*target_node)->get_g_cost() << std::endl;

    std::cout << map << std::endl;
}
} // astar


