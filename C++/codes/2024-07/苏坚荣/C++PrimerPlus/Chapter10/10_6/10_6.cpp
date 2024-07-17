#include "10_6.h"
#include <iostream>

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showMove() const
{
	using namespace std;
	cout << "横坐标：" << x << endl;
	cout << "纵坐标：" << y << endl;
}

Move Move::add(const Move& m) const
{
	return Move(x + m.x, y + m.y);
}

void Move::resetMove(double a, double b)
{
	x = a;
	y = b;
}
