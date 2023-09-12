#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;


// 第八章练习题
// 8.1：根据接受参数个数来打印字符串，使用默认类型
void print(char* a, int n = 0) {
	static int flag = 0;
	flag += 1;
	cout << "第" << flag << "次调用print函数！" << endl;
	if (n == 0) {
		cout << "未传入参数" << endl;
		cout << a << endl;
	}
	else {
		for (int i = 0; i < flag; ++i) {
			cout << a << endl;
		}
	}
	cout << endl;
}

void controller8_1() {
	char str[20] = "hello world!";
	print(str);
	print(str, 2);
	print(str, 3);
	print(str);
}

// 8.2：以引用为参数，打印结构体
struct CandyBar{
	char name[20];
	double weight;
	int calories;
};
void show_CandyBar(const CandyBar& candybar) {
	cout << "name:" << candybar.name << endl;
	cout << "weight:" << candybar.weight << endl;
	cout << "calories:" << candybar.calories << endl;
	cout << endl;
}
void change_candy(CandyBar& candybar, char* name1, double weight1, int calories1) {
	show_CandyBar(candybar);
	strcpy_s(candybar.name, name1);
	candybar.weight = weight1;
	candybar.calories = calories1;
	show_CandyBar(candybar);
}
void controller8_2() {
	CandyBar candybar = { "xiaoli", 3.3, 250 };
	char name1[20] = "Millennium Munch";
	double weight1 = 2.85;
	int calories1 = 350;
	change_candy(candybar, name1, weight1, calories1);
}

// 8.3：将string对象的内容转化为大写
void controller8_3() {
	string temp;
	while (1) {
		cout << "输入转化的字符串（输入q退出结束）：";
		getline(cin, temp);
		if (temp == "q") {
			break;
		}
		string temp2 = "";
		for (int i = 0; i < temp.length(); ++i) {
			if (temp[i] >= 'a' && temp[i] <= 'z') {
				temp2 += toupper(temp[i]);
			}
			else {
				temp2 += temp[i];
			}
		}
		cout << temp2 << endl;
	}
}

// 8.4：补充程序框架
struct stringy{
	char* str;
	int ct;

	~stringy() {
		delete str;
	}
};

void set(stringy& st, const char* x) {
	st.ct = strlen(x) + 1;
	st.str = new char[st.ct];
	strcpy_s(st.str, st.ct, x);
}

void show(stringy& st, const int n = 1) {
	for (int i = 0; i < n; ++i) {
		cout << st.str << endl;
	}
	cout << endl;
}

void show(const char* x, const int n = 1) {
	for (int i = 0; i < n; ++i) {
		cout << x << endl;
	}
	cout << endl;
}

void controller8_4() {
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);

	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
}

// 8.5：编写函数模板
template <typename T>
T max5(T nums[]) {
	T res = nums[0];
	for (int i = 0; i < 5; ++i) {
		res = max(res, nums[i]);
	}
	return res;
}

void controller8_5() {
	int a[5] = { 1,2,3,2,1 };
	double b[5] = { 1.3,2.3,1.2,1.7,3.2 };
	int res1 = max5(a);
	double res2 = max5(b);

	cout << res1 << endl;
	cout << res2 << endl;
}

// 8.6：编写函数模板maxn
template <typename T>
T maxn(T nums[], int n) {
	T res = nums[0];
	for (int i = 0; i < n; ++i) {
		res = max(res, nums[i]);
	}
	return res;
}

// 具体化char函数
template <> char* maxn(char* nums[], int n) {
	char* res = nums[0];
	for (int i = 0; i < n; ++i) {
		res = strlen(res) >= strlen(nums[i]) ? res : nums[i];
	}
	return res;
}

void controller8_6() {
	int nums1[6] = { 2,5,3,1,4,2 };
	double nums2[4] = { 2.3,1.5,9.9,5.5 };
	char str1[] = "Welcome";
	char str2[] = "to";
	char str3[] = "NewYorssk";
	char str4[] = "Tylor";
	char str5[] = "Swift";
	char* nums3[5] = { str1, str2, str3, str4, str5 };
	cout << maxn(nums1, 6) << endl;
	cout << maxn(nums2, 4) << endl;
	cout << maxn(nums3, 5) << endl;
}

// 8.7：修改代码
struct debts {
	char name[50];
	double amount;
};

template <typename T>
void SumArray(T arr[], int n) {
	cout << "template A\n";
	T res = arr[0];
	for (int i = 1; i < n; ++i) {
		res += arr[i];
	}
	cout << res << endl;
}

template <typename T>
void SumArray(T* arr[], int n) {
	cout << "template B\n";
	T res = *arr[0];
	for (int i = 1; i < n; ++i) {
		res += *arr[i];
	}
	cout << res << endl;
}


void controller8_7() {
	int things[6] = { 13, 31, 103,301,310,130 };
	struct debts mr_E[3] = {
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Ibt Stout", 1800.0}
	};
	double* pd[3];
	for (int i = 0; i < 3; ++i) {
		pd[i] = &mr_E[i].amount;
	}
	cout << "Listing Mr. E's count of thing:\n";
	SumArray(things, 6);
	cout << "Listing Mr. E's debts:\n";
	SumArray(pd, 3);
}

int main() {
	//controller8_1();
	//controller8_2();
	//controller8_3();
	//controller8_4();
	//controller8_5();
	//controller8_6();
	controller8_7();
	system("PAUSE");
	return 0;
}
