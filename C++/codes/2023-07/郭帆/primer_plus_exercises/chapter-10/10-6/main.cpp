//
//  main.cpp
//  10-6
//
//  Created by 郭帆 on 2023/7/20.
//

#include <iostream>
#include "move.hpp"

int main(int argc, const char * argv[]) {
    Move m;
    
    m.showmove();
    m = m.add(Move(10, 5));
    m.showmove();
    m = m.add(Move(-2, 3));
    m.showmove();
    m.reset();
    m.showmove();
    m.reset(1, 1);
    m.showmove();
    
    return 0;
}
