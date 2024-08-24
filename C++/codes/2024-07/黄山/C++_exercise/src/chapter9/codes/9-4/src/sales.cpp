#include <iostream>
#include<cfloat>
#include "sales.h"

namespace SALES
{
    void setSales(Sales& s, const double ar[], int n){
        int counts = (n>4) ? 4 : n;
        double sum = 0;
        s.max=DBL_MIN, s.min=DBL_MAX;

        int i=0;
        while(i<counts){
            s.sales[i] = ar[i];
            sum += ar[i];
            if(ar[i] > s.max) s.max=ar[i];
            if(ar[i] < s.min) s.min=ar[i];
            i++;
        }
        s.average = sum / counts;

        while(i<4){
            s.sales[i] = 0;
            i++;
        }
    }

    void setSales(Sales& s){
        std::cout<<"请输入4个数字: ";
        std::cin >> s.sales[0] >> s.sales[1] >> s.sales[2] >> s.sales[3];
        std::cin.get();

        double sum = 0;
        s.max=DBL_MIN, s.min=DBL_MAX;

        for(int i=0;i<4;++i){
            sum += s.sales[i];
            if(s.sales[i] > s.max) s.max=s.sales[i];
            if(s.sales[i] < s.min) s.min=s.sales[i];
        }
        s.average = sum/4;
    }

    void showSales(const Sales& s){
        std::cout<<"Sales: "<<s.sales[0]<<" "<<s.sales[1]<<" "<<s.sales[2]<<" "<<s.sales[3]<<std::endl;
        std::cout<<"average: "<<s.average<<std::endl;
        std::cout<<"max: "<<s.max<<std::endl;
        std::cout<<"min: "<<s.min<<std::endl;
    }
} // namespace name