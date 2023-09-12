//
//  main.cpp
//  10-7
//
//  Created by 郭帆 on 2023/7/20.
//

#include <iostream>
#include "plorg.h"

int main(int argc, const char * argv[]) {
    Plorg one;
    Plorg two("hello");
    Plorg three("world", 1);
    
    one.show();
    two.show();
    three.show();
    
    one.setCI(20);
    one.show();
    
    return 0;
}
