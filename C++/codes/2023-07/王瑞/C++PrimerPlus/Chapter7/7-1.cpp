#include <iostream>

double harmonic_mean(double x, double y);
int main() {
  double a, b;
  std::cout << "Please enter two numbers (0 to quit): ";
  while (std::cin >> a >> b && a && b) {
    std::cout << "the harmonic mean of " << a;
    std::cout << " and " << b << " is ";
    std::cout << harmonic_mean(a, b) << std::endl;
    std::cout << "Next two numbers (0 to quit): ";
  }
  std::cout << "Bye." << std::endl;
  return 0;
}

double harmonic_mean(double x, double y) { return 2.0 * x * y / (x + y); }