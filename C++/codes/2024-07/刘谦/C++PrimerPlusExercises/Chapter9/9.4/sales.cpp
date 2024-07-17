// sales.cpp
#include <iostream>
#include "sales.h"

namespace SALES{

    using std::cin;
    using std::cout;
    using std::endl;

    void setSales(Sales &s, const double ar[], int n){
        
        int a = n < QUARTERS ? n : QUARTERS;
        double sum = 0.0;
        s.max = s.min = ar[0];
        
        for (int i = 0; i < a ; i++){
            s.sales[i] = ar[i];
            sum += ar[i];
            if (ar[i] > s.max)
                s.max = ar[i];
            if (ar[i] < s.min)
                s.min = ar[i];
        }
        
        for (int i = a; i < QUARTERS; i++){
            s.sales[i] = 0.0;
        }
        
        s.average = sum / n;
    }

    void setSales(Sales &s){
        
        double sum = 0.0;
        cout << "Please enter sales for 4 quarters:" << endl;
        
        for (int i = 0; i < QUARTERS; i++){
            cout << "Quarter " << (i + 1) << ": ";
            cin >> s.sales[i];
            sum += s.sales[i];
            if (i == 0 || s.sales[i] > s.max)
                s.max = s.sales[i];
            if (i == 0 || s.sales[i] < s.min)
                s.min = s.sales[i];
        }
        s.average = sum / QUARTERS;
    }

    void showSales(const Sales &s){
        cout << "Sales: ";
        for (int i = 0; i < QUARTERS; i++){
            cout << s.sales[i] << " ";
        }
        cout << endl;
        cout << "Average: " << s.average << endl;
        cout << "Max: " << s.max << endl;
        cout << "Min: " << s.min << endl;
    }
}
