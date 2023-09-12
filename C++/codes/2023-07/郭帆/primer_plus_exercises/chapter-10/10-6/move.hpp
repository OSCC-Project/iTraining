//
//  move.hpp
//  10-6
//
//  Created by 郭帆 on 2023/7/20.
//

#ifndef move_hpp
#define move_hpp

#include <iostream>

class Move {
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0) : x(a), y(b) {}
    void showmove() const { std::cout << "x: " << x << ", y: " << y << std::endl; }
    Move add(const Move & m) const { return Move(x + m.x, y + m.y); }
    void reset(double a = 0, double b = 0) { x = a; y = b; }
};

#endif /* move_hpp */
