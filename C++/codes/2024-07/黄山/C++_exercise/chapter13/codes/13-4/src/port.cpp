#include"port.h"

Port::Port(const char* br, const char* st, int b):bottles(b){
    this->brand = new char(strlen(br) + 1);
    strcpy(this->brand, br);
    strcpy(this->style, st);
}

Port::Port(const Port& p){
    strcpy(this->brand, p.brand);
    strcpy(this->style, p.style);
    this->bottles = p.bottles;
}
// virtual ~Port(){delete[] rand;}
Port& Port::operator=(const Port& p){
    strcpy(this->brand, p.brand);
    strcpy(this->style, p.style);
    this->bottles = p.bottles;
    return *this;
}

Port& Port::operator+(int b){
    this->bottles += b;
    return *this;
}

Port& Port::operator-(int b){
    this->bottles -= b;
    return *this;
}
// int BottleCount() const{return bottles};
void Port::show() const{
    std::cout << "Brand: "<<this->brand <<std::endl;
    std::cout<<"Kind: "<<this->style<<std::endl;
    std::cout<<"Bottles: "<<this->bottles<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const Port& p){
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}