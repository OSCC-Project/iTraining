// static.cpp -- 使用静态局部变量
#include <iostream>
#include<string>

// 常量
const int ArSize = 10;

// 函数原型
void strcount(const std::string str);

int main() {
	using namespace std;
	//char input[ArSize];
	string input;
	char next;

	cout << "输入一行文本:\n";
	//cin.get(input, ArSize);
	getline(cin, input);
	while (input != "") {
		//cin.get(next);
		//while (next != '\n') // 字符串不符合！
			//cin.get(next);   // 处理剩余部分
		strcount(input);
		cout << "输入下一行（空行退出）:\n";
		getline(cin, input);
	}
	cout << "再见\n";
	return 0;
}

void strcount(const std::string str) {
	using namespace std;
	static int total = 0; // 静态局部变量
	int count = 0;        // 自动局部变量

	cout << "\"" << str << "\" 包含 ";
	//while (*str++)        // 移动到字符串的末尾
		//count++;
	count = str.length();
	total += count;
	cout << count << " 个字符\n";
	cout << "总共 " << total << " 个字符\n";
}
