#include <iostream>
#include<cstring>
#include<string>
using namespace std;

const int SLEN = 30;

struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;

	while (cin.get() != '\n')
		continue;

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done\n";
	return 0;
}

int getinfo(student pa[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << "请输入学生的姓名：";
		cin.getline(pa[i].fullname, SLEN);
		if (strlen(pa[i].fullname) == 0) //输入空行则暂停
			break;
		cout << "请输入学生的兴趣：";
		cin.getline(pa[i].hobby, SLEN);
		cout << "请输入学生的ooplevel：";
		cin >> pa[i].ooplevel;
		cin.get();
	}
	return i;
}

void display1(student st) {
	cout << "display1" << endl;
	cout << "姓名：" << st.fullname << " 兴趣：" << st.hobby << " ooplevel：" << st.ooplevel << endl;
}

void display2(const student* ps) {
	cout << "display2" << endl;
	cout << "姓名：" << ps->fullname << " 兴趣：" << ps->hobby << " ooplevel：" << ps->ooplevel << endl;

}
void display3(const student pa[], int n) {
	cout << "display3" << endl;
	for (int i = 0; i < n; i++) {
		cout << "姓名：" << pa[i].fullname << " 兴趣：" << pa[i].hobby << " ooplevel：" << pa[i].ooplevel << endl;
	}
}
