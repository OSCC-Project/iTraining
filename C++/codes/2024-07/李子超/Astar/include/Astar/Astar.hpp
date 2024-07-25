/**
 * @file Astar.hpp
 * @author lizichao ()
 * @brief Header file for the A* algorithm class declarations.
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef ASTAR_H_
#define ASTAR_H_

#include "Astar/Point.hpp"
#include "Astar/Map.hpp"
#include <vector>
#include <list>
#include <set>

const int kCost1 = 10;
const int kCost2 = 14;

struct ComparePoints {
	bool operator()(const Point* p1, const Point* p2) const {
		return p1->getF() < p2->getF();
	}
};

class Astar {
public:
	std::list<Point*> findPath(Point* start, Point* end, Map& map);

private:
	int calcF(Point* now) const;
	int calcG(Point* temp_start, Point* point);
	int calcH(Point* now, Point* end) const;
	bool isUseful(int x, int y, Map& map);
	bool isInOpenList(Point* now);
	bool isInCloseList(Point* now);
	std::vector<Point*> findSurround(Point* now, Map& map);
	std::list<Point*> showPath() const;

private:
	std::multiset<Point*, ComparePoints> _openList;
	std::list<Point*> _closeList;
};

#endif // ASTAR_H_