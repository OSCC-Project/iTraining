//
//  main.cpp
//  10-2
//
//  Created by 郭帆 on 2023/7/20.
//

#include <iostream>
#include "person.hpp"

int main(int argc, const char * argv[]) {
    using std::cout;
    using std::endl;

    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    
    one.Show();
    cout << endl;
    one.FormalShow();
    
    two.Show();
    cout << endl;
    two.FormalShow();
    
    three.Show();
    cout << endl;
    three.FormalShow();
    
    return 0;
}
