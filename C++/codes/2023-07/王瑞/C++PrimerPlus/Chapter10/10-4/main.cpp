#include "sales.h"
#include <iostream>

int main() {
  Sales Sales1;
  Sales1.showSales();
  double text[3] = {3.2, 8.4, 1.6};
  Sales Sales2(text, 3);
  Sales2.showSales();
  system("pause");
  return 0;
}