# Modern C++特性演示

本文档展示了几个Modern C++特性，包括移动构造函数、智能指针、Lambda表达式等。每个特性都有示例代码及其运行结果。

## 移动构造函数和移动赋值运算符

### 示例代码
  ```cpp
#include <iostream>
#include <utility> 

class MoveConstruction {
public:
    int* data;
    size_t size;

    // 构造函数
    MoveConstruction(size_t sz) : size(sz), data(new int[sz]) {
        std::cout << "Constructing\n";
    }

    // 移动构造函数
    MoveConstruction(MoveConstruction&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move Constructing\n";
    }

    // 移动赋值运算符
    MoveConstruction& operator=(MoveConstruction&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move Assigning\n";
        }
        return *this;
    }

    // 析构函数
    ~MoveConstruction() {
        delete[] data;
        std::cout << "Destructing\n";
    }
};

int main() {
    
    MoveConstruction a(10);
    MoveConstruction b(std::move(a)); 
    std::cout<< "size of a:" << a.size <<std::endl;
    std::cout<< "size of b:" << b.size <<std::endl;
    MoveConstruction c(20);
    c = std::move(b); 
    std::cout<< "size of c:" << c.size <<std::endl;
    return 0;
}
```
###  运行结果

Constructing
Move Constructing
size of a:0
size of b:10
Constructing
Move Assigning
size of c:10
Destructing
Destructing
Destructing

## 智能指针

### 示例代码
```cpp
#include <iostream>
#include <memory> 

int main() {
    
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    std::cout << "Unique Pointer Value: " << *ptr << std::endl;

    std::shared_ptr<int> ptr1 = std::make_shared<int>(20);
    std::shared_ptr<int> ptr2 = ptr1;
    std::cout << "Shared Pointer Value of ptr1: " << *ptr1 << ", Use Count: " << ptr1.use_count() << std::endl;
    std::cout << "Shared Pointer Value of ptr2: " << *ptr2 << ", Use Count: " << ptr2.use_count() << std::endl;
    ptr2.reset();
    std::cout << "Shared Pointer Value of ptr1 After reset: " << *ptr1 << ", Use Count: " << ptr1.use_count() << std::endl;
    return 0;
}
```
### 运行结果

Unique Pointer Value: 10
Shared Pointer Value of ptr1: 20, Use Count: 2
Shared Pointer Value of ptr2: 20, Use Count: 2
Shared Pointer Value of ptr1 After reset: 20, Use Count: 1

## Lambda 表达式
### 示例代码
  ```cpp
#include <iostream>

int main() {
   
   auto lam = [](int a, int b) { return a + b; };
    std::cout << "1 + 9 :"<< lam(1, 9) << std::endl;

    int m = 0, n = 0;
    [&, n](int a) mutable { m = (++n) + (++a); }(4);
    std::cout <<"m : "<< m <<"\nn : " << n << std::endl;

    return 0;
}

  ```
### 运行结果

1 + 9 :10
m : 6
n : 0