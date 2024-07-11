#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int Fill_array(double arr[],int length);
void Show_array(const double arr[], int length);
void Reverse_array(double arr[], int length);
const int MAXSIZE = 10;

int main()
{
	double test[MAXSIZE];
	int Len=Fill_array(test, 5);
	Show_array(test, Len);
	Reverse_array(test, Len);
	Show_array(test, Len);
}
int Fill_array(double arr[], int length)
{
	cout << "please input double value" << endl;
	double v;
	int index = 0;
	while (length--&&cin>>v) {
		arr[index++] = v;
	}
	return index ;
}

void Show_array(const double arr[], int length)
{
	cout << "the array is:" << endl;
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Reverse_array(double arr[], int length)
{
	cout << "Reverse the array!" << endl;
	int l = 0, r = length - 1;
	while (l < r) {
		double tmp = arr[l];
		arr[l] = arr[r];
		arr[r] = tmp;
		l++;
		r--;
	}
}
