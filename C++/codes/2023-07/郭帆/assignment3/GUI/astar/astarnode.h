//
//  astarnode.h
//  assignment3
//
//  Created by 郭帆 on 2023/7/26.
//
#ifndef ASTARNODE_H
#define ASTARNODE_H

#include "point.h"
#include "mapnode.h"
#include "mapnode.h"

namespace astar {
enum class NodeStatus { wild, open, closed };

class Node : public gridmap::Node {
public:
    Node() : _parent(this) {}
    
    int get_g_cost() const { return _g_cost; }
    int get_h_cost() const { return _h_cost; }
    int get_f_cost() const { return _f_cost; }
    void set_g_cost(int g_cost) {
        _g_cost = g_cost;
        _f_cost = _g_cost + _h_cost;
    }
    void set_h_cost(int h_cost) {
        _h_cost = h_cost;
        _f_cost = _g_cost + _h_cost;
    }
    Node * get_parent() const { return _parent; }
    void set_parent(Node * parent) { _parent = parent; }
    NodeStatus get_status() { return _status; }
    void set_status(NodeStatus s) { _status = s; }
    
    void refresh() override {
        gridmap::Node::refresh();
        _g_cost = 0;
        _h_cost = 0;
        _f_cost = 0;
        _status = NodeStatus::wild;
    }
    
    int distance(Node & n) {
        int x_distance = std::abs(_position.x() - n._position.x());
        int y_distance = std::abs(_position.y() - n._position.y());
        
        return std::min(x_distance, y_distance)*14 + std::abs(x_distance - y_distance)*10;
    }

    bool operator>(const Node & n) const { return _f_cost > n._f_cost; }

private:
    int _g_cost = 0;
    int _h_cost = 0;
    int _f_cost = 0;
    
    NodeStatus _status = NodeStatus::wild;

    Node * _parent;
};
} // astar

#endif // ASTARNODE_H
