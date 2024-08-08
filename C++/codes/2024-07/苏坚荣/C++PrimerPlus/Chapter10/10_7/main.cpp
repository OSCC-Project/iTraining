#include<iostream>
#include"10_7.h"

int main() {
	Plorg p1 = Plorg();
	Plorg p2("sujianrong");
	p1.showPlorg();
	p2.showPlorg();
	p2.resetCI(25);
	p2.showPlorg();

	return 0;
}