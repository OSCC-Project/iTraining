#include<iostream>
#include"Cd.h"

Cd::Cd() {
	_performers = new char[1];
	_performers[0] = '\0';
	_label = new char[1];
	_label[0] = '\0';
	_selections = 0;
	_playtime = 0;
}

Cd::Cd(const char* s1, const char* s2, int n, double x) {
	_performers = new char[strlen(s1) + 1];
	strcpy_s(_performers, strlen(s1) + 1, s1);
	_label = new char[strlen(s2) + 1];
	strcpy_s(_label, strlen(s2) + 1, s2);
	_selections = n;
	_playtime = x;
}

Cd::Cd(const Cd& d) {
	_performers = new char[strlen(d._performers) + 1];
	strcpy_s(_performers, strlen(d._performers) + 1, d._performers);
	_label = new char[strlen(d._label) + 1];
	strcpy_s(_label, strlen(d._label) + 1, d._label);
	_selections = d._selections;
	_playtime = d._playtime;
}

Cd::~Cd() {
	delete[]_performers;
	delete[]_label;
}

void Cd::Report() const {
	using std::cout;
	cout << "performers:" << _performers << '\n';
	cout << "label:" << _label << '\n';
	cout << "selections:" << _selections << '\n';
	cout << "playtime:" << _playtime << '\n';
}

Cd& Cd::operator=(const Cd& d) {
	if (this == &d) {
		return *this;
	}
	delete[]_performers;
	delete[]_label;
	_performers = new char[strlen(d._performers) + 1];
	strcpy_s(_performers, strlen(d._performers) + 1, d._performers);
	_label = new char[strlen(d._label) + 1];
	strcpy_s(_label, strlen(d._label) + 1, d._label);
	_selections = d._selections;
	_playtime = d._playtime;
	return *this;
}

Classic::Classic() :Cd() {
	_main_work = new char[1];
	_main_work[0] = '\0';
}

Classic::Classic(const char* s1, const char* s2, int n, double x, const char* mk) :Cd(s1, s2, n, x) {
	_main_work = new char[strlen(mk) + 1];
	strcpy_s(_main_work, strlen(mk) + 1, mk);
}

Classic::Classic(const Cd& d, const char* mk) :Cd(d) {
	_main_work = new char[strlen(mk) + 1];
	strcpy_s(_main_work, strlen(mk) + 1, mk);
}

Classic::~Classic() {
	delete[]_main_work;
}

void Classic::Report() const {
	Cd::Report();
	std::cout << "main work:" << _main_work << '\n';
}

Classic& Classic::operator=(const Classic& cl) {
	if (this == &cl) {
		return *this;
	}
	Cd::operator=(cl);
	delete[]_main_work;
	_main_work = new char[strlen(cl._main_work) + 1];
	strcpy_s(_main_work, strlen(cl._main_work) + 1, cl._main_work);
	return *this;
}