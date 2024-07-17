#include <iostream>
#include<cstring>

//模板函数，返回数组中最大的数
template<typename T>
T maxn(T a[], int n) {
	T maxNum = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > maxNum) {
			maxNum = a[i];
		}
	}
	return maxNum;
}

//模板具体化函数，返回最长字符串的地址
template<>
const char* maxn<const char*>(const char* a[], int n) {
	const char* longest = a[0];
	for (int i = 1; i < n; i++) {
		if (strlen(longest) < strlen(a[i])) {
			longest = a[i];
		}
	}
	return longest;
}


int main()
{
	int arr1[4] = { 3, 10, 4, 9 };
	double arr2[6] = { 0.1,0.2,0.3,0.4,0.5,0.6 };
	const char* arr3[] = { "Hello","World","C++","Programming" };
	std::cout << "第一个数组最大的数是：" << maxn(arr1, 4) << "\n";
	std::cout << "第二个数组最大的数是：" << maxn(arr2, 6) << "\n";
	std::cout << "最长的字符串是：" << maxn(arr3, 4) << "\n";
	return 0;
}



