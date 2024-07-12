#include<iostream>
using namespace std;

int Fill_array(double a[], int s);
void Show_array(double a[], int s);
void Reverse_array(double a[], int s);

int main() {
	int size;
	cout << "输入数组的长度：";
	cin >> size;
	double* arr = new double[size];
	int cnt = Fill_array(arr, size);
	cout << "实际输入了" << cnt << "个数" << endl;
	Show_array(arr, cnt);
	Reverse_array(arr, cnt);
	cout << "反转数组：" << endl;
	Show_array(arr, cnt);
	return 0;
}

int Fill_array(double a[], int s) {
	int len = 0;
	double t;
	cout << "请输入数字：";
	while (s--) {
		if (cin >> t) {
			a[len++] = t;
		}
		else
			break;
	}

	return len;
}

void Show_array(double a[], int s) {
	for (int i = 0; i < s; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void Reverse_array(double a[], int s) {
	if (s % 2 == 0) {
		int k = (s - 2) / 2;
		for (int i = 1; i <= k; i++) {
			double temp = a[i];
			a[i] = a[s - 1 - i];
			a[s - 1 - i] = temp;
		}
	}
	else {
		int k = s / 2;
		for (int i = 1; i < k; i++) {
			double temp = a[i];
			a[i] = a[s - 1 - i];
			a[s - 1 - i] = temp;
		}
	}
}
