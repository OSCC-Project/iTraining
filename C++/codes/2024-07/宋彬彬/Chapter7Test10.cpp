#include<iostream>


double add(double ,double);
double kMinus(double ,double);
double mult(double,double);
double calculate(double (*p)(double,double),double,double);

int main()
{
    double opera_a,opera_b,result;
    int opera_type=-1;
    char ctn;

    double (*pa[3])(double,double) = {add,kMinus,mult};

    while (true)
    {
        opera_a = -999;
        opera_b = -999;
        result = -999;
        opera_type = -10;
        ctn = '\0';

        std::cout<<"输入两个数用于计算："<<std::endl;
        std::cin>>opera_a>>opera_b;
        std::cout<<std::endl<<"输入操作类型对应数字："<<std::endl;
        std::cout<<"1:加法"<<std::endl<<"2:减法"<<std::endl<<"3:乘法"<<std::endl;
        std::cin>>opera_type;


        switch(opera_type)
        {
            case 1: result=pa[0](opera_a,opera_b);break;
            case 2: result=pa[1](opera_a,opera_b);break;
            case 3: result=pa[2](opera_a,opera_b);break;
            default:break;
        }
        
        std::cout<<"计算结果为："<<result<<std::endl;
        std::cout<<"输入是否继续操作，N退出，其余继续"<<std::endl;
        std::cin>>ctn;
        
        if(ctn == 'N')
        {
            break;
        }
    }
    return 0;
}

double add(double a,double b)
{
    return a+b;
}
double kMinus(double a,double b)
{
    return a-b;
}
double mult(double a,double b)
{
    return  a*b;
}
double calculate(double (*p)(double,double),double a,double b)
{
    return (*p)(a,b);
}