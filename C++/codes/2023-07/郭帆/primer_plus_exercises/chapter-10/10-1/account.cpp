//
//  account.cpp
//  10-1
//
//  Created by 郭帆 on 2023/7/20.
//

#include <iostream>
#include "account.hpp"

void Account::show() const {
    std::cout << "name: " << name << std::endl;
    std::cout << "account: " << account << std::endl;
    std::cout << "balance: " << balance << std::endl;
}

void Account::deposit(double cash) {
    if (cash <= 0) {
        std::cout << "invalid value! deposit fail." << std::endl;
        return;
    }
    balance += cash;
}

void Account::withdraw(double cash) {
    if (cash <= 0 || cash > balance) {
        std::cout << "invalid value! withdraw fail." << std::endl;
        return;
    }
    balance -= cash;
}
