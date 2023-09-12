#include<iostream>
#include<string>
#include"golf.h"
#include"sale.h"
#include"stack.h"
#include"move.h"
#include"plorg.h"
using namespace std;

// 第十章
// 10.1：实现类定义方法
class bank_account {
private:
	string name;
	string account;
	double deposit;
public:
	bank_account(string m_name, string m_account, double m_deposit) {
		name = m_name;
		account = m_account;
		deposit = m_deposit;
	}

	const void show() {
		cout << "姓名：" << name << endl;
		cout << "账号：" << account << endl;
		cout << "余额：" << deposit << endl;
	}

	void saving(double money) {
		deposit += money;
		cout << "存入" << money << "金额！" << endl;
		cout << "当前账号余额：" << deposit << endl;
	}

	void fetch(double money) {
		deposit -= money;
		cout << "取出" << money << "金额！" << endl;
		cout << "当前账号余额：" << deposit << endl;
	}
};

void controller10_1() {
	bank_account ba{ "Talor Swift", "1989", 20000 };
	ba.show();
	ba.saving(200);
	ba.fetch(1989);
}

// 10.2：构造函数的使用
class Person {
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	// #1
	Person() {
		lname = "";
		fname[0] = '\0';
	}

	// #2
	Person(const string& ln, const char* fn = "Heyyou") {
		lname = ln;
		strcpy_s(fname, fn);
	}

	void Show()const {
		cout << "firstname:" << fname << endl;
		cout << "lastname:" << lname << endl;
	}

	void FormalShow()const {
		cout << "lastname:" << lname << endl;
		cout << "firstname:" << fname << endl;
	}
};

void controller10_2() {
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	cout << endl;
	one.FormalShow();
	cout << endl;
	two.Show();
	cout << endl;
	two.FormalShow();
	cout << endl;
	three.Show();
	cout << endl;
	three.FormalShow();
}

// 10.3：修改9.1代码，使用类来实现
void controller10_3() {
	// 填充数组
	using namespace std;
	golf ann("Ann Birdfree", 24);
	ann.showgolf();
	golf g[3];
	int i = 0;
	while ((i < 3))
	{
		g[i].showgolf();
		i++;

	}
	golf leo("Leonardo Liu", 28);
	leo.set_handicap(1);
	leo.showgolf();
}

// 10.4：修改9.4代码，使用类来实现
void controller10_4() {
	Sales sale1;
	sale1.showSales();
	double sales[4] = { 2.2, 3.2, 2.5, 5.3 };
	Sales sale2(sales, 4);
	sale2.showSales();
}

// 10.5：向栈中添加和删除customer结构
void controller10_5() {
	Stack st;
	st.add_customer();
	st.delete_customer();
}

// 10.6：为函数声明提供定义和测试程序
void controller10_6() {
	Move move(10, 10);
	move.showmove();
	Move temp = move.add(Move(1, 1));
	temp.showmove();

	move.reset(5, 5);
	move.showmove();
}

// 10.7
void controller10_7() {
	Plorg plg(20);
	plg.show();

	plg.change_CI(50);
	plg.show();

}

int main() {
	//controller10_1();
	//controller10_2();
	//controller10_3();
	//controller10_4();
	//controller10_5();
	//controller10_6();
	controller10_7();
	system("PAUSE");
	return 0;
}