#ifndef MYSTACK_H_
#define MYSTACK_H_

typedef unsigned long Item;

class MyStack {
private:
  enum { MAX = 10 };
  Item _items[MAX];
  int _top;

public:
  MyStack();
  ~MyStack();
  bool isEmpty() const;
  bool isFull() const;
  bool push(const Item &_item);
  bool pop(Item &_item);
};
#endif