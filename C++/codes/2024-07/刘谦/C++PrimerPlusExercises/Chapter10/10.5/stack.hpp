
struct customer {
    char fullname[35];
    double payment;
};

typedef customer Item; 

class Stack {

private:
    enum { MAX = 10 };    
    Item items[MAX];      
    int top;              

public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);  
    bool pop(Item & item);          
};

Stack::Stack() {
    top = 0;
}

bool Stack::isempty() const {
    return top == 0;
}

bool Stack::isfull() const {
    return top == MAX;
}

bool Stack::push(const Item & item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else
        return false;
}

bool Stack::pop(Item & item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else
        return false;
}

