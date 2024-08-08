#ifndef MOVE_HPP
#define MOVE_HPP

#include <iostream>

class Move {
private:
    double x; 
    double y; 

public:
   
    Move(double a = 0, double b = 0);

   
    void showmove() const;

  
    Move add(const Move &m) const;

   
    void reset(double a = 0, double b = 0);
};


Move::Move(double a, double b) : x(a), y(b) {}

void Move::showmove() const {
    
    std::cout << "Current x: " << x << ", Current y: " << y << std::endl;
}


Move Move::add(const Move &m) const {
    
    return Move(x + m.x, y + m.y); 
}


void Move::reset(double a, double b) {
   
    x = a;
    y = b;
}

#endif
