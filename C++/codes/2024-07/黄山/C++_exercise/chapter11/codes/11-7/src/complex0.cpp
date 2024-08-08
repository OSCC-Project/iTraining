#include"complex0.h"

complex::complex(){
    this->m_real = 0;
    this->m_imag = 0;
}
complex::complex(double real, double imag){
    this->m_real = real;
    this->m_imag = imag;
}
complex complex::operator+(const complex& other){
    complex comp;
    comp.m_real = this->m_real + other.m_real;
    comp.m_imag = this->m_imag + other.m_imag;
    return comp;
}
complex complex::operator-(const complex& other){
    complex comp;
    comp.m_real = this->m_real - other.m_real;
    comp.m_imag = this->m_imag - other.m_imag;
    return comp;
}
complex complex::operator*(const complex& other){
    complex comp;
    comp.m_real = this->m_real * other.m_real - this->m_imag * other.m_imag;
    comp.m_imag = this->m_real * other.m_imag + this->m_imag * other.m_real;
    return comp;
}
complex operator*(double a, complex& other){
    complex comp;
    comp.m_real = a*other.m_real;
    comp.m_imag = a*other.m_imag;
    return comp;
}
complex complex::operator~(){
    complex comp;
    comp.m_real = this->m_real;
    comp.m_imag = -this->m_imag;
    return comp;
}

std::istream& operator>>(std::istream& is, complex& comp){
    // if(is.peek() == 'q') return false;
    // else{
    //     is >> comp.m_real >> comp.m_imag;
    // }
    // return true;
    std::cout << "real: ";
    is >> comp.m_real;
    std::cout << "imaginary: ";
    is >> comp.m_imag;
    return is;
}
std::ostream& operator<<(std::ostream& os, const complex& comp){
    os << "(" << comp.m_real << ","<<comp.m_imag<<"i)";
    return os;
}