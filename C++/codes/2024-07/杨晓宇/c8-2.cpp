#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
T maxn(T *num, int n = 0)
{
    if(n != 0)
    {
        T pmax = *num;
        num++;
        for(int a = 0; a < n-1; ++a, num++)
            pmax = pmax > *num ? pmax : *num;
        return pmax;
    }
    return *num;
}
template <> char * maxn<char *> (char **num, int n)
{
    if(n != 0)
    {
        auto getLen = [](char *str){
            int a = 0;
            while(str[a] != '\0')
                a++;
            return a+1;
        };
        int tempLen1 = getLen(num[0]), tempLen2 = 0;
        char *pstr = num[0];
        for(int a = 1; a < n; a++)
        {
            tempLen2 = getLen(num[a]);
            if(tempLen1 < tempLen2)
            {
                tempLen1 = tempLen2;
                pstr = num[a];
            }
        }
        return pstr;
    }
    return *num;
}
int main()
{
    int num1[] = {1, 2, 3, 4, 5, 6};
    double num2[] = {1.1, 2.2, 3.3, 4.4};
    char *num3[]={"a", "ab", "abc", "abcr", "abce"};
    cout << maxn(num1, 6) << endl;
    cout << maxn(num2, 4) << endl;
    cout << maxn(num3, 5) << endl;
    return 0;
}