#include "stock2.h"
#include <cstring>
#include <iostream>

Stock::Stock() {
  _company = new char[strlen("no name") + 1];
  strcpy(_company, "no name");
  _shares = 0;
  _share_val = 0.0;
  _total_val = 0.0;
}

Stock::Stock(const char *co, long n, double pr) {
  int len = strlen(co);
  _company = new char[len + 1];
  strcpy(_company, co);
  if (n < 0) {
    std::cout << "Number of _shares can't be negative; " << _company
              << " _shares set to 0.\n";
    _shares = 0;
  } else {
    _shares = n;
  }
  _share_val = pr;
  set_tot();
}

Stock::~Stock() { delete[] _company; }

void Stock::buyCompany(long num, double price) {
  if (num < 0) {
    std::cout << "Number of _shares purchased can't be negative. "
              << "Transaction is aborted.\n";
  } else {
    _shares += num;
    _share_val = price;
    set_tot();
  }
}

void Stock::sellCompany(long num, double price) {
  if (num < 0) {
    std::cout << "Number of _shares sold can't be negative. "
              << "Transaction is aborted.\n";
  } else if (num > _shares) {
    std::cout << "You can't sell more than you have! "
              << "Transaction is aborted.\n";
  } else {
    _shares -= num;
    _share_val = price;
    set_tot();
  }
}

void Stock::updatePrice(double price) {
  _share_val = price;
  set_tot();
}

std::ostream &operator<<(std::ostream &os, const Stock &st) {
  os << "Company: " << st._company << std::endl;
  os << "Share: " << st._shares << std::endl;
  os << "Share value: " << st._share_val << std::endl;
  os << "total value: " << st._total_val << std::endl;
  return os;
}

const Stock &Stock::topval(const Stock &s) const {
  if (s._total_val > _total_val) {
    return s;
  } else {
    return *this;
  }
}