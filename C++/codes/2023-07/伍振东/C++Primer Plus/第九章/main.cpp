#include<iostream>
#include<string>
#include<new>
#include"golf.h"    //9.1
#include"sale.h"    //9.4

// 9.1：golf.h，golf.cpp
void controller9_1() {
	// 填充数组
    using namespace std;
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);
    golf g[3];
    int i = 0;
    while ((i < 3) && (setgolf(g[i])))
    {
        showgolf(g[i]);
        cout << "下一个 golf:\n";
        i++;

    }
    golf leo;
    setgolf(leo, "Leonardo Liu", 28);
    handicap(leo, 1);
    showgolf(leo);
}

// 9.2：修改程序9.9
void strcount(std::string str) {
    using namespace std;
    int count = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != ' ')count += 1;
    }
    cout <<"\"" << str <<"\"" << " contains " << count << " characters" << endl;
}

void controller9_2() {
    using namespace std;
    string input;
    while (1) {
        cout << "Enter a line:\n";
        getline(cin, input);
        if (input.compare("") == 0) {
            break;
        }
        strcount(input);
    }
    cout << "Bye!\n" << endl;
}

// 9.3：使用new运算符
struct chaff
{
    char dross[20];
    int slag;
};

void controller9_3() {
    using namespace std;
    char buffer1[512];
    char* buffer2 = new char[512];

    chaff* p1, * p2;
    // 分配指定内存空间
    p1 = new (buffer1) chaff[2];
    p2 = new (buffer2) chaff[2];

    strcpy_s(p1[0].dross, "first");
    p1[0].slag = 1;
    strcpy_s(p1[1].dross, "second");
    p1[1].slag = 2;
    strcpy_s(p2[0].dross, "third");
    p2[0].slag = 3;
    strcpy_s(p2[1].dross, "forth");
    p2[1].slag = 4;

    for (int i = 0; i < 2; ++i) {
        cout << "dross：" << p1[i].dross << " slag：" << p1[i].slag << endl;
    }
    for (int i = 0; i < 2; ++i) {
        cout << "dross：" << p2[i].dross << " slag：" << p2[i].slag << endl;
    }
}

// 9.4：基于名字空间写出一个由三个文件组成的程序
void controller9_4(){
    using namespace std;
    using namespace SALES;
    Sales sale1;
    Sales sale2;
    setSales(sale1);
    showSales(sale1);
    double sales[4] = {2.2, 3.2, 2.5, 5.3};
    setSales(sale2, sales, 4);
    showSales(sale2);
}

int main() {
    //controller9_1();
    //controller9_2();
    //controller9_3();
    controller9_4();
    system("PAUSE");
}