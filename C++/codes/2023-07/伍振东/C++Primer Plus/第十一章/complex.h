#pragma once
#ifndef COMPLEX_H_
#define COMPLEX_H_
#include<iostream>

class complex {
private:
	double rn;
	double vn;
public:
	complex();
	complex(double n1, double n2);
	complex operator~();
	friend complex operator+(const complex& c1, const complex& c3);
	friend complex operator-(const complex& c1, const complex& c3);
	friend complex operator*(const complex& c1, const complex& c3);
	friend complex operator*(const complex& c, const double d);
	friend complex operator*(const double d, const complex& c);
	friend std::ostream& operator<<(std::ostream& os, const complex& c);
	friend std::istream& operator>>(std::istream& is, complex& c);
};
#endif // !COMPLEX_H_
