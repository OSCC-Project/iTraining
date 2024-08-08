#include<iostream>
#include "10_3.h"
#include<cstring>

Golf::Golf()
{
	using namespace std;
	cout << "Please input fullname: ";
	cin.getline(_fullname, Len);
	cout << "Please input handicap: ";
	cin >> _handicap;
}

Golf::Golf(const char fn[], int hd)
{
	strcpy_s(_fullname, Len, fn);
	_handicap = hd;
}

Golf::~Golf()
{
}

void Golf::resetHandicap(int hc)
{
	_handicap = hc;
}

void Golf::showGolf()
{
	using namespace std;
	cout << "fullname: " << _fullname << endl;
	cout << "handicap: " << _handicap << endl;
}
