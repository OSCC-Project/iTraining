#include<iostream>
#include"Stack.h"

Stack::Stack(int n) {
	_size = n;
	_top = 0;
	_pitems = new Item[n];
}

Stack::Stack(const Stack& st) {
	_size = st._size;
	_top = st._top;
	_pitems = new Item[_size];
	
	for (int i = 0; i < _top; ++i) {
		_pitems[i] = st._pitems[i];
	}
}

Stack::~Stack() {
	delete[]_pitems;
}

bool Stack::isEmpty()const {
	if (_size == 0)return 1;
	return 0;
}

bool Stack::isFull()const {
	if (_top == _size)return 1;
	else return 0;
}

// 先添加，再加一
bool Stack::push(const Item& item) {
	if (isFull())return 0;
	_pitems[_top] = item;
	_top += 1;
	return 1;
}

bool Stack::pop(Item& item) {
	if (isEmpty())return 0;
	item = _pitems[--_top];
	return 1;
}

Stack& Stack::operator=(const Stack& st) {
	_size = st._size;
	_top = st._top;
	delete[]_pitems;
	_pitems = new Item[_size];
	for (int i = 0; i < _top; ++i) {
		_pitems[i] = st._pitems[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, Stack& stk) {
	for (int i = 0; i < stk._top; ++i) {
		os << stk._pitems[i] << " ";
	}
	return os;
}