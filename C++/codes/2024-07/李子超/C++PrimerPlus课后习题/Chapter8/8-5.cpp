#include <iostream>
using std::cout;
using std::endl;
using std::cin;
template <typename T>
T Maxvalue(const T *arr);
int main()
{
	int arr1[5] = { 5,4,3,2,1 };
	double arr2[5] = { 5.5,4.4,3.3,2.2,1.1 };
	cout << "Max of int array: ";
	cout << Maxvalue(arr1) << endl;
	cout << "Max of double array: ";
	cout << Maxvalue(arr2) << endl;
}

template<typename T>
T Maxvalue(const T * arr)
{
	T ans = arr[0];
	for (int i = 1; i < 5; i++) {
		ans = ans > arr[i] ? ans : arr[i];
	}
	return ans;
}
