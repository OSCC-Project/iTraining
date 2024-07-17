#include "10_7.h"
#include <cstring>
#include <iostream>

Plorg::Plorg()
{
	strcpy_s(m_name, 20, "Plorga");
	m_CI = 50;
}

Plorg::Plorg(const char name[])
{
	strcpy_s(m_name, 20, name);
	m_CI = 50;
}

Plorg::~Plorg()
{
}

void Plorg::resetCI(int CI)
{
	m_CI = CI;
}

void Plorg::showPlorg() const
{
	using namespace std;
	cout << "name: " << m_name << endl;
	cout << "CI: " << m_CI << endl;
}
