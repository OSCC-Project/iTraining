#include<iostream>

void printString(const char* str, int n = 0);	//第二个参数是默认参数

int main() {
	const char* mystring = "Hello World";
	printString(mystring);
	printString(mystring, 3);

	return 0;
}

//默认参数的值只能在声明中指定
void printString(const char* str, int n) {
	std::cout << str << std::endl;
}