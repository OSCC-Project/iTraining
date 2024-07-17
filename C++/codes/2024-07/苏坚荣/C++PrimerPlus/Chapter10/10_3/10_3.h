#pragma once
#include<iostream>

const int Len = 40;
class Golf
{
private:
	char _fullname[Len];
	int _handicap;

public:
	Golf();
	Golf(const char fn[], int hd);
	~Golf();
	void resetHandicap(int hc);
	void showGolf();
};
