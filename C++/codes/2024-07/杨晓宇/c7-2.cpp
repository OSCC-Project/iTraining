#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**
 * @brief 返回两数之和
 * 
 * @param x 被加数
 * @param y 加数
 * @return double 
 */
double add(double x, double y)
{
    return x + y;
}

/**
 * @brief 返回两数之差
 * 
 * @param x 被减数
 * @param y 减数
 * @return double 
 */
double del(double x, double y)
{
    return x - y;
}

/**
 * @brief 调用add和del函数
 * 
 * @param x 输入1
 * @param y 输入2
 * @return double 
 */
double (*calculate[2])(double x, double y) = {add, del};

int main()
{
    double x, y;
    while(1)
    {
        cin >> x >> y;
        if(x == 0.0 || y == 0.0)
            break;
        cout << x << " add " << y << " = " 
            << (*calculate[0])(x, y) << endl;
        cout << x << " del " << y << " = " 
            << (*calculate[1])(x, y) << endl;
    }
    return 0;
}