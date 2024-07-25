#include<iostream>
using namespace std;
#include"complex0.h"

int main(int argc, char** argv){
    complex a(3.0, 4.0);
    complex c;
    cout<<"Enter a complex number (q to quit):\n";
    while(cin>>c){
        cout<<"c is "<<c<<'\n';
        cout<<"compldex conjugate is "<<~c<<'\n';
        cout<<"a is "<<a<<'\n';
        cout<<"a + c is "<<a+c<<'\n';
        cout<<"a - c is "<<a-c<<'\n';
        cout<<"a * c is "<<a*c<<'\n';
        cout<<"2 * c is "<<2*c<<'\n';
        cout<<"Enter a complex number (q to quit):\n";
    }
    cout<<"Done!\n";
    return 0;
}