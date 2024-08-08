#include <iostream>
#include "10-8-list.h"
void show(Item &item) {
	std::cout << item << std::endl;
}
void add(Item &item) {
	item++;
}
int main()
{
	List test;
	test.add(10);
	test.add(20);
	test.add(30);

	test.visit(show);
	test.visit(add);
	test.visit(show);
}