//
//  mapnode.h
//  cppex
//
//  Created by 郭帆 on 2023/7/28.
//

#ifndef MAPNODE_H
#define MAPNODE_H

#include <iostream>
#include <string>
#include <cmath>

#include "point.h"

namespace gridmap {
class Node {
public:
    Node() : _walk_cost(0), _position({0, 0}) {}
    Node(point::Point2i position, double walk_cost = 0) : _walk_cost(walk_cost), _position(position) {}
    
    double get_walk_cost() { return _walk_cost; }
    void set_walk_cost(double cost) { _walk_cost = cost; }
    const point::Point2i & get_position() const { return _position; }
    int x() const { return _position.x(); }
    int y() const { return _position.y(); }
    void x(int in_x) { _position.x(in_x); }
    void y(int in_y) { _position.y(in_y); }
    void set_display_char(char c) { _display_char = c; }

    bool isWalkable() const { return !std::isinf(_walk_cost); }
    
    virtual void refresh() { _display_char = ' '; }
    
    virtual bool operator==(const Node & n) const { return this == &n ? true : _position.x() == n._position.x() && _position.y() == n._position.y(); }
    
    bool operator!=(const Node & n) const { return !(*this == n); }

    friend std::ostream & operator<<(std::ostream & os, const Node & n) {
        std::string color_control = "";
        char display = n._display_char;
        if (!n.isWalkable()) {
            color_control = "\e[40;37m";
            display = 'x';
        }
        else if (n._walk_cost < 0.1) color_control = "\e[47;30m";
        else if (n._walk_cost < 0.3) color_control = "\e[46;30m";
        else if (n._walk_cost < 0.5) color_control = "\e[44;30m";
        else if (n._walk_cost < 0.7) color_control = "\e[43;30m";
        else if (n._walk_cost < 0.9) color_control = "\e[45;30m";
        else color_control = "\e[41;30m";
        
        std::cout << color_control << display;
        std::cout << "\e[0m";
        return os;
    }
    
protected:
    double _walk_cost;              // range 0-1, inf means unwalkable
    point::Point2i _position;
    
    char _display_char = ' ';
};
}

#endif // MAPNODE_H
