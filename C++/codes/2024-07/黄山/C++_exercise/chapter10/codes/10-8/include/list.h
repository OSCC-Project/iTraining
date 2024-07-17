#pragma once

#include<iostream>

template<typename T>
class List{
private:
    struct Item
    {
        T value;
        Item* next;
    };

    int size;
    int capacity;
    Item* HEAD; //指向第一个数据
    Item* TAIL; //指向最后一个数据

public:
    // List(int n=0);

    // bool isEmpty();

    // bool isFull();

    // void append(T val);

    // void visit(void(*pf)(T&));

    List(int n){
        HEAD = new Item;
        TAIL = HEAD;
        size = 0;
        capacity = n;
        std::cout<<"list init completion"<<std::endl;
    }

    bool isEmpty(){
        if(size == 0) return true;
        else return false;
    }

    bool isFull(){
        if(size == capacity) return true;
        else return false;
    }

    void append(T val){
        if(isFull()){
            std::cout << "Can't append, this list is full." << std::endl;
            return;
        }
        Item* temp = new Item;
        temp->value = val;
        temp->next = nullptr;
        TAIL->next = temp;
        TAIL = temp;
        size++;
        std::cout<<"append completion"<<std::endl;
    }

    void visit(void(*pf)(T& )){
        Item* temp = HEAD;
        while(temp->next != nullptr){
            pf(temp->next->value);
            temp = temp->next;
        }
    }
};