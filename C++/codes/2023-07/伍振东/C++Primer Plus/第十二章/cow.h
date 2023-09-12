#pragma once
#ifndef COW_H_
#define COW_H_
#include<string>

class Cow {
private:
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow& c);
	~Cow();
	Cow& operator=(const Cow& c);
	void ShowCow()const;
};

#endif // COW_H_
