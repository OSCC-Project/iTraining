#ifndef STACK_H_
#define STACK_H_
typedef unsigned long Item;

class Stack {
private:
	enum {MAX = 10};
	Item* _pitems;
	int _size;
	int _top;
public:
	Stack(int n = MAX);
	Stack(const Stack& st);
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const Item& item);
	bool pop(Item& item);
	Stack& operator=(const Stack& st);
	friend std::ostream& operator<<(std::ostream& os, Stack& stk);
};
#endif // !STACK_H_
