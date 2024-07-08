#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int cnt = 0;

/**
 * @brief 输出输入字符串
 * 
 * @param str 输入的字符串
 * @param n 参数
 */
void func(char *str, int n = 0)
{
    ++cnt;
    cout << str << endl;
    if(n != 0)
        for(int a = 1; a < cnt; a++)
            cout << str << endl;
    return;
}

int main()
{
    int n;
    char str[255];
    while(1)
    {
        cin >> str >> n;
        func(str, n);
    }
    return 0;
}