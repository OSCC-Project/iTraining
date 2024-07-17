#pragma once

class Move{
private:
    double x;
    double y;
public:
    Move(double a=0, double b=0){
        this->x = a;
        this->y = b;
    }

    void showmove() const{
        std::cout << "x: " << this->x << " y: " << this->y << std::endl;
    }

    Move add(const Move& m) const{
        Move tempmove(this->x+m.x, this->y+m.y);
        return tempmove;
    }

    void reset(double a=0, double b =0){
        this->x = a;
        this->y = b;
    }
};