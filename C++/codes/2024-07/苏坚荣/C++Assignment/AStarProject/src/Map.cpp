
/**
 * @file Map.cpp
 * @author SuJianrong (1014150286@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "AStarProject/Map.hpp"
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

/**
 * @brief Print the map
 * 
 */
void Map::showMap() const
{
	std::cout << "The map is:" << std::endl;
	for (const auto& row : m_map) {
		for (const auto& elem : row) {
			if (elem == 0) {
				std::cout << "o ";
			}
			else {
				std::cout << "x ";
			}

		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/**
 * @brief Print the path
 * 
 * @param path 
 */
void Map::showPath(std::list<Node*>& path)
{
	std::vector<std::vector<char>> c_map(getLength(), std::vector<char>(getWidth(), '0'));
	for (int i = 0; i < getLength(); i++) {
		for (int j = 0; j < getWidth(); j++) {
			if (m_map[i][j] == 0) {
				c_map[i][j] = 'o';
			}
			else {
				c_map[i][j] = 'x';
			}
		}
	}
	for (auto& p : path) {
		c_map[p->get_X_value()][p->get_Y_value()] = '#';
	}
	for (int i = 0; i < getLength(); i++) {
		for (int j = 0; j < getWidth(); j++) {
			std::cout << c_map[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/**
 * @brief Initiate the map
 * 
 * @param M_map 
 */
void Map::initMap(std::vector<std::vector<int>>& M_map)
{
	m_map = M_map;
}

/**
 * @brief Using randon method to initiate the map
 * 
 * @param rows 
 * @param cols 
 * @param obstacleRatio 
 */
void Map::initRandonMap(int rows, int cols, double obstacleRatio)
{
	// 初始化随机数生成器
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	// 创建二维数组并填充0
	std::vector<std::vector<int>> M_map(rows, std::vector<int>(cols, 0));

	// 根据障碍比例随机生成0或1
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (static_cast<double>(std::rand()) / RAND_MAX < obstacleRatio) {
				M_map[i][j] = 1; // 设置障碍
			}
		}
	}
	m_map = M_map;
}

