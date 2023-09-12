//
//  sales.cpp
//  9-4
//
//  Created by 郭帆 on 2023/7/20.
//

#include <iostream>
#include "sales.hpp"

namespace SALES {


Sales::Sales(const double ar[], int n) {
    double total = ar[0], maxv = ar[0], minv = ar[0];
    for (int i = 1; i < n; i++)
    {
        sales[i] = ar[i];
        total += ar[i];
        maxv = ar[i] > maxv ? ar[i] : maxv;
        minv = ar[i] < minv ? ar[i] : minv;
    }
    min = minv;
    max = maxv;
    average = total / n;
}

Sales::Sales() {
    using namespace std;
    int len;
    cout << "Enter the length of sales(<= 4 and > 0): ";
    while (!(cin >> len) || len > 4 || len <= 0)
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Please enter a number(<= 4 and > 0): ";
    }
    double *temp = new double[len];
    cout << "Please enter the sales:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << "Please enter the content #" << i + 1 << ": ";
        while (!(cin >> temp[i]))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Please enter a number: ";
        }
    }
    *this = Sales(temp, len);
    delete[] temp;
}

void Sales::show() const {
    std::cout << "Sales average: " << average << std::endl;
    std::cout << "Sales max: " << max << std::endl;
    std::cout << "Sales min: " << min << std::endl;
}

}
