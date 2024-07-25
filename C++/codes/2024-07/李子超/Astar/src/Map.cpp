/**
 * @file Map.cpp
 * @author lizichao ()
 * @brief Implementation file for the Map class.
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Astar/Map.hpp"

int Map::getDir(int i, int j)
{
	return _dir[i][j];
}

int Map::getLength() const
{
	return  this->_length;
}

void Map::setLength(int length)
{
	this->_length = length;
}

int Map::getWidth() const
{
	return this->_width;
}

void Map::setWidth(int weight)
{
	this->_width = weight;
}

void Map::setGraph(std::vector<std::vector<int>> g)
{
	_graph = g;
}



int Map::visitGraph(int i, int j)
{
	return _graph[i][j];
}

void Map::showMap() const
{
	for (int i = 0; i < _length; i++) {
		for (int j = 0; j < _width; j++) {
			if (_graph[i][j] == 0) std::cout << "o"<<" ";
			else std::cout << "x"<<" ";
		}
		std::cout << std::endl<< std::endl;
	}
}

void Map::showPath(std::list<Point*> path)
{
	std::vector<std::vector<int>> result_graph = _graph;
	for (auto it : path) {
		result_graph[it->getX()][it->getY()] = 2;
	}
	for (int i = 0; i < _length; i++) {
		for (int j = 0; j < _width; j++) {
			if (result_graph[i][j] == 0) std::cout << "o" << " ";
			else if (result_graph[i][j] == 1) std::cout << "x" << " ";
			else std::cout << "#" << " ";
		}
		std::cout << std::endl << std::endl;
	}
}

void Map::randomizeGraph()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);

	for (auto& row : _graph) {
		for (auto& elem : row) {
			elem = dis(gen);
		}
	}
}
