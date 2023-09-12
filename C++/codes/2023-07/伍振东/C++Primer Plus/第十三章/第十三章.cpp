#include<iostream>
#include"Cd.h"

// 第十三章

// 13.1-2：类的继承应用
void Bravo(const Cd& disk) {
	disk.Report();
}
void controller13_1and2() {
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", 2, 57.17, "Pjilips");
	Cd* pcd = &c1;

	std::cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	std::cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	std::cout << "Testing assignment:";
	Classic copy;
	copy = c2;
	c2.Report();
}

int main() {
	controller13_1and2();
	system("PAUSE");
	return 0;
}