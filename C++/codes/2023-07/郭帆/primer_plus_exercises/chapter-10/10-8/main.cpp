//
//  main.cpp
//  10-8
//
//  Created by 郭帆 on 2023/7/20.
//

#include <iostream>
#include "list.h"

using namespace std;

void print_int(int &n) {
    cout << n << endl;
}

int main(int argc, const char * argv[]) {
    List<int> l;
    
    cout << "empty? " << l.isempty() << endl;
    
    for (int i = 0; i < 5; i++) {
        l.push_back(i);
    }
    cout << "empty? " << l.isempty() << endl;
    
    l.visit(print_int);
    
    cout << "full? " << l.isfull() << endl;
    
    for (int i = 0; i < 100; i++) {
        l.push_back(i);
    }
    cout << "full? " << l.isfull() << endl;
    
    l.visit(print_int);
    
    return 0;
}
