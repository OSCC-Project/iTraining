#include <iostream>

const int size_max = 5;
double *fill_array(double *begin, double *end);
void show_array(const double *begin, double *end);
void revalue(double r, double *begin, double *end);

int main() {
  double properties[size_max];
  double *size = fill_array(properties, (properties + size_max));
  show_array(properties, size);
  if (size - properties > 0) {
    std::cout << "Enter revaluation factor: " << std::endl;
    double factor;
    while (!(std::cin >> factor)) {
      std::cin.clear();
      while (std::cin.get() != '\n')
        continue;
      std::cout << "Bad input; Please enter a number: ";
    }
    revalue(factor, properties, size);
    show_array(properties, size);
  }

  std::cout << "Done.\n";
  return 0;
}

double *fill_array(double *begin, double *end) {
  double temp;
  int i;
  double *pre;
  for (i = 0, pre = begin; pre < end; i++, pre++) {
    std::cout << "Enter value #" << (i + 1) << ": ";
    std::cin >> temp;
    if (!std::cin) {
      std::cin.clear();
      while (std::cin.get() != '\n')
        continue;
      std::cout << "Bad input; input process terminated.\n";
      break;
    } else if (temp < 0) {
      break;
    }
    *pre = temp;
  }
  return begin + i;
}

void show_array(const double *begin, double *end) {
  int i;
  for (i = 0; begin < end; begin++, i++) {
    std::cout << "Property #" << (i + 1) << ": " << *begin << std::endl;
  }
}

void revalue(double r, double *begin, double *end) {
  for (; begin <= end; begin++) {
    *begin *= r;
  }
}