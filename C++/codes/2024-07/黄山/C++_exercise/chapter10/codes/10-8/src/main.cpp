#include"list.h"

struct move{
    double x, y;
};

void showint(int& num){
    std::cout<<"num: "<<num<<std::endl;
}

void showmove(move& m){
    std::cout<<"x: "<<m.x<<" y:"<<m.y<<std::endl;
}

int main(int argc, char** argv){
    //int list test
    List<int> int_list(3);
    if(int_list.isEmpty()){
        std::cout<<"the list is empty"<<std::endl;
    }
    // if(int_list.isFull()){
    //     std::cout<<"the list is full"<<std::endl;
    // }
    // std::cout<<int_list.capacity<<std::endl;
    int_list.append(3);
    int_list.append(4);
    int_list.append(-1);
    int_list.append(0);
    if(int_list.isFull()){
        std::cout<<"the list is full"<<std::endl;
    }
    int_list.visit(showint);

    //own type list test
    move m1 = {3, 4};
    move m2 = {1, 2};
    List<move> move_list(4);
    move_list.append(m1);
    move_list.append(m2);
    move_list.visit(showmove);
    
    return 0;
}