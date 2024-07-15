#include<iostream>

using namespace std;

double add(double x, double y){
    return x + y;
}

double multiply(double x, double y){
    return x * y;
}

double calculate(double x, double y, double (*pf)(double, double)){
    return pf(x, y);
}

int main(int argc, char **argv){
    double x, y;
    while (true)
    {
        std::cout << "请输入两个数字（用空格分隔）: ";
        if(!(cin>>x>>y)){
            cout << "输入格式错误，退出" << endl;
            break;
        }

        double sum = calculate(x, y, add);
        double product = calculate(x, y, multiply);
        cout << x << "+" << y << "=" << sum << endl;
        cout << x << "*" << y << "=" << product << endl;
    }
    return 0;
}