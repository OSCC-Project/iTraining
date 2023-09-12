//
//  stack.hpp
//  10-5
//
//  Created by 郭帆 on 2023/7/20.
//

#ifndef stack_hpp
#define stack_hpp

template <typename T>
class Stack {
private:
    enum {MAX = 10};
    T items[MAX];
    int top;
public:
    Stack() : top(0) {}
    
    bool isempty() const { return top == 0; }
    
    bool isfull() const { return top == MAX; }
    
    bool push(const T & item) {
        if (top < MAX) {
            items[top++] = item;
            return true;
        } else {
            return false;
        }
    }
    
    bool pop(T & item) {
        if (top > 0) {
            item = items[--top];
            return true;
        } else {
            return false;
        }
    }
};

#endif /* stack_hpp */
