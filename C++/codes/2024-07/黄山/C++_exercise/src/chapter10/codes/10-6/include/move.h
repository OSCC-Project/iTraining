#pragma once

class Move{
public:
    Move(double x=0, double y=0){
        m_x = x;
        m_y = y;
    }

    void showmove() const{
        std::cout << "x: " << m_x << " y: " << m_y << std::endl;
    }

    Move add(const Move& other) const{
        Move tempmove(m_x+other.m_x, m_y+other.m_y);
        return tempmove;
    }

    void reset(double x=0, double y=0){
        m_x = x;
        m_y = y;
    }

private:
    double m_x;
    double m_y;
};