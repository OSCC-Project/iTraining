//
//  point.h
//  assignment3
//
//  Created by 郭帆 on 2023/7/26.
//
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <array>

namespace point {
template <typename T, std::size_t N>
class Point {
public:
    Point() = default;
    Point(const std::array<T, N> & init_data) : _data(init_data) {}
    
    virtual Point operator+(const Point & p) const {
        Point ans;
        for (int i = 0; i < N; ++i) {
            ans._data[i] = _data[i] + p._data[i];
        }
        return ans;
    }
    
    const T & operator[](const int index) const {
        return _data[index];
    }
    
    bool operator==(const Point & p) const {
        bool is_equal = true;
        for (int i = 0; i < N; ++i) {
            if (_data[i] != p._data[i]) is_equal = false;
        }
        return is_equal;
    }
    
    friend std::ostream & operator<<(std::ostream & os, const Point & p) {
        os << "(" << p._data[0];
        for (int i = 1; i < N; ++i) {
            os << ", ";
            os << p._data[i];
        }
        os << ")";
        return os;
    }
    
protected:
    std::array<T, N> _data;
};

class Point2i : public Point<int, 2> {
public:
    Point2i() {
        *this = Point2i(0, 0);
    }
    
    Point2i(int x, int y) {
        _data[0] = x;
        _data[1] = y;
    }
    
    int x() const { return _data[0]; }
    int y() const { return _data[1]; }
    void x(int in_x) { _data[0] = in_x; }
    void y(int in_y) { _data[1] = in_y; }
    
    Point2i operator+(const Point2i & p) const {
        return Point2i(_data[0] + p._data[0], _data[1] + p._data[1]);
    }
    
    Point2i operator-() const {
        return Point2i(-_data[0], -_data[1]);
    }
    
    Point2i operator-(const Point2i & p) const {
        return *this + (-p);
    }
};
} // point

#endif // POINT_H
