#include <iostream>

//模板函数
template<typename T> T getMaxnumber(T a[]);

int main() {
	int arr1[5] = { 1,2,3,4,5 };
	double arr2[5] = { 1.2,4.2,0.3,5.6,2.3 };
	std::cout << "第一个数组中最大的数为：" << getMaxnumber(arr1) << "\n";
	std::cout << "第二个数组中最大的数为：" << getMaxnumber(arr2) << "\n";

	return 0;
}

template<typename T> T getMaxnumber(T a[]) {
	T maxNumber = a[0];
	for (int i = 1; i < 5; i++) {
		if (a[i] > maxNumber) {
			maxNumber = a[i];
		}
	}
	return maxNumber;
}
