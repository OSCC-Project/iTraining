#include "vector.h"
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  using VECTOR::Vector;
  srand(time(0));
  double direction;
  Vector step;
  Vector result(0.0, 0.0);
  unsigned long steps = 0;
  double target = 50.0;
  double dstep = 2.0;
  unsigned long i, n, maxv, minv;
  double average = 0.0;

  std::cout << "Target distance: " << target << std::endl;
  std::cout << "Step length: " << dstep << std::endl;
  std::cout << "Please you enter running time: ";
  while (!(std::cin >> n)) {
    std::cin.clear();
    while (std::cin.get() != '\n')
      continue;
    std::cout << "Please enter an number: ";
  }
  i = 0, maxv = 0, minv = ULONG_MAX;
  while (i < n) {
    while (result.getMagVal() < target) {
      direction = rand() % 360;
      step.resetVector(dstep, direction, Vector::POL);
      result = result + step;
      steps++;
    }
    maxv = maxv < steps ? steps : maxv;
    minv = minv > steps ? steps : minv;
    average += steps;
    std::cout << "Time #" << i + 1 << ':' << std::endl;
    std::cout << "After " << steps << " steps, the subject ";
    std::cout << "has the following location:\n";
    std::cout << result << std::endl;
    result.setPolarMode();
    std::cout << " or\n";
    std::cout << result << std::endl;
    std::cout << "Average outward distance per step = ";
    std::cout << result.getMagVal() / steps << std::endl;
    steps = 0;
    result.resetVector(0.0, 0.0);
    ++i;
  }
  std::cout << "The maximum steps are: " << maxv << std::endl;
  std::cout << "The minimum steps are: " << minv << std::endl;
  std::cout << "The average steps are: " << average / n << std::endl;
  std::cout << "Bye!\n";
  system("pause");
  return 0;
}
