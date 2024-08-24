#include<iostream>

double add(double x, double y){
    return x + y;
}

double multiply(double x, double y){
    return x * y;
}

double calculate(double x, double y, double (*pf)(double, double)){
    return pf(x, y);
}

int main(int argc, char **argv){
    double x, y;
    while (true)
    {
        std::cout << "Please enter two numbers (separated by Spaces): ";
        if(!(std::cin>>x>>y)){
            std::cout << "The input format is incorrect. Exit." << std::endl;
            break;
        }

        double sum = calculate(x, y, add);
        double product = calculate(x, y, multiply);
        std::cout << x << "+" << y << "=" << sum << std::endl;
        std::cout << x << "*" << y << "=" << product << std::endl;
    }
    return 0;
}