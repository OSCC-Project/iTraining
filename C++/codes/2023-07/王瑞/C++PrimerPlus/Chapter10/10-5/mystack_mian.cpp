#include "iostream"
#include "mystack.h"

int main() {
  unsigned long num = 0;
  MyStack st;
  std::cout << "the stack empty is: " << st.isEmpty() << std::endl;
  std::cout << "the stack push:  " << st.push(12);
  std::cout << "the stack full is: " << st.isFull() << std::endl;
  for (int i = 0; !st.isFull(); i++) {
    st.push(i);
  }
  std::cout << "the stack full is: " << st.isFull() << std::endl;
  std::cout << "the stack empty is: " << st.isEmpty() << std::endl;
  std::cout << "the stack push:  " << st.pop(num);
  system("pause");
  return 0;
}