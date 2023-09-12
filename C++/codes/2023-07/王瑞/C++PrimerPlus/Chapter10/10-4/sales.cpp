#include "sales.h"
#include <iostream>

Sales::Sales() {
  int len;
  std::cout << "Please enter the number of _sales: (0 < number < 4)"
            << std::endl;
  std::cin >> len;
  for (int i = 0; i < 4; i++) {
    _sales[i] = 0;
  }

  while (!(std::cin >> len)) {
    std::cin.clear();
    while (std::cin.get() <= 0 || std::cin.get() > 4) {
      continue;
      std::cout << "Bad input; Please enter a number(0 < number < 4): ";
    }
  }

  for (int i = 0; i < len; i++) {
    std::cout << "Please enter the _sales # " << i + 1 << ": " << std::endl;
    std::cin >> _sales[i];
  }
  this->setAverage();
  this->setMin();
  this->setMax();
}

Sales::~Sales() {}

Sales::Sales(const double S[], int len) {
  int i;
  for (i = 0; i < len; i++) {
    _sales[i] = S[i];
  }
  if ((i - 1) < 4) {
    while (i < 4) {
      _sales[i] = 0;
      i++;
    }
  }
  this->setAverage();
  this->setMin();
  this->setMax();
}

void Sales::setAverage() {
  double total = 0.0;
  int i;
  for (i = 0; _sales[i] != 0; i++) {
    total += _sales[i];
  }
  _average = total / i;
}

void Sales::setMax() {
  double max = _sales[0];
  if (_sales[1] != 0) {
    for (int i = 1; _sales[i] != 0; i++) {
      max = max > _sales[i] ? max : _sales[i];
    }
  }
  _max = max;
}

void Sales::setMin() {
  double min = _sales[0];
  if (_sales[1] != 0) {
    for (int i = 1; i < _sales[i] != 0; i++) {
      min = min < _sales[i] ? min : _sales[i];
    }
  }
  _min = min;
}

void Sales::showSales() const {
  std::cout << "the _sales are as follows: " << std::endl;
  int i = 0;
  while (_sales[i++] != 0) {
    std::cout << "_sales #" << i << ": " << _sales[i] << std::endl;
  }
  std::cout << "the average is : " << _average << std::endl;
  std::cout << "the minimum is : " << _min << std::endl;
  std::cout << "the maximum is : " << _max << std::endl;
}

void Sales::showAverage() const {
  std::cout << "the average is : " << _average << std::endl;
}

void Sales::showMin() const {
  std::cout << "the minimum is : " << _min << std::endl;
}

void Sales::showMax() const {
  std::cout << "the maximum is : " << _max << std::endl;
}