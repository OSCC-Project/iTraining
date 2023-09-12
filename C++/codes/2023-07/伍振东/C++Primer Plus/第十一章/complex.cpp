#include"complex.h"
#include<iostream>

complex::complex() {
	rn = 0.0;
	vn = 0.0;
}

complex::complex(double n1, double n2) {
	rn = n1;
	vn = n2;
}

complex complex::operator~() {
	complex temp;
	temp.rn = rn;
	temp.vn = -vn;
	return temp;
}

complex operator+(const complex& c1, const complex& c2) {
	return complex(c1.rn + c2.rn, c1.vn + c2.vn);
}

complex operator-(const complex& c1, const complex& c2) {
	return complex(c1.rn - c2.rn, c1.vn - c2.vn);
}

complex operator*(const complex& c1, const complex& c2) {
	return complex(c1.rn * c2.rn - c1.vn * c2.vn, c1.rn * c2.vn + c1.vn * c2.rn);
}


complex operator*(const complex& c, const double d) {
	return complex(c.rn * d, c.vn * d);
}

complex operator*(const double d, const complex& c) {
	return complex(c.rn * d, c.vn * d);
}

std::ostream& operator<<(std::ostream& os, const complex& c) {
	os << "(" << c.rn << "," << c.vn << "i)";
	return os;
}

std::istream& operator>>(std::istream& is, complex& c) {
	is >> c.rn >> c.vn;
	return is;
}