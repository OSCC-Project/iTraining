#include<iostream>

template<typename T>
T ReturnMax(T a[],T b[],T c[],T d[],T e[])
{
    T max = -999.0;
    for(int i=0;i<3;i++)
    {
        if(a[i] > max) {max = a[i];}
        if(b[i] > max) {max = b[i];}
        if(c[i] > max) {max = c[i];}
        if(d[i] > max) {max = d[i];}
        if(e[i] > max) {max = e[i];}   
    }
    return max;
}

int main()
{
    /*int arr1[3] = {1,3,5};
    int arr2[3] = {4,56,7};
    int arr3[3] = {4,6,7};
    int arr4[3] = {4,9,7};
    int arr5[3] = {3,5,7};
    int max = -999;*/

    double arr1[3] = {1.0,3.4,5.6};
    double arr2[3] = {4.8,56.0,7.9};
    double arr3[3] = {4,6,7};
    double arr4[3] = {4,9,7};
    double arr5[3] = {3,5,7};
    double max = -999.0;

    max = ReturnMax(arr1,arr2,arr3,arr4,arr5);

    //std::cout<<max<<std::endl;
    printf("%lf\n",max);

    return 0;
}