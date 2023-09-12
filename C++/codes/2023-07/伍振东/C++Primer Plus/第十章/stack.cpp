#include"stack.h"
#include<iostream>
#include<string>
using namespace std;

// 初始化数据
Stack::Stack() {
	top = 0;
	payments = 0;
}

void Stack::add_customer() {
	if (top == 10) {
		cout << "当前栈已满，无法添加顾客!" << endl;
		return;
	}
	cout << "输入顾客的姓名：";
	cin >> item[top].fullname;
	cout << "输入顾客的消费金额：";
	cin >> item[top].payment;
	top += 1;
}

void Stack::delete_customer() {
	if (top == 0) {
		cout << "当前顾客人数为空，无法删除顾客！" << endl;
		return;
	}
	top -= 1;
	payments += item[top].payment;
	cout << "顾客" << item[top].fullname << "消费完毕！" << endl;
	cout << "当前消费总额为：" << payments << endl;
}
