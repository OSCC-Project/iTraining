#include<iostream>
#include "../include/project/a_.h"
#include "../include/project/gra.h"
using std::cout;
using std::cin;
using std::endl;

int main(){
    cout<<"enter the rows and cols of map "<<endl;
    int tmp[2];
    cin>>tmp[0]>>tmp[1];
    cout<<"enter the number of barriers"<<endl;
    int tt;
    cin>>tt;
    std::vector<std::pair<int,int> >ba;
    Grid_ grah(tmp[0],tmp[1]);
    while(tt--){
        cout<<"enter the locations of barriers:"<<endl;
        int x,y;
        cin>>x>>y;
        grah.setValue(x,y,1);

    }
    
    cout<<"enter the start"<<endl;
    std::pair<int,int> p1;
    std::pair<int,int> p2;
    cin>>p1.first;
    cin>>p1.second;
    if(grah.getValue(p1.first,p1.second)==-1){
        cout<<"wrong start!!"<<endl;
        return 0;
    }
    cout<<"enter the goal:"<<endl;
    cin>>p2.first;
    cin>>p2.second;
    if(grah.getValue(p2.first,p2.second)==-1){
        cout<<"wrong goal!!"<<endl;
        return 0;
    }
    std::pair<int,int> start=std::make_pair(0,0);
    std::pair<int,int> goal=std::make_pair(3,7);
    AStarAlgorithm astar;
    std::vector<std::pair<int, int>> path = astar.findPath(grah, start, goal);

    std::cout << "Path: ";
    for (const auto& p : path) {
        std::cout << "(" << p.first << "," << p.second << ") ";
    }
    std::cout << std::endl;
    
    
}

