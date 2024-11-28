#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**
 * @brief 返回调和平均数
 * 
 * @param x 输入1
 * @param y 输入2
 * @return double 
 */
double func(double x, double y)
{
    return 2.0 * x * y / (x + y);
}

int main()
{
    double x, y;
    while(1)
    {
        cin >> x >> y;
        if(x == 0.0 || y == 0.0)
            break;
        cout << func(x, y) << endl;
    }
    return 0;
}