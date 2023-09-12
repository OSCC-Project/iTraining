#include "complex0.h"
#include <iostream>

int main() {
  Complex a(3.0, 4.0);
  Complex c;
  std::cout << "Enter a complex number (q to quit):\n";
  while (std::cin >> c) {
    std::cout << "c is " << c << std::endl;
    std::cout << "complex conjugate is " << ~c << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "a + c is " << (a + c) << std::endl;
    std::cout << "a - c is " << (a - c) << std::endl;
    std::cout << "a * c is " << (a * c) << std::endl;
    std::cout << "2 * c is " << (2 * c) << std::endl;
    std::cout << "Enter a complex number (q to quit):\n";
  };
  std::cout << "Done!\n";

  return 0;
}