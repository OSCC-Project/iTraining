#ifndef STOCK2_H_
#define STOCK2_H_
#include <iostream>

class Stock {
public:
  Stock();
  Stock(const char *co, long n = 0, double pr = 0.0);
  ~Stock();
  void buyCompany(long num, double price);
  void sellCompany(long num, double price);
  void updatePrice(double price);
  friend std::ostream &operator<<(std::ostream &os, const Stock &st);
  const Stock &topval(const Stock &s) const;

private:
  char *_company;
  int _shares;
  double _share_val;
  double _total_val;
  void set_tot() { _total_val = _shares * _share_val; }
};

#endif
