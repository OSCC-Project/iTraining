#include"10_6.h"
#include<iostream>

int main() {
	Move p0 = Move();
	Move p1(2, 3);
	Move p2(3, 7);
	p0.showMove();
	p1.showMove();
	p2.showMove();
	Move p3 = p1.add(p2);
	p3.showMove();

	return 0;
}