#include<iostream>

#include"Stock.h"

Stock::Stock() {
	_company = new char[1];
	_company[0] = '\0';
	_shares = 0;
	_share_val = 0.0;
	setTot();
}

Stock::Stock(const char* st, long n, double pr){
	_company = new char[strlen(st) + 1];
	_shares = n;
	_share_val = pr;
	setTot();
	strcpy_s(_company, strlen(st) + 1, st);
}

Stock::~Stock() {
	delete[]_company;
}

void Stock::buy(long num, double price) {
	_shares += num;
	_share_val = price;
	setTot();
}

void Stock::sell(long num, double price) {
	_shares -= num;
	_share_val = price;
	setTot();
}

void Stock::update(double price) {
	_share_val = price;
	setTot();
}

std::ostream& operator<<(std::ostream& os, const Stock& st) {
	os << "Company:" << st._company << "Shares:" << st._shares << '\n';
	os << " Share Price:$" << st._share_val << '\n';
	os << "Total val:" << st._total_val << '\n';
	return os;
}

const Stock& Stock::topVal(const Stock& s)const {
	if (s._total_val > _total_val)return s;
	return *this;
}

