#include "sales.h"
#include <iostream>

using namespace SALES;

int main() {
  double arr1[3] = {10.1, 10.3, 9.6};
  Sales text1, text2;
  setSales(text1, arr1, 3);
  showSales(text1);

  setSales(text2);
  showSales(text2);
  system("pause");
  return 0;
}