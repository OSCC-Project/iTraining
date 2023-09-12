#include "sales.h"
#include <iostream>
namespace SALES {

void setSales(Sales &s, const double ar[], int n) {
  double sum = 0;
  int ar_max = ar[0];
  int ar_min = ar[0];

  for (int i = 0; i < n; i++) {
    s.sales[i] = ar[i];
    ar_max = ar_max > ar[i] ? ar_max : ar[i];
    ar_min = ar_min < ar[i] ? ar_min : ar[i];
    sum += ar[i];
  }
  s.average = sum / n;
  s.max = ar_max;
  s.min = ar_min;
}

void setSales(Sales &s) {
  int len;
  std::cout << "Please enter the number of sales(0 < number <= " << QUARTERS
            << "): " << std::endl;
  std::cin >> len;
  double *temp = new double[len];
  for (int i = 0; i < len && i < QUARTERS; i++) {
    std::cout << "Please enter sales # " << i + 1 << ": " << std::endl;
    std::cin >> temp[i];
  }
  setSales(s, temp, len);
  delete[] temp;
}

void showSales(const Sales &s) {
  std::cout << "the sales are: " << std::endl;
  std::cout << "the average is : " << s.average << std::endl;
  std::cout << "the maximum is : " << s.max << std::endl;
  std::cout << "the minimum is : " << s.min << std::endl;
}
} // namespace SALES