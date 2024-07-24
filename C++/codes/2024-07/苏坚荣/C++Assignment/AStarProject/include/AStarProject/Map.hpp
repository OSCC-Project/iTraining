/**
 * @file Map.hpp
 * @author SuJianrong (1014150286@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <vector>
#include <list>
#include "AStarProject/Node.hpp"


class Map {

public:
	void showMap() const;
	void showPath(std::list<Node*>& path);
	void initMap(std::vector<std::vector<int>>& M_map);
	void initRandonMap(int rows, int cols, double obstacleRatio);
	std::vector<std::vector<int>> getMap() const { return m_map; }
	int getLength() const { return m_map.size(); }
	int getWidth() const { return m_map[0].size(); }
	std::vector<int>& operator[](int index) {
		return m_map[index];
	}
	const std::vector<int>& operator[](int index) const {
		return m_map[index];
	}

private:
	std::vector<std::vector<int>> m_map;
	int length;
	int width;
};