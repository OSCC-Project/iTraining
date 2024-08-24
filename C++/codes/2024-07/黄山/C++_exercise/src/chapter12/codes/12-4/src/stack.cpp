#include"stack.h"

Stack::Stack(int n){
    this->size = n;
    this->pitems = new Item[this->size];
    this->top = -1;
    std::cout << "stack created" << std::endl;
}

Stack::Stack(const Stack& st){
    this->size = st.size;
    this->pitems = new Item[this->size];
    this->top = st.top;
    for(int i=0;i<=this->top;++i){
        this->pitems[i] = st.pitems[i];
    }
    std::cout << "stack copyed" << std::endl;
}

Stack::~Stack(){
    delete[] (this->pitems);
    std::cout << "stack destroyed" << std::endl;
}

bool Stack::isempty() const{
    if(this->top == -1)
        return true;
    else
        return false;
}

bool Stack::isfull() const{
    if(this->top == this->size - 1)
        return true;
    else
        return false;
}
bool Stack::push(const Item& item){
    if(this->isfull()){
        std::cout << "can't push, the stack is full." << std::endl;
        return false;
    }
    this->top += 1;
    this->pitems[this->top] = item;
    std::cout << "push " << item << std::endl;
    return true;
}
bool Stack::pop(Item& item){
    if(this->isempty()){
        std::cout << "can't pop, the stack is empty." << std::endl;
        return false;
    }
    item = this->pitems[this->top];
    this->top -= 1;
    std::cout << "pop " << item << std::endl;
    return true;
}

Stack& Stack::operator=(const Stack& st){
    this->size = st.size;
    this->pitems = new Item[this->size];
    this->top = st.top;
    for(int i=0;i<=this->top;++i){
        this->pitems[i] = st.pitems[i];
    }
    std::cout << "stack assigned" << std::endl;
    return *this;
}

// Stack& Stack::operator=(const Stack& st){
//     Stack new_stack(st.size);
//     new_stack.pitems = new Item[new_stack.size];
//     new_stack.top = st.top;
//     for(int i=0;i<=new_stack.top;++i){
//         new_stack.pitems[i] = st.pitems[i];
//     }
//     std::cout << "stack assigned" << std::endl;
//     return new_stack;
// }