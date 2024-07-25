#ifndef PORT_H
#define PORT_H

#include<iostream>
#include<cstring>
#include<ostream>

using namespace std;

class Port
{
private:
    char *brand;
    char style[20];
    int bottles;
public:
    Port(const char *br="none",const char *st="none",int b=0);
    Port(const Port &p);
    virtual ~Port();
    Port & operator=(const Port &p);
    Port & operator+=(int b);    //add b to bottles
    Port & operator-=(int b);    //subtracts b from bottles
    int BottleCount() const ;
    virtual void Show() const;
    friend ostream &operator<<(ostream &os,const Port &p);
};

#endif