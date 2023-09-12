#include "cow.h"
#include <iostream>

int main() {
  std::cout << "Let's start to see our cows!\n";
  Cow c1;
  c1.showCow();
  Cow c2("yellow", "eat grass", 123.456);
  c2.showCow();
  Cow c3("black", "drink water", 222.333);
  c3.showCow();
  c3 = c1;
  Cow c4(c2);
  c3.showCow();
  c4.showCow();
  system("pause");
  return 0;
}