//
//  main.cpp
//  10-1
//
//  Created by 郭帆 on 2023/7/20.
//

#include <iostream>
#include "account.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Account temp("GuoFan", "1002", 666);

    cout << "Information of depositors:" << endl;
    temp.show();
    cout << "\nDeposit -1 dollar:" << endl;
    temp.deposit(-1);
    cout << "\nDeposit 100 dollars:" << endl;
    temp.deposit(100);
    cout << "\nWithdraw 6666 dollars:" << endl;
    temp.withdraw(6666);
    cout << "\nWithdraw 99 dollars:" << endl;
    temp.withdraw(99);
    cout << "\nNow information of depositors:" << endl;
    temp.show();
    cout << "Bye." << endl;
    
    return 0;
}
