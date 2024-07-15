#pragma once
typedef int Item;
class List {
private:
	enum {MAX_SIZE = 10};
	Item list[MAX_SIZE];
	int count;
public:
	List();
	void add(const Item&item);
	bool isEmpty() const;
	bool isFull() const;
	void visit(void (*pf)(Item &));
};