#include<iostream>
#include<cstring>

template<typename T1,typename T2>
T1 ReturnMax(T1 a[],T2 b)
{
    T1 max = -999;
    for(int i=0;i<b;i++)
    {
        if(a[i] > max) {max = a[i];}
    }
    return max;
}
template<typename T1,typename T2>
T1 *ReturnMax(T1 *a[],T2 b);

int main()
{
    /*int arr1[6] = {4,5,7,9,23,432};
    int cnt = 6;
    int max = -9999;*/

    double arr1[6] = {4.9,5.7,7,9,23,432.65};
    double cnt = 6;
    double max = -9999.0;

    char const *arr2[5] = {"erqerdsf","dfa","trtrt","trt-oerw","rqwer"};

    max = ReturnMax(arr1,cnt);
    
    std::cout<<max<<std::endl;
    std::cout<<ReturnMax(arr2,5)<<std::endl;

    return 0;
}
template<typename T1,typename T2>
T1 *ReturnMax(T1 *a[],T2 b)
{
    T1 *addr = NULL;
    int len = -1;
    for(int i=0;i<b;i++)
    {
        int tmp_len = strlen(a[i]) ;
        if( tmp_len > len)
        {
            len = tmp_len;
            addr = a[i];
        }
    }
    return addr;
}