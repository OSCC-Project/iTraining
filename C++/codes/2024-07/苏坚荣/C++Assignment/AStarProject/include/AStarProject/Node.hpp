/**
 * @file Node.hpp
 * @author SuJianrong (1014150286@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

class Node {

private:
	int n_x, n_y;
	int n_F, n_G, n_H;
	Node* n_parent;

public:
	Node();
	Node(int x, int y);
	~Node() {}

	int get_X_value() const { return n_x; }
	void set_X_value(const int x) { n_x = x; }
	int get_Y_value() const { return n_y; }
	void set_Y_value(const int y) { n_y = y; }
	int get_F_value() const { return n_F; }
	void set_F_value(const int F) { n_F = F; }
	int get_G_value() const { return n_G; }
	void set_G_value(const int G) { n_G = G; }
	int get_H_value() const { return n_H; }
	void set_H_value(const int H) { n_H = H; }
	Node* get_parent() const { return n_parent; }
	void set_parent(Node* parent) { n_parent = parent; }

};