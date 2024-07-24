#include"AStarProject/Node.hpp"

Node::Node()
{
	n_x = 0;
	n_y = 0;
	n_F = 0;
	n_G = 0;
	n_H = 0;
	n_parent = nullptr;
}

Node::Node(int x, int y)
{
	n_x = x;
	n_y = y;
	n_F = 0;
	n_G = 0;
	n_H = 0;
	n_parent = nullptr;
}
