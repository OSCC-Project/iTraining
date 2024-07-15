#pragma once
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

const int LEN = 40;

class Account {
private:
	char _name[LEN];	//姓名
	char _number[LEN];	//账号
	double _money;		//存款
public:
	Account();	//默认构造函数
	Account(const char name[], const char number[], double money);	//构造函数
	~Account();	//析构函数
	void pushMoney(double money);	//存款
	void pullMoney(double money);	//取款
	void showAccount();
};


#endif