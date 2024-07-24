/**
 * @file AStar.cpp
 * @author SuJianrong (1014150286@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include"AStarProject/AStar.hpp"
#include"AStarProject/Node.hpp"
#include"AStarProject/Map.hpp"
#include <stdlib.h>
#include <cstddef>
#include<cmath>

/**
 * @brief This is a public method which can get the shortest path.
 * 
 * @param startNode 
 * @param endNode 
 * @param isIgnoreCorner 
 * @param a_map 
 * @return std::list<Node*> 
 */
std::list<Node*> AStar::getPath(Node& startNode, Node& endNode, bool isIgnoreCorner, Map& a_map)
{
	Node* resultNode = findPath(startNode, endNode, isIgnoreCorner, a_map);
	std::list<Node*> path;

	while (resultNode) {
		path.push_front(resultNode);
		resultNode = resultNode->get_parent();
	}

	openList.clear();
	closeList.clear();

	return path;
}

/**
 * @brief The main method of A* Algorithm
 * 
 * @param startNode 
 * @param endNode 
 * @param isIgnoreCorner 
 * @param a_map 
 * @return Node* 
 */
Node* AStar::findPath(Node& startNode, Node& endNode, bool isIgnoreCorner, Map& a_map)
{
	openList.push_back(new Node(startNode.get_X_value(), startNode.get_Y_value()));
	while (!openList.empty()) {
		auto currentNode = getLeastFnode();	//在openList中找到F值最小的点
		openList.remove(currentNode);		//从openList中删除这个点
		closeList.push_back(currentNode);	//将这个点放入关闭列表中

		//找到当前周围8个格中可以通过的格子
		auto surroundNodes = getSurroundNodes(currentNode, isIgnoreCorner, a_map);
		//找到后分别处理这些格子
		for (auto& target : surroundNodes) {
			//如果当前点不在openList中，将其加入进去，并设置这个点的父节点为当前格，设置F，G，H
			if (!isInList(target, openList)) {
				target->set_parent(currentNode);

				target->set_G_value(calculate_G_val(currentNode, target));
				target->set_H_value(calculate_H_val(target, &endNode));
				target->set_F_value(calculate_F_val(target));

				openList.push_back(target);
			}
			//如果当前点已经在openList中，计算G值，如果比原来的大，就什么都不做，否则设置他的父节点为当前点，并更新G和F
			else {
				int tempG = calculate_G_val(currentNode, target);
				if (tempG < target->get_G_value()) {
					target->set_parent(currentNode);

					target->set_G_value(tempG);
					target->set_F_value(calculate_F_val(target));
				}
			}
			Node* resultNode = isInList(&endNode, openList);
			if (resultNode) {
				return resultNode;
			}
		}
	}
	return nullptr;
}

/**
 * @brief Get the Node which has the minimum F value
 * 
 * @return Node* 
 */
Node* AStar::getLeastFnode()
{
	if (!openList.empty()) {
		auto resultNode = openList.front();
		for (auto& node : openList) {
			if (node->get_F_value() < resultNode->get_F_value()) {
				resultNode = node;
			}
		}
		return resultNode;
	}
	return nullptr;
}

/**
 * @brief Get the surrounding nodes
 * 
 * @param node 
 * @param isIgnoreCorner 
 * @param a_map 
 * @return std::vector<Node*> 
 */
std::vector<Node*> AStar::getSurroundNodes(const Node* node, bool isIgnoreCorner, Map& a_map) const
{
	std::vector<Node*> surroundNodes;
	for (int i = node->get_X_value() - 1; i <= node->get_X_value() + 1; i++) {
		for (int j = node->get_Y_value() - 1; j <= node->get_Y_value() + 1; j++) {
			if (isCanReach(node, new Node(i, j), isIgnoreCorner, a_map)) {
				surroundNodes.push_back(new Node(i, j));
			}
		}
	}

	return surroundNodes;
}

/**
 * @brief Judege a node which can be reached or not
 * 
 * @param node 
 * @param target 
 * @param isIgnoreCorner 
 * @param a_map 
 * @return true 
 * @return false 
 */
bool AStar::isCanReach(const Node* node, const Node* target, bool isIgnoreCorner, Map& a_map) const
{
	int x = target->get_X_value();
	int y = target->get_Y_value();
	if (x < 0 || x > a_map.getLength() - 1 || y<0 || y > a_map.getWidth() - 1
		|| a_map[x][y] == 1
		|| (x == node->get_X_value() && y == node->get_Y_value())
		|| isInList(target, closeList)) {
		return false;	//如果周围的点超出地图范围、是障碍物、与当前点重合、在关闭列表中，均为不可达
	}
	else {
		if (abs(node->get_X_value() - x) + abs(node->get_Y_value() - y) == 1) {
			return true;	//上下左右可以
		}
		else {
			if (a_map[node->get_X_value()][y] == 0 && a_map[x][node->get_Y_value()] == 0) {
				return true;	//斜对角没有障碍物
			}
			else {
				return isIgnoreCorner;
			}
		}
	}
	return false;
}

/**
 * @brief Judge a node which is in the list or not
 * 
 * @param node 
 * @param List 
 * @return Node* 
 */
Node* AStar::isInList(const Node* node, const std::list<Node*> List) const
{
	for (auto p : List) {
		if (p->get_X_value() == node->get_X_value() && p->get_Y_value() == node->get_Y_value()) {
			return p;
		}
	}
	return nullptr;
}

/**
 * @brief Get G value
 * 
 * @param preNode 
 * @param node 
 * @return int 
 */
int AStar::calculate_G_val(Node* preNode, Node* node)
{
	int extraG = (abs(preNode->get_X_value() - node->get_X_value()) + abs(preNode->get_Y_value() - node->get_Y_value())) == 1 ? MoveCost1 : MoveCost2;
	int parentG = node->get_parent() == nullptr ? 0 : node->get_parent()->get_G_value();	//如果是初始节点，则父节点为空
	return extraG + parentG;
}

/**
 * @brief Get H val
 * 
 * @param node 
 * @param endNode 
 * @return int 
 */
int AStar::calculate_H_val(Node* node, Node* endNode)
{
	//return (abs(endNode->get_X_value() - node->get_X_value()) + abs(endNode->get_Y_value() - node->get_Y_value())) * MoveCost1;
	return sqrt((double)(endNode->get_X_value() - node->get_X_value()) * (double)(endNode->get_X_value() - node->get_X_value())
		+ (double)(endNode->get_Y_value() - node->get_Y_value()) * (double)(endNode->get_Y_value() - node->get_Y_value())) * MoveCost1;

}

/**
 * @brief Get F value
 * 
 * @param node 
 * @return int 
 */
int AStar::calculate_F_val(Node* node)
{
	return node->get_G_value() + node->get_H_value();
}


