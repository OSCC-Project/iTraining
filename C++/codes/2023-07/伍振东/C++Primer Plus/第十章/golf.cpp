// 9.1函数实现文件
#include<iostream>
#include<string>
#include"golf.h"

golf::golf(const char* name, int hc) {
	strcpy_s(fullname, name);
	handicap = hc;
}

golf::golf() {
	using namespace std;
	cout << "输入用户的姓名：";
	cin >> fullname;
	cout << "输入用户的等级：";
	cin >> handicap;
}

void golf::set_handicap(int hc) {
	handicap = hc;
}

void golf::showgolf() {
	using namespace std;
	cout << "用户姓名：" << fullname << endl;
	cout << "用户等级：" << handicap << endl;
}