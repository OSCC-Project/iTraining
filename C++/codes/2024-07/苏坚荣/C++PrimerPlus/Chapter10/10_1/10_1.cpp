#include "10_1.h"
#include<cstring>
#include <iostream>

Account::Account()
{
	strcpy_s(_name, LEN, "no name");
	strcpy_s(_number, LEN, "no number");
	_money = 0.0;
}

Account::Account(const char name[], const char number[], double money)
{
	strcpy_s(_name, LEN, name);
	strcpy_s(_number, LEN, number);
	_money = money;
}

Account::~Account()
{
}

void Account::pushMoney(double money)
{
	using namespace std;
	cout << _name << "的账户存入" << money << "元" << endl;
	_money += money;
}

void Account::pullMoney(double money)
{
	using namespace std;
	cout << _name << "的账户取出" << money << "元" << endl;
	_money -= money;
}

void Account::showAccount()
{
	using namespace std;
	cout << "姓名：" << _name << endl;
	cout << "账户：" << _number << endl;
	cout << "余额：" << _money << endl;
	cout << endl;
}
