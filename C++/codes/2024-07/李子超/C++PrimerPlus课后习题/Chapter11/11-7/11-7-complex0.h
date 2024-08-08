#pragma once
#include <iostream>
using std::ostream;
using std::istream;
class complex {
private:
	double realnum;
	double imagnum;
public:
	complex() :realnum(0.0), imagnum(0.0) {};
	complex(const double& a, const double& b) :realnum(a), imagnum(b) {};
	complex operator+(const complex& c);
	complex operator-(const complex& c);
	complex operator*(const complex& c);
	complex operator*(const double& x);
	friend complex operator*(const  double& x, const complex& c);
	friend ostream& operator<<( ostream&os, const complex& c);
	friend istream& operator>>( istream&is,  complex& c);
};
