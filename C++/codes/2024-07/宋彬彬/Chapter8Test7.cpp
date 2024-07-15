#include<iostream>

template<typename T>
T ShowArray(T a[],int n);

template<typename T>
T ShowArray(T *a[],int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    int things[6] = {13,31,103,301,310,130};
    struct debts mr_E[3] =
    {
        {"IMa woof",2400.0},
        {"fadif afda",1300.0},
        {"idj adf2d",1800.0}
    };

    double *pt[3];
    for(int i=0;i<3;i++)
    {
        pt[i] = &mr_E[i].amount;
    }

    std::cout<<"things:"<<ShowArray(things,6)<<std::endl;
    std::cout<<"debts:"<<ShowArray(pt,3)<<std::endl;
    
    return 0;
}

template<typename T>
T ShowArray(T a[],int n)
{
    T count = 0;
    for(int i=0;i<n;i++)
    {
        count += a[i];
    }
    return count;
}

template<typename T>
T ShowArray(T *a[],int n)
{
    T count = 0;
    for(int i=0;i<n;i++)
    {
        count += (*a[i]);
    }
    return count;
}