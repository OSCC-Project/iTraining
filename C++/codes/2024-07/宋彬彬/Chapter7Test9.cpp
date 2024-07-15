#include<iostream>
#include<array>
#include<string>

const int Seasons = 4;
const char Snames[4][10] = {"Spring","Summer","Fall","Winter"};

void fill(double [],int count);
void show(const char str[][10],double [],int count);


int main()
{
    double spand[4] = {0.0};
    fill(spand,Seasons);
    show(Snames,spand,Seasons);
    
    return 0;
}

void fill(double arr[],int count)
{
    for(int i=0;i<count;i++)
    {
        std::cout<<"输入"<<Snames[i]<<"花费"<<std::endl;
        std::cin>>arr[i];
    }
}

void show(const char str[][10],double arr[],int count)
{
    for(int i=0;i<count;i++)
    {
        std::cout<<str[i]<<"花费"<<arr[i]<<std::endl;
    }
}