#pragma once

#include<iostream>
#include<cstring>

class Port{
public:
    Port(const char*br="none", const char* st="none", int b=0);
    Port(const Port& p);
    virtual ~Port(){delete[] brand;}
    Port& operator=(const Port& p);
    Port& operator+(int b);
    Port& operator-(int b);
    int BottleCount() const { return bottles; }
    virtual void show() const;
    friend std::ostream& operator<<(std::ostream& os, const Port& p);
protected:
    char* brand;
    char style[20];
    int bottles;
};