#include<iostream>

struct CandyBar {
	char _name[40];
	double _weight;
	int _heat;
};

void setCandy(CandyBar& c, const char name[] = "Millennium Munch", double weight = 2.85, int heat = 350);
void showCandy(const CandyBar& c);

int main() {
	CandyBar candy1, candy2;
	setCandy(candy1);
	setCandy(candy2, "Chocolate", 3.85, 800);
	showCandy(candy1);
	showCandy(candy2);
	return 0;
}

void setCandy(CandyBar& c, const char name[], double weight, int heat) {
	strcpy_s(c._name, name);
	c._heat = heat;
	c._weight = weight;
}

void showCandy(const CandyBar& c) {
	std::cout << "Candy name: " << c._name << "\n";
	std::cout << "Candy weight: " << c._weight << "\n";
	std::cout << "Candy heat: " << c._heat << "\n";
}
