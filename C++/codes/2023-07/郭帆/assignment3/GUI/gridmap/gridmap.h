//
//  gridmap.h
//  assignment3
//
//  Created by 郭帆 on 2023/7/26.
//
#ifndef GRIDMAP_H
#define GRIDMAP_H

#include <iostream>
#include <array>
#include <vector>

#include "point.h"
#include "mapnode.h"

namespace gridmap {
template <typename T> // requires std::is_base_of_v<Node, T> // C++20
class Map {
public:
    Map(int x, int y) {
        _map_size.x(x);
        _map_size.y(y);
        _map = std::vector<std::vector<T>>(x, std::vector<T>(y, T()));
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                _map[i][j].x(i);
                _map[i][j].y(j);
                _map[i][j].set_walk_cost(0);
            }
        }
    }

    Map(std::vector<std::vector<double>> map_data) {
        int x = map_data.size();
        int y = 0;
        if (x > 0) {
            _map_size.x(x);

            y = map_data[0].size();
            if (y > 0) {
                _map_size.y(y);
                _map = std::vector<std::vector<T>>(x, std::vector<T>(y, T()));
            }
        }

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                _map[i][j].x(i);
                _map[i][j].y(j);
                if (j < map_data[i].size())
                    _map[i][j].set_walk_cost(map_data[i][j]);
            }
        }
    }
    
    const point::Point2i & get_map_size() { return _map_size; }

    T & operator[](const point::Point2i & p) {
        return _map[p.x()][p.y()];
    }
    
    std::vector<T> & operator[](int index) {
        return _map[index];
    }

    std::vector<T *> getNeighbours(const point::Point2i & p) {
        std::vector<T *> neighbours;
        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                point::Point2i coord = p + point::Point2i{ x, y };
                if (!(x == 0 && y == 0) &&
                    coord.x() >= 0 && coord.x() < _map_size.x() &&
                    coord.y() >= 0 && coord.y() < _map_size.y()) {
                    neighbours.emplace_back(&_map[coord.x()][coord.y()]);
                }
            }
        }
        return neighbours;
    }

    std::vector<T *> getNeighbours(const T & n) {
        return getNeighbours(n.get_position());
    }
    
    void refreshMap() {
        for (auto &line : _map) {
            for (auto &item : line) {
                item.refresh();
            }
        }
    }
    
    friend std::ostream & operator<<(std::ostream & os, const Map & m) {
        for (auto &line : m._map) {
            for (auto &item : line) {
                std::cout << item;
            }
            std::cout << std::endl;
        }
        return os;
    }
    
private:
    std::vector<std::vector<T>> _map;
    point::Point2i _map_size;
};
} // gridmap

#endif // GRIDMAP_H
