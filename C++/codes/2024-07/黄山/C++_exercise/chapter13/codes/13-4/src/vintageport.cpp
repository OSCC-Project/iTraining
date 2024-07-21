#include"vintageport.h"

VintagePort::VintagePort():Port::Port(){
    this->year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char * nn, int y):Port::Port(br, "vintage", b){
    this->nickname = new char(strlen(nn) + 1);
    strcpy(this->nickname, nn);
    this->year = y;
}

VintagePort::VintagePort(const VintagePort& vp):Port::Port(vp){
    strcpy(this->nickname, vp.nickname);
    this->year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp){
    Port::operator=(vp);
    strcpy(this->nickname, vp.nickname);
    this->year = vp.year;
    return *this;
}
void VintagePort::show() const{
    Port::show();
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout<<"Year: "<<this->year<<std::endl;
}
std::ostream& operator<<(std::ostream& os, const VintagePort& vp){
    // operator<<(os, vp);
    os << vp.brand << ", " << vp.style << ", " << vp.bottles;
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}