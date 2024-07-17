#include "10_2.h"
#include <iostream>


Person::Person(const string& ln, const char* fn)
{
	_lname = ln;
	strcpy_s(_fname, LIMIT, fn);
}

void Person::Show() const
{
	using namespace std;
	cout << "lastname: " << _lname << endl;
	cout << "firstname: " << _fname << endl;
}

void Person::FormalShow() const
{
	using namespace std;
	cout << "firstname: " << _fname << endl;
	cout << "lastname: " << _lname << endl;
}
