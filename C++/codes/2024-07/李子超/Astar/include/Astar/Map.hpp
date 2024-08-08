/**
 * @file Map.hpp
 * @author lizichao ()
 * @brief Header file for the Map class declarations, used in the A* algorithm.
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include <vector>
#include <list>
#include <random>
#include "Astar/Point.hpp"

class Map {
public:
	Map() : _length(0), _width(0) {}
	Map(int length, int weight): _length(length), _width(weight), _graph(static_cast<std::vector<int>::size_type>(length), std::vector<int>(static_cast<std::vector<int>::size_type>(weight))) {}
	Map(int length, int weight, std::vector<std::vector<int>> g) : _length(length), _width(weight), _graph(g) {}

	int getDir(int i, int j);
	int getLength() const;
	void setLength(int length);
	int getWidth() const;
	void setWidth(int weight);
	void setGraph(std::vector<std::vector<int>> g);
	int visitGraph(int i, int j);
	void showMap() const;
	void showPath(std::list<Point*> path);
	void randomizeGraph();

private:
	int _dir[8][2] = { {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {-1, 1} };
	int _length;
	int _width;
	std::vector<std::vector<int>> _graph;
};

#endif // MAP_H_