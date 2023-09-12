#include<iostream>
#include "Point.h"

Point::Point(){
    _xy.x = 0;
    _xy.y = 0;
    _value = 0;
    _parent = nullptr;
}

Point::Point(int m_x, int m_y, int m_value){
    _xy.x = m_x;
    _xy.y = m_y;
    _value = m_value;
    _parent = nullptr;
}

Point::~Point(){
    // delete _parent;
}

void Point::insertAbs() noexcept{
    _value = ADS;
}

void Point::insertFirst() noexcept{
    _value = FIRST;
}

void Point::insertFinal() noexcept{
    _value = FINAL;
}

void Point::insertNoAbs() noexcept{
    _value = NOABS;
}

void Point::insertPriority() noexcept{
    _value = PRIOQUE;
}

int Point::getValue(){
    return _value;
}

Xy Point::getXy(){
    return _xy;
}

void Point::setParent(Point& p){
    _parent = &p;
}

void Point::updateF(){
    _f = _g + _h;
}

std::ostream& operator<<(std::ostream& os, Point& m_point){
    os<<'('<<m_point.getXy().x<<','<<m_point.getXy().y<<')'<<'\n';
    return os;
}

std::ostream& operator<<(std::ostream& os, Xy& m_point){
    os<<'('<<m_point.x<<','<<m_point.y<<')'<<'\n';
    return os;
}

bool Point::operator<(const Point& point1)const{
    if(_f == point1._f) return _h >= point1._h;
    return _f > point1._f;
}