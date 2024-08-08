#include<iostream>
using namespace std;

int Jiecheng(int x);

int main() {
	int n;
	while (1) {
		cout << "请输入一个数：";
		cin >> n;
		cout << n << "的阶乘为：" << Jiecheng(n) << endl;
	}

	return 0;
}

int Jiecheng(int x) {
	if (x == 0)
		return 1;
	return x * Jiecheng(x - 1);

}