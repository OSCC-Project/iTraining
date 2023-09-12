#include <iostream>

int factorial(int n);

int main() {
  int n;
  std::cout << "Please enter the number: " << std::endl;
  while (std::cin >> n && n != 'q' && n >= 0) {
    std::cout << n << "! = " << factorial(n) << std::endl;
    std::cout << "Please enter the number(q to quit): " << std::endl;
  }
  return 0;
}

int factorial(int n) {
  int num = 1;
  if (n != 0) {
    for (int i = n; i > 1; i--) {
      num *= i;
    }
  }
  return num;
}