#include"Port.h"

Port::Port(const Port &p)
{
    this->brand = new char[strlen(p.brand)+1];
    strcpy(this->brand,p.brand);
    strcpy(this->style,p.style);
    this->bottles = p.bottles;
}

Port::Port(const char *br,const char *st,int b)
{
    this->brand = new char(strlen(br)+1);
    strcpy(this->brand,br);
    strcpy(this->style,st);
    this->bottles = b;
}

Port::~Port()
{
    delete []brand;
}

Port & Port::operator=(const Port &p)
{
    if(this == &p){return *this;}
    this->brand = new char[strlen(p.brand)+1];
    strcpy(this->brand,p.brand);
    strcpy(this->style,p.style);
    this->bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    this->bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    this->bottles -= b;
    return *this;
}

void Port::Show()const{
    cout<<"Brand: "<<this->brand<<endl;
    cout<<"Kind: "<<this->style<<endl;
    cout<<"Bottles: "<<this->bottles<<endl;
}

ostream& operator<<(ostream& os,const Port& p)
{
    os<<p.brand<<","<<p.style<<","<<p.bottles<<endl;
    return os;
}