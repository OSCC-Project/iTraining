﻿// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

struct customer {
	char fullname[35];
	double payment;
};

typedef customer Item;

class Stack
{
private:
	enum { MAX = 10 };        // constant specific to class
	Item items[MAX];        // holds stack items
	int top;                // index for top stack item
	double total = 0;

public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack already is full, true otherwise
	bool push(const Item& item);  // add item to stack
	// pop() returns false if stack already is empty, true otherwise
	bool pop(Item& item);         // pop top into item
	void showTotal();
};

#endif
