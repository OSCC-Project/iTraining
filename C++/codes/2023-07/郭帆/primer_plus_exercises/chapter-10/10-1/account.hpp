//
//  account.hpp
//  10-1
//
//  Created by 郭帆 on 2023/7/20.
//

#ifndef account_hpp
#define account_hpp

#include <string>

class Account {
private:
    std::string name;
    std::string account;
    double balance;
public:
    Account() = default;
    Account(const std::string &n, const std::string &a, double b = 0.0) : name(n), account(a), balance(b) {};
    void show() const;
    void deposit(double cash);
    void withdraw(double cash);
};

#endif /* account_hpp */
