#ifndef BANK_H_
#define BANK_H_
#include <string>

class Bank {
private:
  std::string name;
  std::string ID;
  double deposit;

public:
  Bank();
  Bank(const std::string &name, const std::string &ID, double deposit = 0.0);
  ~Bank();
  void showBank();
  void inputMoney(double money);
  void outputMoney(double money);
};

#endif