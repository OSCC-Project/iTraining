#include "CD.h"
#include <string.h>
#include<iostream>

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	performers = new char[len1 + 1];
	label = new char[len2 + 1];
	strcpy_s(performers, len1 + 1, s1);
	strcpy_s(label, len2 + 1, s2);
	performers[len1] = '\0';
	label[len2] = '\0';

	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	int len1 = strlen(d.performers);
	int len2 = strlen(d.label);

	performers = new char[len1 + 1];
	label = new char[len2 + 1];
	strcpy_s(performers, len1 + 1, d.performers);
	strcpy_s(label, len2 + 1, d.label);
	performers[len1] = '\0';
	label[len2] = '\0';

	selections = d.selections;
	playtime = d.playtime;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
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
	delete[] performers;
	delete[] label;

	int len1 = strlen(d.performers);
	int len2 = strlen(d.label);

	performers = new char[len1 + 1];
	label = new char[len2 + 1];
	strcpy_s(performers, len1 + 1, d.performers);
	strcpy_s(label, len2 + 1, d.label);
	performers[len1] = '\0';
	label[len2] = '\0';

	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char* s, const char* s1, const char* s2, int n, double x) :Cd(s1, s2, n, x)
{
	int len = strlen(s);
	song = new char[len + 1];
	strcpy_s(song, len + 1, s);
	song[len] = '\0';
}

Classic::~Classic()
{
	delete[] song;
}

void Classic::Report() const
{
	using namespace std;
	Cd::Report();
	cout << "song: " << song << endl;
}

Classic& Classic::operator=(const Classic& c)
{
	if (this == &c) {
		return *this;
	}
	Cd::operator=(c);
	delete[] song;
	int len = strlen(c.song);
	song = new char[len + 1];
	strcpy_s(song, len + 1, c.song);
	song[len] = '\0';

	return *this;
}
