#include<iostream>
using namespace std;
#include"stack.h"

int main(int argc, char** argv){
    Stack s1(3);
    if(s1.isempty()){
        cout << "stack is empty" << endl;
    }

    int start = 3;
    while(s1.push(start)){
        start++;
    }
    Stack s2;
    s2 = s1; //调用重载的=
    unsigned long temp;
    s2.pop(temp);
    cout << temp << endl;

    Stack s3(s2); //调用复制构造函数
    return 0;
}