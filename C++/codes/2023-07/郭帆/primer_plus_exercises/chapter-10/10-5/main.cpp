//
//  main.cpp
//  10-5
//
//  Created by 郭帆 on 2023/7/20.
//

#include <iostream>
#include <string>
#include "stack.hpp"

using namespace std;

struct customer {
    char fullname[35];
    double payment;
    customer(string s = "", double n = 0.0);
};

customer::customer(string s, double n) {
    strcpy(fullname, s.c_str());
    payment = n;
}

int main(int argc, const char * argv[]) {
    Stack<customer> s;
    double total = 0.0;
    
    for (int i = 0; i < 5; i++) {
        s.push(customer(to_string(i), i));
    }
    
    customer c;
    for (int i = 0; i < 5; i++) {
        s.pop(c);
        total += c.payment;
        cout << "total: " << total << endl;
    }
    
    return 0;
}
