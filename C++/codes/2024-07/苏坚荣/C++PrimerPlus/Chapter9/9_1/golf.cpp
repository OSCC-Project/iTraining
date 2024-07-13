#include "golf.h"
#include<cstring>

void setGolf(Golf& g, const char* name, int hc)
{
	strcpy_s(g._fullname, Len, name);
	g._handicap = hc;
}

int setGolf(Golf& g)
{
	using namespace std;
	char fullname[Len];
	int handicap;
	cout << "请输入用户的姓名：";
	cin.getline(fullname, Len);
	if (fullname[0] == '\0') {
		return 0;
	}

	strcpy_s(g._fullname, Len, fullname);
	cout << "请输入用户的等级：";
	cin >> handicap;
	g._handicap = handicap;
	cin.get();
	return 1;
}

void handicap(Golf& g, int hc)
{
	g._handicap = hc;
}

void showGolf(const Golf& g)
{
	using namespace std;
	cout << "用户的姓名为：" << g._fullname << "，等级为：" << g._handicap << endl;
}
