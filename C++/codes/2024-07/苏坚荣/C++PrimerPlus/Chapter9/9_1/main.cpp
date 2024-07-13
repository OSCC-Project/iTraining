#include<iostream>
#include"golf.h"

int main() {
	using namespace std;
	Golf ann;
	setGolf(ann, "Ann Birdfree", 24);
	Golf arr[3];
	int k;
	for (k = 0; k < 3; k++) {
		if (setGolf(arr[k]) == 0) {
			break;
		}
	}
	cout << "以下是全部用户信息" << endl;
	for (int i = 0; i < k; i++) {
		showGolf(arr[i]);
	}

	cout << "请选择要重设等级的用户：";
	int j, hc;
	cin >> j;
	cout << "请输入新等级：";
	cin >> hc;
	handicap(arr[j - 1], hc);

	cout << "以下是全部用户信息" << endl;
	for (int i = 0; i < k; i++) {
		showGolf(arr[i]);
	}
	return 0;
}