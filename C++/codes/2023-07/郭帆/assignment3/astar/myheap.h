//
//  myheap.h
//  assignment3
//
//  Created by 郭帆 on 2023/7/27.
//

#ifndef myheap_h
#define myheap_h

#include <queue>
#include <vector>

namespace astar {
struct cmp {
    bool operator()(Node * n1, Node * n2) {
        if (n1->get_f_cost() == n2->get_f_cost()) {
            return n1->get_h_cost() > n2->get_h_cost();
        }
        return n1->get_f_cost() > n2->get_f_cost();
    }
};

template<class T, class Container = std::vector<T>, class Compare = cmp>
class myheap : public std::priority_queue<T, Container, Compare> {
public:
    typedef typename std::priority_queue<T, Container, Compare>::container_type::const_iterator const_iterator;
    
    const_iterator find(const T & t) const {
        auto first = this->c.cbegin();
        auto last = this->c.cend();
        
        while (first != last) {
            if (*first == t) return first;
            ++first;
        }
        
        return last;
    }
    
    const_iterator begin() { return this->c.cbegin(); }
    const_iterator end() { return this->c.cend(); }
};
} // astar

#endif /* myheap_h */
