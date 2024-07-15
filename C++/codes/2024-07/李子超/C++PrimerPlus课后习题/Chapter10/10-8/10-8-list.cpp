#include "10-8-list.h"
#include <iostream>
List::List()
{
	count = 0;
};
void List::add(const Item&item) {
	if (isFull())
		std::cout << "the list is full!" << std::endl;
	else {
		list[count++] = item;
	}
	
};
bool List::isEmpty()const {
	return count == 0;
};

bool List::isFull() const {
	return count == MAX_SIZE;
};
void List::visit(void(*pf)(Item &)) {
	for (int i = 0; i < count; i++)
		pf(list[i]);
};
