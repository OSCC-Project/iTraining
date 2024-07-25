#pragma once

#include<iostream>
// #include<fstream>

class complex{
private:
    double m_real;
    double m_imag;
public:
    complex();
    complex(double real, double imag);
    complex operator+(const complex& other);
    complex operator-(const complex& other);
    complex operator*(const complex& other);
    friend complex operator*(double a, complex& other);
    complex operator~();

    friend std::istream& operator>>(std::istream& is, complex& comp);
    friend std::ostream& operator<<(std::ostream& os, const complex& comp);
};