#include "port.h"
#include <iostream>
#include <cstring>
using namespace std;
Port::Port()
{
    brand=new char[1];
    brand[0]='\0';
    style[0]='\0';
    bottles=0;
}
Port::Port(const char *br, const char *st, int b)
{
    brand=new char[strlen(br)+1];
    strcpy(brand,br);
    strcpy(style,st);
    bottles=b;
}

Port::Port(const Port &p)
{   
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
}

Port &Port::operator=(const Port &p)
{
    if(this==&p)
        return *this;
    delete []brand;
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
    return *this;
}

Port &Port::operator+=(int b)
{
    bottles+=b;
    return *this;
}

Port &Port::operator-=(int b)
{
    bottles-=b;
    return *this;
}

void Port::Show() const
{
    cout<<"Brand:"<<brand<<endl;
    cout<<"Kind:"<<style<<endl;
    cout<<"Bottles:"<<bottles<<endl;
}

ostream &operator<<(ostream &os, const Port &p)
{
    os<<p.brand<<","<<p.style<<","<<p.bottles;
    return os;
}

ostream &operator<<(ostream &os, const VintagePort &vp)
{
    operator<<(os,(const Port&)vp);
    os<<vp.nickname<<vp.year;
    return os;
}

VintagePort::VintagePort():Port()
{
    nickname=new char[1];
    nickname[0]='\0';
    year=0;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y):Port(br,"null",b)
{
    nickname=new char[strlen(nn)+1];
    strcpy(nickname,nn);
    year=y;
}

VintagePort::VintagePort(const VintagePort &vp):Port(vp)
{
    nickname=new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    year=vp.year;
}

void VintagePort::Show() const
{
    Port::Show();
    cout<<"nickname:"<<nickname<<endl;
    cout<<"year:"<<year<<endl;
}
