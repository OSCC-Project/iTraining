#include "classic.h"
#include <cstring>
#include <iostream>

void Bravo(const Cd &disk);

int main() {
  Cd c1("Beatles", "Capitol", 14, 35.5);
  Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                       "Alfred Brendel", "Philips", 2, 57.17);
  Cd *pcd = &c1;
  std::cout << "Using object directly:\n";
  c1.reportInfo();
  c2.reportInfo();
  std::cout << "Using type cd * pointer to objects:\n";
  pcd->reportInfo();
  pcd = &c2;
  pcd->reportInfo();
  std::cout << "Calling a function with a Cd reference argument:\n";
  Bravo(c1);
  Bravo(c2);
  std::cout << "Testing assignment: ";
  Classic copy;
  copy = c2;
  copy.reportInfo();
  system("pause");
  return 0;
}

void Bravo(const Cd &disk) { disk.reportInfo(); }
