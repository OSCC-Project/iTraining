#include"10_3.h"
#include<iostream>

int main() {
	Golf g1;
	Golf g2("User2", 10);
	g1.showGolf();
	g2.showGolf();
	g1.resetHandicap(20);
	g1.showGolf();

}