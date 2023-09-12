#include "golf.h"
#include <iostream>

int main() {
  int sum = 0;
  golf a[Len];
  setGolf(a[0], "Abc def", 24);
  std::cout << "output: " << std::endl;
  showGolf(a[0]);
  setHandicap(a[0], 6);
  std::cout << "handicap: " << a[0].handicap << std::endl;
  showGolf(a[0]);
  for (int i = 0; i < Len; i++) {
    std::cout << "Please enter #" << i + 1 << ": " << std::endl;
    setGolf(a[i]);
    if (setGolf(a[i]) == 0) {
      break;
    }
    ++sum;
  }
  if (sum > 0) {
    std::cout << "Ending output: " << std::endl;
  }
  for (int i = 0; i < sum; i++) {
    showGolf(a[i]);
  }
  std::cout << "Bye." << std::endl;
  system("pause");
  return 0;
}