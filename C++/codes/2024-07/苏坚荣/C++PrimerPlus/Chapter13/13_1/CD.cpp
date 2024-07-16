#include "CD.h"
#include <string.h>
#include<iostream>

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strcpy_s(performers, 50, s1);
	strcpy_s(label, 20, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strcpy_s(performers, 50, d.performers);
	strcpy_s(label, 20, d.label);
	selections = d.selections;
	playtime = d.playtime;
}


void Cd::Report() const
{
	using namespace std;
	cout << "performers: " << performers << endl;
	cout << "label: " << label << endl;
	cout << "selections: " << selections << endl;
	cout << "playtime: " << playtime << endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d) {
		return *this;
	}
	strcpy_s(performers, 50, d.performers);
	strcpy_s(label, 20, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Classic::Classic(const char* s, const char* s1, const char* s2, int n, double x) :Cd(s1, s2, n, x)
{
	strcpy_s(song, 50, s);
}

void Classic::Report() const
{
	using namespace std;
	Cd::Report();
	cout << "song: " << song << endl;
}
