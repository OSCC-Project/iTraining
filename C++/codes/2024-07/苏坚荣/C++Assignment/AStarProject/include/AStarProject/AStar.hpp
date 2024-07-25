/**
 * @file AStar.hpp
 * @author SuJianrong (1014150286@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include"AStarProject/Node.hpp"
#include"AStarProject/Map.hpp"
#include <vector>
#include <list>


const int MoveCost1 = 10;	//横向或纵向移动一格的距离
const int MoveCost2 = 14;	//斜着移动一格的距离


class AStar {

private:
	std::list<Node*> openList;
	std::list<Node*> closeList;

	Node* findPath(Node& startNode, Node& endNode, bool isIgnoreCorner, Map& a_map);
	Node* getLeastFnode();
	std::vector<Node*> getSurroundNodes(const Node* node, bool isIgnoreCorner, Map& a_map) const;
	bool isCanReach(const Node* node, const Node* target, bool isIgnoreCorner, Map& a_map) const;
	Node* isInList(const Node* node, const std::list<Node*> List) const;
	int calculate_G_val(Node* preNode, Node* node);
	int calculate_H_val(Node* node, Node* endNode);
	int calculate_F_val(Node* node);

public:
	AStar() : openList({}), closeList({}) {}
	std::list<Node*> getPath(Node& startNode, Node& endNode, bool isIgnoreCorner, Map& a_map);

};


