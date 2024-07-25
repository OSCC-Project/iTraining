/**
 * @file tmp_test.cpp
 * @author SuJianrong (1014150286@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <gtest/gtest.h>
#include<iostream>
#include"AStarProject/AStar.hpp"
#include"AStarProject/Map.hpp"
#include"AStarProject/Node.hpp"

/**
 * @brief Construct a new TEST object to check the path
 * 
 */
TEST(MyAstar,CheckPath){
  	std::vector<std::vector<int>> mp = {
		{0,0,0,0,1,1,1,1},
		{0,0,0,0,0,1,1,1},
		{1,1,0,1,1,0,0,0},
		{1,0,0,0,0,0,0,0}
	};
  	AStar astar;
	Map mmap;
	Node startNode = Node(0, 0);
	Node endNode = Node(3, 7);
	mmap.initMap(mp);
	std::list<Node*> path = astar.getPath(startNode, endNode, true, mmap);

	std::list<Node*> result;
	result.push_back(new Node(0, 0));
	result.push_back(new Node(0, 1));
	result.push_back(new Node(1, 2));
	result.push_back(new Node(1, 3));
	result.push_back(new Node(1, 4));
	result.push_back(new Node(2, 5));
	result.push_back(new Node(2, 6));
	result.push_back(new Node(3, 7));

	int flag = true;
	std::list<Node*>::iterator it1 = path.begin();
	std::list<Node*>::iterator it2 = result.begin();
	for (; it1 != path.end() && it2 != result.end(); it1++, it2++) {
		if ((*it1)->get_X_value() != (*it2)->get_X_value() || (*it1)->get_Y_value() != (*it2)->get_Y_value()) {
			flag = false;
		}
	}
	EXPECT_EQ(true,flag);
}

/**
 * @brief Construct a new TEST object to check the value of F,G,H
 * 
 */
TEST(MyAstar, checkValue){
	std::vector<std::vector<int>> mp = {
		{0,0,0,0,1,1,1,1},
		{0,0,0,0,0,1,1,1},
		{1,1,0,1,1,0,0,0},
		{1,0,0,0,0,0,0,0}
	};
  	AStar astar;
	Map mmap;
	Node startNode = Node(0, 0);
	Node endNode = Node(3, 7);
	mmap.initMap(mp);
	std::list<Node*> path = astar.getPath(startNode, endNode, true, mmap);

	int position = 4;
	std::list<Node*>::iterator it = path.begin();
	std::advance(it, position);
	EXPECT_EQ((*it)->get_F_value(), 80);
	EXPECT_EQ((*it)->get_G_value(), 44);
	EXPECT_EQ((*it)->get_H_value(), 36);
	EXPECT_NE((*it)->get_F_value(), 200);
}

int main(int argc, char **argv) {
	std::vector<std::vector<int>> mp = {
		{0,0,0,0,1,1,1,1},
		{0,0,0,0,0,1,1,1},
		{1,1,0,1,1,0,0,0},
		{1,0,0,0,0,0,0,0}
	};
	AStar astar;
	Map mmap;

	while (true) {
		std::cout << "输入 '1' 使用原始地图, 输入 '2' 使用随机地图, 输入 '3' 打印地图, 输入 '4' 打印路径, 输入 'q' 退出: ";
		char input;
		std::cin >> input;
		std::cout << std::endl;

		if (input == 'q') {
			break;
		}
		else if (input == '1') {
			mmap.initMap(mp);
			std::cout << "初始化地图成功！" << std::endl << std::endl;
		}
		else if (input == '2') {
			std::cout << "请输入地图的行数和列数: ";
			int rows, cols;
			double obstacleRatio = 0.3; // 随机障碍的比例
			std::cin >> rows >> cols;
			mmap.initRandonMap(rows, cols, obstacleRatio);
			std::cout << "随机地图生成成功！" << std::endl << std::endl;
		}
		else if (input == '3') {
			std::cout << "当前地图为: " << std::endl;
			mmap.showMap();
		}
		else if (input == '4') {
			int x1, x2, y1, y2;
			std::cout << "请输入起点和终点的坐标: ";
			std::cin >> x1 >> y1 >> x2 >> y2;
			Node startNode = Node(x1, y1);
			Node endNode = Node(x2, y2);

			std::list<Node*> path = astar.getPath(startNode, endNode, true, mmap);

			if (!path.empty()) {
				std::cout << "The shortest path is: ";
				for (auto& p : path) {
					std::cout << "(" << p->get_X_value() << "," << p->get_Y_value() << ") ";
				}
				std::cout << std::endl;
				mmap.showPath(path);
			}
			else {
				std::cout << "No path is found!" << std::endl;
			}
			std::cout << std::endl;
		}
		else {
			std::cout << "无效的输入，请重新输入。" << std::endl;
		}
	}
	
  	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}