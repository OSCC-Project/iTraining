#include<iostream>
#include<string>
using namespace std;

// 函数声明
double tiaohe(double x, double y);
void controller7_1();

// 第七章练习题
// 7.1：调和平均数
double tiaohe(double x, double y) {
	return 2.0 * x * y / (x + y);
}
void controller7_1() {
	int x, y;
	cin >> x >> y;
	while (x != 0 && y != 0) {
		cout << tiaohe(x, y);
	}
}

// 7.2：输入、显示和计算平均成绩
void controller7_2() {
	double grades[10] = { 0 };
	int len = 0;
	double sum_grade = 0;
	cout << "请输入高尔夫成绩（输入-1提前结束）：";
	for (int i = 0; i < 10; ++i) {
		int t;
		cin >> t;
		if (t == -1) {
			break;
		}
		len += 1;
		grades[i] = t;
	}
	
	cout << "显示成绩：";
	for (int i = 0; i < len; ++i) {
		sum_grade += grades[i];
		cout << grades[i] << ' ';
	}

	cout << endl;
	cout << "平均成绩：" << sum_grade / len << endl;
}

// 7.3：结构体与函数
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

// 函数1：传递box结构，显示成员的值
void show_value(box x) {
	cout << x.maker << endl;
	cout << x.height << endl;
	cout << x.width << endl;
	cout << x.length << endl;
	cout << x.volume << endl;
}

// 函数2：传递box的地址，改变成员的值
void change_value(box * x) {
	x->height = 10;
	x->length = 10;
	x->width = 10;
	cout << "修改以后的值：" << endl;
	show_value(*x);
}


// 函数3：使用上面两个函数
void controller7_3() {
	box box1 = { "sdad", 20, 20, 20, 20 };
	show_value(box1);
	change_value(&box1);
}

// 7.4：计算彩票头奖的概率
// 输入两个区间，计算出中头奖的概率
long double probability(unsigned numbers, unsigned picks) {
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--) {
		result = result * n / p;
	}
	return result;
}

void controller7_4() {
	long double result;
	cout << "输入域号码区间：";
	int first, second;
	cin >> first >> second;
	result = probability(first, second);
	cout << "输入特选号码区间：";
	cin >> first;
	result = result / first;
	cout << "彩票中奖概率：" << result << endl;
}

// 7.5：递归函数返回阶乘
long int jiecheng(unsigned n) {
	if (n == 1)return n;
	else {
		return n * jiecheng(n - 1);
	}
}

void controller7_5() {
	while (true) {
		cout << "输入要计算的递归值：";
		int n;
		cin >> n;
		if (n <= 0)break;
		cout << jiecheng(n) << endl;
	}
}

// 7.6：自定义数组函数
// 函数1：将字符串转化为数字
double transfer(string a) {
	int n = a.length();
	double result = 0;
	for (int i = 0; i < n; ++i) {
		if (!isdigit(a[i])) {
			return -1;
		}
		result = result * 10 + (a[i] - '0');
	}
	return result;
}
// 填充列表
int Fill_array(double numbers[], int length) {
	string temp;
	cout << "输入填充的数组：" << endl;
	for (int i = 0; i < length; ++i) {
		cin >> temp;
		double t_n = transfer(temp);
		if (t_n == -1) {
			return i;
			break;
		}
		numbers[i] = t_n;
	}
	return length;
}
// 显示列表
void Show_array(double numbers[], int length) {
	for (int i = 0; i < length; ++i) {
		cout << numbers[i] << ' ';
	}
	cout << endl;
}
// 反转列表
void Reverse_array(double numbers[], int length) {
	for (int i = 0; i < length / 2; ++i) {
		double temp = numbers[i];
		numbers[i] = numbers[length - i - 1];
		numbers[length - i - 1] = temp;
	}
}

void controller7_6() {
	double numbers[10];
	int len = Fill_array(numbers, 10);
	Show_array(numbers, len);
	Reverse_array(numbers, len);
	Show_array(numbers, len);
}

// 7.7：使用指针来对数组进行操作
double* fill_array(double* ar, double* limit) {
	double temp;
	double* p;
	int i = 0;
	for (p = ar; p != limit; ++p, ++i) {
		cout << "Enter value #" << (i + 1) << ":";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process treminated. \n";
			break;
		}
		else if (temp < 0) {
			break;
		}
		*p = temp;
	}
	return p;
}

void show_array(const double* ar,const double* end) {
	const double* p = ar;
	int i = 0;
	for (p = ar; p != end; ++p, ++i) {
		cout << "Property #" << (i + 1) << ": $";
		cout << *p << endl;
	}
}

void revalue(double r, double* ar, double* n) {
	for (double* p = ar; p != n; ++p) {
		*p *= r;
	}
}

void controller7_7() {
	double properties[5];
	double* size = fill_array(properties, properties + 5);
	show_array(properties, size);

	cout << "Enter revaluation factor: ";
	double factor;
	cin >> factor;
	revalue(factor, properties, size);
	show_array(properties, size);
	cout << "Done.\n";
	system("pause");

}

// 7.9：处理数组和结构的函数
const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n) {
	int count = 0;
	for (int i = 0; i < n; ++i) {
		cout << "第" << i + 1 << "个学生" << endl;
		cout << "输入fullname：";
		cin >> pa[i].fullname;
		cout << "输入hobby：";
		cin >> pa[i].hobby;
		cout << "输入ooplevel：";
		cin >> pa[i].ooplevel;
		count++;
	}
	cout << "输入结束" << endl;
	return count;
}

void display1(student st) {
	cout << "fullname:" << st.fullname << endl;
	cout << "hobby:" << st.hobby << endl;
	cout << "ooplevel:" << st.ooplevel << endl;
}

void display2(const student* st) {
	cout << "fullname:" << st->fullname << endl;
	cout << "hobby:" << st->hobby << endl;
	cout << "ooplevel:" << st->ooplevel << endl;
}

void display3(const student pa[], int n) {
	for (int i = 0; i < n; ++i) {
		display1(pa[i]);
	}
}

void controller7_9() {
	cout << "Enter class size:";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n') {
		continue;
	}
	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; ++i) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done\n";
}

// 7.10：calculate函数
double add(double x, double y) {
	return x + y;
}

double sub(double x, double y) {
	return x - y;
}

double mul(double x, double y) {
	return x * y;
}

double calculate(double x, double y, double(*func)(double x, double y)) {
	return func(x, y);
}

void controller7_10() {
	double(*pf[3])(double, double);
	pf[0] = add;
	pf[1] = sub;
	pf[2] = mul;

	double x, y;
	while (1) {
		cout << "输入成对的x和y（输入非数字则退出）：";
		cin >> x >> y;
		if (!cin) {
			break;
		}
		cout << "进行add、sub、mul后的结果分别为：";
		for (int i = 0; i < 3; ++i) {
			cout<<pf[i](x, y)<<" ";
		}
		cout << endl;
	}

}

int main() {
	controller7_10();
	return 0;
}