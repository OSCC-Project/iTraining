#include <iostream>

double calculate(double a, double b, double (*p)(double a, double b));
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);

int main() {
  double a, b;
  double (*pf[3])(double a, double b) = {add, subtract, multiply};

  std::cout << "Enter two numbers (q to quit): ";
  while (std::cin >> a >> b) {
    for (int i = 0; i < 3; i++) {
      switch (i) {
      case 0: {
        std::cout << "The " << a << " + " << b << " = " << (*pf[i])(a, b)
                  << std::endl;
        break;
      }
      case 1: {
        std::cout << "The " << a << " - " << b << " = " << (*pf[i])(a, b)
                  << std::endl;
        break;
      }
      case 2: {
        std::cout << "The " << a << " * " << b << " = " << (*pf[i])(a, b)
                  << std::endl;
        break;
      }
      }
    }
  }
  return 0;
}

double calculate(double a, double b, double (*p)(double a, double b)) {
  return (*p)(a, b);
}
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }