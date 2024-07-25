/**
 * @file Astar.cpp
 * @author lizichao ()
 * @brief Implementation file for the A* algorithm.
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Astar/Astar.hpp"
#include <algorithm>
#include <memory>
#include <iostream>
#include <set>

int Astar::calcF(Point * now) const
{
	return now->getG() + now->getH();
}

int Astar::calcG(Point *temp_start, Point *point)
{
	int extraG = (abs(point->getX() - temp_start->getX()) + abs(point->getY() - temp_start->getY())) == 1 ? kCost1 : kCost2;
	int parentG = point->getParent() == NULL ? 0 : point->getParent()->getG();
	return parentG + extraG;
}
int Astar::calcH(Point * now, Point * end) const
{
	int dx = end->getX() - now->getX();
	int dy = end->getY() - now->getY();
	return static_cast<int>(sqrt(dx * dx + dy * dy) * kCost1);
}


bool Astar::isUseful(int x, int y, Map &map)
{
	//ʹ�� std::unique_ptr ������ָ�룬�Ա����ֶ������ڴ档
	auto point = std::make_unique<Point>(x, y);
	return !(x < 0 || x >= map.getLength() || y < 0 || y >= map.getWidth() || map.visitGraph(x, y) == 1 || isInCloseList(point.get()));
}

bool Astar::isInOpenList(Point * now)
{
	//ʹ��lambda����ʽ
	return std::any_of(_openList.begin(), _openList.end(), [now](Point* point) {
		return point->getX() == now->getX() && point->getY() == now->getY();
	});
}

bool Astar::isInCloseList(Point * now)
{
	return std::any_of(_closeList.begin(), _closeList.end(), [now](Point* point) {
		return point->getX() == now->getX() && point->getY() == now->getY();
	});
}

std::vector<Point*> Astar::findSurround(Point * now, Map &map)
{
	std::vector<Point*> surroundings;
	int newx=0,newy = 0;
	for (int i = 0; i < 8; i++) {
			newx = now->getX() + map.getDir(i,0);
			newy = now->getY() + map.getDir(i,1);
			if (isUseful(newx, newy,map)) {
				surroundings.push_back(new Point(newx, newy));
			}	
		
	}
	return surroundings;
}

std::list<Point*> Astar::findPath(Point * start, Point * end, Map &map)
{
	_openList.insert(start);
	while (!_openList.empty()) {
		auto it = _openList.begin();
		Point* now = *it;
		_openList.erase(it);
		_closeList.push_back(now);
		auto surrounds = findSurround(now, map);

		for (auto &target : surrounds) {
			if (!isInOpenList(target)) {
				target->setParent(now);
				target->setG(calcG(now, target));
				target->setH(calcH(target, end));
				target->setF(calcF(target));
				_openList.insert(target);
			}
			else {
				int tempG = calcG(now, target);
				if (tempG < target->getG()) {
					target->setParent(now);
					target->setG(tempG);
					target->setF(calcF(target));
				}
			}
		}
		if (isInCloseList(end)) {
			auto List = showPath();
			map.showPath(List);
			return List;
		}
	}
	std::cout << "path no found" << std::endl;
	return std::list<Point*>();
}

std::list<Point*> Astar::showPath() const
{
	std::list<Point*> showlist;
	auto end = _closeList.back();
	while (end != nullptr) {
		showlist.push_front(end);
		end = end->getParent();
	}
	std::cout << "the path is:" << std::endl;
	
	for (const auto& point : showlist) {
		if (point != showlist.back()) {
			std::cout << "(" << point->getX() << "," << point->getY() << ") -> ";
		}
		else {
			std::cout << "(" << point->getX() << "," << point->getY() << ")";
		}
	}
	std::cout << std::endl << std::endl;
	return showlist;;
}


