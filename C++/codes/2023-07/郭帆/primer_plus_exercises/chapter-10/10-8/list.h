//
//  list.h
//  cpppp
//
//  Created by 郭帆 on 2023/7/20.
//

#ifndef list_h
#define list_h

template <typename T>
class List {
private:
    enum {MAX = 10};
    T items[MAX];
    int idx;
public:
    List() : idx(0) {}
    
    bool isempty() const { return idx == 0; }
    
    bool isfull() const { return idx == MAX; }
    
    bool push_back(const T & item) {
        if (idx < MAX) {
            items[idx++] = item;
            return true;
        } else {
            return false;
        }
    }
    
    void visit(void (*pf)(T &)) {
        for (int i = 0; i < idx; i++) {
            pf(items[i]);
        }
    }
};

#endif /* list_h */
