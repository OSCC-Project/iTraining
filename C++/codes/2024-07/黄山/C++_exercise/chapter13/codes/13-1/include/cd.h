#pragma once

#include<iostream>
#include<cstring>

class Cd{
public:
    Cd(char* s1, char* s2, int n, double x);
    Cd(const Cd& d);
    Cd();
    virtual void Report() const;
    virtual Cd& operator=(const Cd& d);
protected:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
};