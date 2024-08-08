#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::cin;
const char* maxn(const char* arr[], size_t n);
template <typename T>
T maxn(const T *arr, size_t n);

int main()
{
	int arr1[6] = { 1,5,3,7,9,13};
	double arr2[4] = { 5.3,10.3,20.4,1.1 };
	const char *str[5] = { "abc","df","gfaga","fa","n"};

	cout << "Max of int array: ";
	cout << maxn(arr1,6) << endl;
	cout << "Max of double array: ";
	cout << maxn(arr2,4) << endl;
	cout << "longest of str array: ";
	cout << maxn(str, 5) << endl;

}
template<typename T>
T maxn(const T * arr, size_t n)
{
	T ans = arr[0];
	for (size_t i = 1; i < n; i++) {
		ans = ans > arr[i] ? ans : arr[i];
	}
	return ans;
}


const char* maxn(const char* arr[], size_t n) {
	const char* maxStr = arr[0];
	for (size_t i = 1; i < n; ++i) {
		if (strlen(arr[i]) > strlen(maxStr)) {
			maxStr = arr[i];
		}
	}
	return maxStr;
}

