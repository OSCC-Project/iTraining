#include "12_1.h"
#include <string.h>
#include <iostream>

Cow::Cow()
{
	weight = 0.0;
	hobby = new char[20];
	strcpy_s(hobby, 20, "no hobby");
	strcpy_s(name, 20, "no name");
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	weight = wt;
	strcpy_s(name, 20, nm);
	hobby = new char[20];
	strcpy_s(hobby, 20, ho);
}

Cow::Cow(const Cow& c)
{
	weight = c.weight;
	strcpy_s(name, 20, c.name);
	hobby = new char[20];
	strcpy_s(hobby, 20, c.hobby);
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c) {
		return *this;	//如果是自我复制，将返回
	}
	Cow t;
	t.weight = c.weight;
	strcpy_s(t.name, 20, c.name);
	t.hobby = new char[20];
	strcpy_s(t.hobby, 20, t.hobby);
	return t;
}

void Cow::ShowCow() const
{
	using namespace std;
	cout << "name: " << name << endl;
	cout << "hobby: " << hobby << endl;
	cout << "weight: " << weight << endl;
	cout << endl;
}
