//
//  plorg.h
//  cpppp
//
//  Created by 郭帆 on 2023/7/20.
//

#ifndef plorg_h
#define plorg_h

#include <iostream>

class Plorg {
private:
    char name[20];
    int CI;
public:
    Plorg(const char *n, int c = 50) {
        strcpy(name, n);
        CI = c;
    }
    Plorg() {
        *this = Plorg("Plorga");
    }
    
    void setCI(int c) { CI = c; }
    void show() const { std::cout << "name: " << name << ", CI: " << CI << std::endl; }
};

#endif /* plorg_h */
