/**
 * @file Point.hpp
 * @brief Header file for the Point class declarations, representing points in the map.
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	Point(int x, int y) : _x(x), _y(y), _F(0), _G(0), _H(0), _parent(nullptr) {}

	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	int getF() const;
	void setF(int F);
	int getG() const;
	void setG(int G);
	int getH() const;
	void setH(int H);
	Point* getParent() const;
	void setParent(Point* parent);

	bool operator==(const Point& other) const {
		return _x == other._x && _y == other._y;
	}

private:
	int _x;
	int _y;
	int _F;
	int _G;
	int _H;
	Point* _parent;
};

#endif // POINT_H_