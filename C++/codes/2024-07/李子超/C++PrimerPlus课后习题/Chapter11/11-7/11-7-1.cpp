#include <iostream>
#include "11-7-complex0.h"
using std::cin;
using std::cout;
using std::endl;
complex complex::operator+(const complex& c) {
	return complex(this->realnum+c.realnum, this->imagnum+c.imagnum);
}
complex complex::operator-(const complex& c) {
	return complex(this->realnum - c.realnum, this->imagnum - c.imagnum);
}
complex complex::operator*(const complex& c) {
	double a = this->realnum*c.realnum - this->imagnum*c.imagnum;
	double b = this->realnum*c.imagnum + this->imagnum*c.realnum;
	return complex(a, b);
}
complex complex::operator*(const double& x) {
	return complex(this->realnum*x, this->imagnum*x);
}

complex operator*( const double& x, const complex& c) {
	return complex(x*c.realnum, x*c.imagnum);
}
ostream& operator<<(ostream& os, const complex& c) {
	os << c.realnum << "+" << c.imagnum << "i" << endl;
	return os;
}

istream& operator>>(istream& is,  complex& c) {
	cout << "read:";
	is >> c.realnum;
	cout << "imaginary:";
	is>> c.imagnum;
	return is;
}