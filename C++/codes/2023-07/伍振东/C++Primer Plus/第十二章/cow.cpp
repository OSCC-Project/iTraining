#include"cow.h"
#include<iostream>

Cow::Cow() {
	strcpy_s(name, "\0");
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt) {
	weight = wt;
	strcpy_s(name, 20, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, strlen(ho) + 1, ho);
}

Cow::Cow(const Cow& c) {
	weight = c.weight;
	strcpy_s(name, 20, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
}

Cow::~Cow() {
	std::cout << "析构函数\n";
	delete hobby;
}

// 赋值构造函数
Cow& Cow::operator=(const Cow& c) {
	if (this == &c) {
		return *this;
	}
	weight = c.weight;
	strcpy_s(name, 20, c.name);
	delete hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	return *this;
}

void Cow::ShowCow()const {
	std::cout << "name:" << name << std::endl;
	std::cout << "hobby:" << hobby << "\n";
	std::cout << "weight:" << weight << '\n';
}