// stack.cpp -- Stack member functions
#include "10_5.h"
#include <iostream>

Stack::Stack()    // create an empty stack
{
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const Item& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		item = items[--top];
		total += item.payment;
		return true;
	}
	else
		return false;
}

void Stack::showTotal()
{
	std::cout << "总数为：" << total << std::endl;
}
