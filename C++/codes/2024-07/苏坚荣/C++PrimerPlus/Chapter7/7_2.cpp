#include<iostream>
using namespace std;

int Init(int arr[]);
void Show(int arr[], int s);
double Cal(int arr[], int s);

int main() {
	int arr[10];
	int size = Init(arr);
	Show(arr, size);
	cout << "平均成绩为：" << Cal(arr, size) << endl;
	return 0;
}

int Init(int arr[]) {
	int s = 0;
	cout << "请输入成绩：（输入-1提前结束输入）" << endl;
	for (int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;
		if (temp == -1)
			break;
		arr[i] = temp;
		s++;
	}
	return s;
}

void Show(int arr[], int s) {
	cout << "以下是高尔夫成绩：" << endl;
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

double Cal(int arr[], int s) {
	double sum = 0;
	for (int i = 0; i < s; i++) {
		sum += arr[i];
	}
	return sum / s;
}
