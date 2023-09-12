#include "vector.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

int main() {
  srand(time(0));
  double direction;
  VECTOR::Vector step;
  VECTOR::Vector result(0.0, 0.0);
  unsigned long steps = 0;
  double target;
  double dstep;
  std::ofstream fout;
  fout.open("RandWalk.txt");
  std::cout << "Enter target distance (q to quit): ";
  while (std::cin >> target) {
    std::cout << "Enetr step length: ";
    if (!(std::cin >> dstep)) {
      break;
    } else {
      fout << "Target Distance: " << target << ", Step Size: " << dstep
           << std::endl;
    }
    int i = 0;
    while (result.magval() < target) {
      direction = rand() % 360;
      step.resetVector(dstep, direction, VECTOR::Vector::POL);
      result = result + step;
      steps++;
      fout << i << ": (x,y) = (" << result.xval() << ", " << result.yval()
           << ")\n";
      i++;
    }
    std::cout << "After " << steps
              << " steps, the subject has the following location:\n";
    std::cout << result << std::endl;
    fout << "After " << steps
         << " steps, the subject has the following location:\n";
    fout << result << std::endl;
    result.polar_mode();
    std::cout << " or\n" << result << std::endl;
    std::cout << "Average outward distance per step = "
              << result.magval() / steps << std::endl;
    fout << " or\n" << result << std::endl;
    fout << "Average outward distance per step = " << result.magval() / steps
         << std::endl;
    steps = 0;
    result.resetVector(0.0, 0.0);
    std::cout << "Enter target distance (q to quit): ";
  }
  std::cout << "Bye!\n";
  fout << "Bye!\n";
  std::cin.clear();
  while (std::cin.get() != '\n')
    continue;

  system("pause");
  return 0;
}
