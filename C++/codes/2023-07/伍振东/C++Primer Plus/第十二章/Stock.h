#pragma once
#ifndef STOCK_H_
#define STOCK_H_

class Stock{
private:
	char* _company;
	int _shares;
	double _share_val;
	double _total_val;
	void setTot() { _total_val = _shares * _share_val; }
public:
	Stock();
	Stock(const char* st, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock& topVal(const Stock& s)const;
	friend std::ostream& operator<<(std::ostream& os, const Stock& st);
};
#endif  //STOCK_H_