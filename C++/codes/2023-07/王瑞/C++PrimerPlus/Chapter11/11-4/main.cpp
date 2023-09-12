#include "mytime.h"
#include <iostream>

int main() {
  MyTime aida(3, 35);
  MyTime tosca(2, 48);
  MyTime temp;

  std::cout << "Aida and Tosca:\n";
  std::cout << aida << "; " << tosca << std::endl;
  temp = aida + tosca;
  std::cout << "Aida + Tosca: " << temp << std::endl;
  temp = aida * 1.17;
  std::cout << "Aida * 1.17: " << temp << std::endl;
  std::cout << "10.0 * Tosca: " << 10.0 * tosca << std::endl;

  system("pause");

  return 0;
}