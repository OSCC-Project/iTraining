#include <iostream>
#include "stack.h"

Stack::Stack(int n)
{
	size = n;
	top = 0;
	pitems = new Item[size];
}

Stack::Stack(const Stack& st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < st.size; i++) {
		pitems[i] = st.pitems[i];
	}
}

Stack::~Stack()
{
	delete[] pitems;
}

bool Stack::isEmpty() const
{
	return top == 0;
}

bool Stack::isFull() const
{
	return top == MAX;
}

bool Stack::push(const Item& item)
{
	if (top < MAX) {
		pitems[top++] = item;
		return true;
	}
	return false;
}

bool Stack::pop(Item& item)
{
	if (top > 0) {
		item = pitems[--top];
		return true;
	}
	return false;
}

Stack& Stack::operator=(const Stack& st)
{
	if (this == &st) {
		return *this;
	}
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < st.size; i++) {
		pitems[i] = st.pitems[i];
	}
}
