/**
 * @file Point.cpp
 * @author lizichao ()
 * @brief Implementation file for the Point class.
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Astar/Point.hpp"

int Point::getX() const
{
	return this->_x;
}

void Point::setX(int x)
{
	this->_x = x;
}

int Point::getY() const
{
	return this->_y;
}

void Point::setY(int y)
{
	this->_y = y;
}

int Point::getF() const
{
	return this->_F;
}

void Point::setF(int F)
{
	this->_F =F;
}

int Point::getG() const
{
	return this->_G;
}

void Point::setG(int G)
{
	this->_G = G;
}

int Point::getH() const
{
	return this->_H;
}

void Point::setH(int H)
{
	this->_H = H;
}

Point* Point::getParent() const
{
	return this->_parent;
}

void Point::setParent(Point * parent)
{
	this->_parent = parent;
}
