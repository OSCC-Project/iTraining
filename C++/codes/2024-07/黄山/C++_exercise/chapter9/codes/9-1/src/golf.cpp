#include<iostream>
#include<cstring>

#include"golf.h"

void setgolf(golf& g, const char* name,int hc){
    strcpy(g.fullname, name);
    // g.fullname = name;
    g.handicap = hc;
}

int setgolf(golf& golf_player){
    char fullname[Len];
    int handicap;
    std::cout<<"请输入高尔夫选手的姓名: ";
    std::cin.getline(fullname, Len);
    if(fullname[0] =='\0') return 0;
    std::cout<<"请输入高尔夫选手的等级：";
    std::cin >> handicap;
    std::cin.get();
    setgolf(golf_player, fullname, handicap);
    return 1;
}

void handicap(golf& g, int hc){
    g.handicap = hc;
}

void showgolf(const golf& g){
    std::cout << "姓名：" << g.fullname << " 等级：" << g.handicap << std::endl;
}