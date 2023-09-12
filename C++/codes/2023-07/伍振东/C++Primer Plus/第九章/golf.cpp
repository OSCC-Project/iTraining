// 9.1函数实现文件
#include<iostream>
#include<string>
#include"golf.h"

void setgolf(golf& g, const char* name, int hc) {
	strcpy_s(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g) {
	using namespace std;
	cout << "输入用户的姓名：";
	cin >> g.fullname;
	if (strcmp(g.fullname, "") == 0) {
		return 0;
	}
	cout << "输入用户的等级：";
	cin >> g.handicap;
	return 1;
}

void handicap(golf& g, int hc) {
	g.handicap = hc;
}

void showgolf(const golf& g) {
	using namespace std;
	cout << "用户姓名：" << g.fullname << endl;
	cout << "用户等级：" << g.handicap << endl;
}