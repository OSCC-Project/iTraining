#include "mystack.h"
#include <iostream>

MyStack::MyStack() { _top = 0; }

MyStack::~MyStack() {}

bool MyStack::isEmpty() const { return _top == 0; }

bool MyStack::isFull() const { return _top == MAX; }
bool MyStack::push(const Item &item) {
  if (isFull()) {
    std::cout << "The stack is full!\n";
    return false;
  } else {
    _items[_top++] = item;
    std::cout << "OK. " << std::endl;
  }
  return true;
}

bool MyStack::pop(Item &item) {
  if (isEmpty()) {
    std::cout << "the stack is empty!\n";
    return false;
  } else {
    item = _items[--_top];
    std::cout << "OK." << std::endl;
  }
  return true;
}