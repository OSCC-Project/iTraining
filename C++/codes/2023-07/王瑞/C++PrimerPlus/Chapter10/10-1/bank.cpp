#include "bank.h"
#include <iostream>
#include <string>

Bank::Bank() {
  name = "no name";
  ID = "no ID";
  deposit = 0.0;
}

Bank::Bank(const std::string &name_, const std::string &ID_, double deposit_) {
  name = name_;
  ID = ID_;
  deposit = deposit_;
}

Bank::~Bank() {}

void Bank::showBank() {
  std::cout << "the bank's messages are as follows: " << std::endl;
  std::cout << "the bank's name is: " << name << std::endl;
  std::cout << "the bank's ID is: " << ID << std::endl;
  std::cout << "the bank's deposit is: " << deposit << std::endl;
}

void Bank::inputMoney(double money) {
  if (money <= 0) {
    std::cout << "Your deposit amount can't be less than 0!" << std::endl;
  } else {
    deposit += money;
    std::cout << "Your deposit $" << money << " successfully." << std::endl;
  }
}

void Bank::outputMoney(double money) {
  if (money > deposit) {
    std::cout << "insufficient saving.\n";
  } else {
    deposit -= money;
    std::cout << "Your withdraw $" << money << " successfully." << std::endl;
  }
}