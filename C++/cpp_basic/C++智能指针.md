# 一、为什么需要智能指针

- 示例： 

```
double Division(int a, int b)
{
    // 当b == 0时抛出异常
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (double)a / (double)b;
}
void Func()
{
    //如果发生除0错误抛出异常在外部进行捕获，那么下面的array没有得到释放
    int* array = new int[10];

    int len, time;
    cin >> len >> time;
    cout << Division(len, time) << endl;

    cout << "delete []" << array << endl;
    delete[] array;
}
int main()
{
    try
    {
        Func();
    }
    catch (const char* errmsg)
    {
        cout << errmsg << endl;
    }
    return 0;
}
```

- 效果： 

![image-20220520104728920](https://typoracole.oss-cn-guangzhou.aliyuncs.com/img/image-20220520104728920.png)

- 异常安全问题: 

> 如果在malloc和free之间如果存在抛异常，那么还是有内存泄漏

- 一般解决办法：重新抛出时处理 

```
double Division(int a, int b)
{
    // 当b == 0时抛出异常
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (double)a / (double)b;
}
void Func()
{
    // 这里捕获异常后并不处理异常，异常还是交给外面处理
    // 这里捕获了再重新抛出去
    int* array = new int[10];
    try {
        int len, time;
        cin >> len >> time;
        cout << Division(len, time) << endl;
    }
    catch (...)
    {
        cout << "delete []" << array << endl;
        delete[] array;
        throw;
    }
    // ...
    cout << "delete []" << array << endl;
    delete[] array;
}
int main()
{
    try
    {
        Func();
    }
    catch (const char* errmsg)
    {
        cout << errmsg << endl;
    }
    return 0;
}
```

> 注：这种方式比较麻烦，不实用，由此引入了智能指针

# 二、内存泄漏

- 什么是内存泄漏： 

> 内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费

- 内存泄漏的危害： 

> 长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致响应越来越慢，最终卡死

- C/C++程序中一般我们关心两种方面的内存泄漏： 

1. 堆内存泄漏： 

> 堆内存指的是程序执行中依据须要分配通过malloc / calloc / realloc / new等从堆中分配的一块内存，用完后必须通过调用相应的 free或者delete 删掉。假设程序的设计错误导致这部分内存没有被释放，那么以后这部分空间将无法再被使用，就会产生Heap Leak

1. 系统资源泄漏： 

> 指程序使用系统分配的资源，比方套接字、文件描述符、管道等没有使用对应的函数释放掉，导致系统资源的浪费，严重可导致系统效能减少，系统执行不稳定

- 如何避免内存泄漏： 

> 1. 工程前期良好的设计规范，养成良好的编码规范，申请的内存空间记着匹配的去释放。ps：这个理想状态。但是如果碰上异常时，就算注意释放了，还是可能会出问题 
> 2. 采用RAII思想或者智能指针来管理资源 
> 3. 有些公司内部规范使用内部实现的私有内存管理库。这套库自带内存泄漏检测的功能选项 
> 4. 出问题了使用内存泄漏工具检测。ps：不过很多工具都不够靠谱，或者收费昂贵 

- 总结: 

> 内存泄漏非常常见，解决方案分为两种：
>
> 1、事前预防型。如智能指针等
>
> 2、事后查错型。如泄漏检测工具 

# 三、智能指针

## 1、RAII

- 概念及介绍： 

> 1. RAII（Resource Acquisition Is Initialization）是一种利用对象生命周期来控制程序资源（如内存、文件句柄、网络连接、互斥量等等）的简单技术 
> 2. 在对象构造时获取资源，接着控制对资源的访问使之在对象的生命周期内始终保持有效，最后在对象析构的时候释放资源。即我们实际上把管理一份资源的责任托管给了一个对象 

- 好处： 

> 1. 不需要显式地释放资源
> 2. 对象所需的资源在其生命期内始终保持有效 

- 示例： 

```
// 使用RAII思想设计的SmartPtr类
template<class T>
class SmartPtr {
public:
    SmartPtr(T* ptr = nullptr)
        : _ptr(ptr)
    {}
    ~SmartPtr()
    {
        if (_ptr)
            delete _ptr;
    }
private:
    T* _ptr;
};
```



- 注意： 

> 1. RAII思想除了可以用来设计智能指针，还可以用来设计守卫锁，防止异常安全导致的死锁问题 
> 2. C++11中引入了lock_guard和unique_lock来解决死锁的问题 
> 3. 大部分情况下，两者的功能是一样的，不过**unique_lock比lock_guard更灵活**：unique_lock提供了lock, unlock, try_lock等接口. lock_guard没有多余的接口；构造函数时拿到锁，析构函数时释放锁 lock_guard比unique_lock要省时 

- 模拟实现lock_guard： 

```
template<class Mutex>
class LockGuard
{
public:
    LockGuard(Mutex& mtx)
        :_mutex(mtx)
    {
        _mutex.lock();
    }
    ~LockGuard()
    {
        _mutex.unlock();
    }
    LockGuard(const LockGuard<Mutex>&) = delete;
private:
    // 注意这里必须使用引用，否则锁的就不是一个互斥量对象
    Mutex& _mutex;
};
```

## 2、智能指针的原理

> 上述的SmartPtr还不能将其称为智能指针，因为它还不具有指针的行为
>
> 指针可以解引用，也可以通过->去访问所指空间中的内容，因此模板类中还得需要将***\** 、**->**重载下，才可让其像指针一样去使用

- 示例： 

```
template<class T>
class SmartPtr {
public:
    SmartPtr(T* ptr = nullptr)
        : _ptr(ptr)
    {}
    ~SmartPtr()
    {
        if (_ptr)
            delete _ptr;
    }
    T& operator*() { return *_ptr; }
    T* operator->() { return _ptr; }
private:
    T* _ptr;
};
```

- 智能指针的原理： 

> 1. RAII特性(构造时初始化，析构时释放) 
> 2. 重载operator*和opertaor->，具有像指针一样的行为 

## 3、std::auto_ptr

- 概念及介绍： 

> 1. C++98版本的库中就提供了auto_ptr的智能指针 
> 2. auto_ptr的实现原理：管理权转移的思想，即当拷贝和赋值时将智能指针管理的内存地址进行转移，也就是一份空间内存只有一个智能指针进行管理 

- 示例： 

```
class Date
{
public:
    Date() { cout << "Date()" << endl; }
    ~Date() { cout << "~Date()" << endl; }
    int _year;
    int _month;
    int _day;
};
int main()
{
    auto_ptr<Date> ap(new Date);
    auto_ptr<Date> copy(ap);
    // auto_ptr的问题：当对象拷贝或者赋值后，前面的对象就悬空了
    // C++98中设计的auto_ptr问题是非常明显的，所以实际中很多公司明确规定了不能使用auto_ptr
    ap->_year = 2018;
    return 0;
}
```

- 效果： 

![image-20220520111711710](https://typoracole.oss-cn-guangzhou.aliyuncs.com/img/image-20220520111711710.png)

- 模拟实现： 

```
//auto_ptr:管理权转移-存在问题
    template<class T>
    class auto_ptr
    {
        public:
        auto_ptr(T* ptr)
            :_ptr(ptr)
            {}
        auto_ptr(auto_ptr<T>& ap)
            :_ptr(ap._ptr)// 转移资源
            {
                ap._ptr = nullptr;
            }
        auto_ptr<T>& operator=(auto_ptr<T>& ap)
        {
            if (this != &ap)//防止自我赋值
            {
                cout << "~auto_ptr:" << _ptr << endl;
                delete _ptr;
                _ptr = ap._ptr;
                ap._ptr = nullptr;
            }
            return *this;
        }
        ~auto_ptr()
        {
            if (_ptr)
            {
                cout << "~auto_ptr:" << _ptr << endl;
                delete _ptr;
            }
        }
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return &_ptr;
        }
        private:
        T* _ptr;
    };
```

## 4、std::unique_ptr

- 概念及介绍： 

> 1. C++11中开始提供更靠谱的unique_ptr 
> 2. unique_ptr的实现原理：简单粗暴的防拷贝，即只有一个智能指针管理资源，并且不会发生拷贝和赋值 

- 示例： 

```
//unique_ptr:不存在拷贝和赋值-没有管理权的转移
    template<class T>
    class unique_ptr
    {
    public:
        unique_ptr(T* ptr)
            :_ptr(ptr)
        {}
        unique_ptr(unique_ptr<T>& ap) = delete;
        unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;
        ~unique_ptr()
        {
            if (_ptr)
            {
                cout << "~unique_ptr:" << _ptr << endl;
                delete _ptr;
            }
        }
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return &_ptr;
        }
    private:
        T* _ptr;
    };
```

- 效果： 

![image-20220520113225144](https://typoracole.oss-cn-guangzhou.aliyuncs.com/img/image-20220520113225144.png)

- 模拟实现： 

[复制代码](#)

```
//unique_ptr:不存在拷贝和赋值-没有管理权的转移
    template<class T>
    class unique_ptr
    {
    public:
        unique_ptr(T* ptr)
            :_ptr(ptr)
        {}
        unique_ptr(unique_ptr<T>& ap) = delete;
        unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;
        ~unique_ptr()
        {
            if (_ptr)
            {
                cout << "~unique_ptr:" << _ptr << endl;
                delete _ptr;
            }
        }
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return &_ptr;
        }
    private:
        T* _ptr;
    };
```

> 注：C++98防拷贝的方式：只声明不实现+声明成私有；C++11防拷贝的方式修饰函数为delete 

## 5、std::shared_ptr

- 概念及介绍： 

> 1. C++11中开始提供更靠谱的并且支持拷贝的shared_ptr 
> 2. shared_ptr的原理：是通过引用计数的方式来实现多个shared_ptr对象之间共享资源，只有最后一个智能指针析构才进行资源的释放 

- 注意： 

> 1. shared_ptr在其内部，给每个资源都维护了着一份计数，用来记录该份资源被几个对象共享 
> 2. 在对象被销毁时(也就是析构函数调用)，就说明自己不使用该资源了，对象的引用计数减一 
> 3. 如果引用计数是0，就说明自己是最后一个使用该资源的对象，必须释放该资源 
> 4. 如果不是0，就说明除了自己还有其他对象在使用该份资源，不能释放该资源，否则其他对象就成野指针了 
> 5. 由于资源共享，需要使用引用计数，也就是计数也是共享的，那么对计数的操作需要保证原子性，否则会造成数据混乱 

- 示例： 

[复制代码](#)

```
int main()
{
    // shared_ptr通过引用计数支持智能指针对象的拷贝
    shared_ptr<Date> sp(new Date);
    shared_ptr<Date> copy(sp);
    cout << "ref count:" << sp.use_count() << endl;
    cout << "ref count:" << copy.use_count() << endl;
    return 0;
}
```

- 效果： 

![image-20220520113318293](https://typoracole.oss-cn-guangzhou.aliyuncs.com/img/image-20220520113318293.png)

- 模拟实现： 

[复制代码](#)

```
    //shared_ptr:多个智能指针管理一个内存资源，最后一个智能指针释放内存
    template<class T>
    class shared_ptr
    {
    public:
        explicit shared_ptr(T* ptr)
            :_ptr(ptr)
            , _pCount(new int(1))
            , _mtx(new mutex)
        {}
        void add_pCount()
        {
            // 加锁或者使用加1的原子操作
            _mtx->lock();
            ++(*_pCount);
            _mtx->unlock();
        }
        void release_pCount()
        {
            // 引用计数减1，如果减到0，则释放资源
            bool flg = false;
            _mtx->lock();
            --(*_pCount);
            if ((*_pCount) == 0 && _ptr)
            {
                cout << "~shared_ptr:" << _ptr << endl;
                D del;
                delete _ptr;
                delete _pCount;
                flg = true;
            }
            _mtx->unlock();
            if (flg)
                delete _mtx;
        }
        shared_ptr(shared_ptr<T>& sp)
            :_ptr(sp._ptr)
            , _pCount(sp._pCount)
            , _mtx(sp._mtx)
        {
            add_pCount();
        }
        //shared_ptr<T>& operator=(shared_ptr<T>& sp)
        //{
        //    if (_ptr != sp._ptr)//管理资源地址相同则不用处理
        //    {
        //        release_pCount();
        //        _ptr = sp._ptr;
        //        _pCount = sp._pCount;
        //        _mtx = sp._mtx;
        //        add_pCount();
        //    }
        //  return *this;
        //}
        void swap(shared_ptr<T>& sp)
        {
            std::swap(_ptr, sp._ptr);
            std::swap(_pCount, sp._pCount);
            std::swap(_mtx, sp._mtx);
        }
        //现代式写法
        shared_ptr<T>& operator=(shared_ptr<T> sp)
        {
            swap(sp);
            return *this;
        }
        ~shared_ptr()
        {
            release_pCount();
        }
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return &_ptr;
        }
        T* get()
        {
            return _ptr;
        }
        size_t use_count()
        {
            return *_pCount;
        }
    private:
        T* _ptr;//管理的内存资源
        int* _pCount;//计数
        mutex* _mtx;//多线程互斥
        //堆上开辟-多个智能指针共享计数和互斥锁
    };
```

- shared_ptr的线程安全分为两方面： 

> 1. 智能指针对象中引用计数是多个智能指针对象共享的，引用计数同时++或--操作不是原子的，存在线程数据安全问题，会导致资源未释放或者程序崩溃的问题，即内部计数操作需要加锁 
> 2. 智能指针管理的对象存放在堆上，两个线程中同时去访问，会导致线程安全问题，即调用指针对象去访问资源时需要自行保证访问的互斥，确保线程安全 

- 示例： 

[复制代码](#)

```
// 1.演示引用计数线程安全问题，就把AddRefCount和SubRefCount中的锁去掉
// 2.演示可能不出现线程安全问题，因为线程安全问题是偶现性问题，main函数的n改大一些概率就变大了，就容易出现了。
// 3.下面代码我们使用SharedPtr演示，是为了方便演示引用计数的线程安全问题，将代码中的SharedPtr换成shared_ptr进行测试，可以验证库的shared_ptr，发现结论是一样的

void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
    cout << sp.Get() << endl;
    for (size_t i = 0; i < n; ++i)
    {
        // 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
        SharedPtr<Date> copy(sp);
        // 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最终看到的结果，并一定是加了2n
        copy->_year++;
        copy->_month++;
        copy->_day++;
    }
}
int main()
{
    SharedPtr<Date> p(new Date);
    cout << p.Get() << endl;
    const size_t n = 100;
    thread t1(SharePtrFunc, p, n);
    thread t2(SharePtrFunc, p, n);
    t1.join();
    t2.join();
    cout << p->_year << endl;
    cout << p->_month << endl;
    cout << p->_day << endl;
    return 0;
}
```

## 6、std::weak_ptr

- 概念及引入： 

> 一般来说shared_ptr可以满足资源管理的大部分情况，但是也有些情况是shared_ptr不能处理的，这时候就需要使用weak_ptr

- 示例：std::shared_ptr的循环引用 

[复制代码](#)

```
struct` `ListNode``{``  ``int` `_data;``  ``shared_ptr<ListNode> _prev;``  ``shared_ptr<ListNode> _next;``  ``~ListNode() { cout << ``"~ListNode()"` `<< endl; }``};``int` `main()``{``  ``shared_ptr<ListNode> node1(``new` `ListNode);``  ``shared_ptr<ListNode> node2(``new` `ListNode);``  ``cout << node1.use_count() << endl;``  ``cout << node2.use_count() << endl;``  ``node1->_next = node2;``  ``node2->_prev = node1;``  ``cout << node1.use_count() << endl;``  ``cout << node2.use_count() << endl;``  ``return` `0;``}
```

- 效果： 

![image-20220520210808632](https://typoracole.oss-cn-guangzhou.aliyuncs.com/img/image-20220520210808632.png)

- 循环引用分析： 

> 1. node1和node2两个智能指针对象指向两个节点，引用计数变成1，我们不需要手动delete 
> 2. node1的_ next指向node2，node2的_prev指向node1，引用计数变成2 
> 3. node1和node2析构，引用计数减到1，但是_ next还指向下一个节点，_ prev还指向上一个节点 
> 4. 也就是说_ next析构了，node2的计数减到0，node2就释放了；_prev析构了，node1就释放了 
> 5. 但是_ next属于node1的成员，node1释放了，_ next才会析构，而node1由_ prev管理，_prev属于node2的成员，所以这就叫循环引用，谁也不会释放 

- 示图： 

![image-20220520211018174](https://typoracole.oss-cn-guangzhou.aliyuncs.com/img/image-20220520211018174.png)

- 解决方案： 

> 在引用计数的场景下，把节点中的_ prev和_ next改成weak_ptr就可以了

- weak_ptr原理： 

> node1->_ next = node2;和node2->_ prev = node1;时weak_ptr的_ next和_ prev不会增加node1和node2的引用计数，即weak_ptr不会参与空间资源的管理，只是作为一个解决循环引用的工具

- 示例： 

[复制代码](#)

```
struct ListNode
{
    int _data;
    shared_ptr<ListNode> _prev;
    shared_ptr<ListNode> _next;
    ~ListNode() { cout << "~ListNode()" << endl; }
};
int main()
{
    shared_ptr<ListNode> node1(new ListNode);
    shared_ptr<ListNode> node2(new ListNode);
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    node1->_next = node2;
    node2->_prev = node1;
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    return 0;
}
```

- 效果： 

![image-20220520213830845](https://typoracole.oss-cn-guangzhou.aliyuncs.com/img/image-20220520213830845.png)

- 模拟实现： 

[复制代码](#)

```
struct ListNode
{
    int _data;
    weak_ptr<ListNode> _prev;
    weak_ptr<ListNode> _next;
    ~ListNode(){ cout << "~ListNode()" << endl; }
};
int main()
{
    shared_ptr<ListNode> node1(new ListNode);
    shared_ptr<ListNode> node2(new ListNode);
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    node1->_next = node2;
    node2->_prev = node1;
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    return 0;
}
```

## 7、删除器

- 概念及引入： 

> 1. 对于管理的资源并不一定就只是通过new出来的，还存在其他的方式获取的资源对象该如何通过智能指针管理呢 
> 2. 这里就需要shared_ptr设计一个删除器来解决，对于不一样的资源使用其对应的方式进行资源的回收 

- 示例： 

[复制代码](#)

```
// 仿函数的删除器
template<class T>
struct FreeFunc {
    void operator()(T* ptr)
    {
        cout << "free:" << ptr << endl;
        free(ptr);
    }
};
template<class T>
struct DeleteArrayFunc {
    void operator()(T* ptr)
    {
        cout << "delete[]" << ptr << endl;
        delete[] ptr;
    }
};
int main()
{
    FreeFunc<int> freeFunc;
    shared_ptr<int> sp1((int*)malloc(4), freeFunc);
    DeleteArrayFunc<int> deleteArrayFunc;
    shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);
    return 0;
}
```

- 效果： 

![image-20220520214727772](https://typoracole.oss-cn-guangzhou.aliyuncs.com/img/image-20220520214727772.png)

- 简单模拟实现删除器shared_ptr: 

[复制代码](#)

```
    template<class T>
    class DelRef
    {
    public:
        void operator()(T*& ptr)
        {
            if (ptr)
            {
                delete ptr;
                ptr = nullptr;
            }
        }
    };
    template<class T>
    class Free
    {
    public:
        void operator()(T*& ptr)
        {
            if (ptr)
            {
                free(ptr);
                ptr = nullptr;
            }
        }
    };
    class FClose
    {
    public:
        void operator()(FILE*& pf)
        {
            if (pf)
            {
                fclose(pf);
                pf = nullptr;
            }
        }
    };
    //shared_ptr:多个智能指针管理一个内存资源，最后一个智能指针释放内存
    template<class T,class D=DefaultDel<T>>
    class shared_ptr
    {
        friend class weak_ptr<T>;
    public:
        explicit shared_ptr(T* ptr)
            :_ptr(ptr)
            , _pCount(new int(1))
            , _mtx(new mutex)
        {}
        void add_pCount()
        {
            _mtx->lock();
            ++(*_pCount);
            _mtx->unlock();
        }
        void release_pCount()
        {
            bool flg = false;
            _mtx->lock();
            --(*_pCount);
            if ((*_pCount) == 0 && _ptr)
            {
                cout << "~shared_ptr:" << _ptr << endl;
                D del;
                del(_ptr);
                delete _pCount;
                flg = true;
            }
            _mtx->unlock();
            if (flg)
                delete _mtx;
        }
        shared_ptr(shared_ptr<T,D>& sp)
            :_ptr(sp._ptr)
            , _pCount(sp._pCount)
            , _mtx(sp._mtx)
        {
            add_pCount();
        }
        //shared_ptr<T>& operator=(shared_ptr<T>& sp)
        //{
        //    if (_ptr != sp._ptr)//管理资源地址相同则不用处理
        //    {
        //        release_pCount();
        //        _ptr = sp._ptr;
        //        _pCount = sp._pCount;
        //        _mtx = sp._mtx;
        //        add_pCount();
        //    }
        //  return *this;
        //}
        void swap(shared_ptr<T,D>& sp)
        {
            std::swap(_ptr, sp._ptr);
            std::swap(_pCount, sp._pCount);
            std::swap(_mtx, sp._mtx);
        }
        //现代式写法
        shared_ptr<T>& operator=(shared_ptr<T,D> sp)
        {
            swap(sp);
            return *this;
        }
        ~shared_ptr()
        {
            release_pCount();
        }
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return &_ptr;
        }
        T* get()
        {
            return _ptr;
        }
        size_t use_count()
        {
            return *_pCount;
        }
    private:
        T* _ptr;//管理的内存资源
        int* _pCount;//计数
        mutex* _mtx;//多线程互斥
        //堆上开辟-多个智能指针共享计数和互斥锁
    };    template<class T>
    class DelRef
    {
    public:
        void operator()(T*& ptr)
        {
            if (ptr)
            {
                delete ptr;
                ptr = nullptr;
            }
        }
    };
    template<class T>
    class Free
    {
    public:
        void operator()(T*& ptr)
        {
            if (ptr)
            {
                free(ptr);
                ptr = nullptr;
            }
        }
    };
    class FClose
    {
    public:
        void operator()(FILE*& pf)
        {
            if (pf)
            {
                fclose(pf);
                pf = nullptr;
            }
        }
    };
    //shared_ptr:多个智能指针管理一个内存资源，最后一个智能指针释放内存
    template<class T,class D=DefaultDel<T>>
    class shared_ptr
    {
        friend class weak_ptr<T>;
    public:
        explicit shared_ptr(T* ptr)
            :_ptr(ptr)
            , _pCount(new int(1))
            , _mtx(new mutex)
        {}
        void add_pCount()
        {
            _mtx->lock();
            ++(*_pCount);
            _mtx->unlock();
        }
        void release_pCount()
        {
            bool flg = false;
            _mtx->lock();
            --(*_pCount);
            if ((*_pCount) == 0 && _ptr)
            {
                cout << "~shared_ptr:" << _ptr << endl;
                D del;
                del(_ptr);
                delete _pCount;
                flg = true;
            }
            _mtx->unlock();
            if (flg)
                delete _mtx;
        }
        shared_ptr(shared_ptr<T,D>& sp)
            :_ptr(sp._ptr)
            , _pCount(sp._pCount)
            , _mtx(sp._mtx)
        {
            add_pCount();
        }
        //shared_ptr<T>& operator=(shared_ptr<T>& sp)
        //{
        //    if (_ptr != sp._ptr)//管理资源地址相同则不用处理
        //    {
        //        release_pCount();
        //        _ptr = sp._ptr;
        //        _pCount = sp._pCount;
        //        _mtx = sp._mtx;
        //        add_pCount();
        //    }
        //  return *this;
        //}
        void swap(shared_ptr<T,D>& sp)
        {
            std::swap(_ptr, sp._ptr);
            std::swap(_pCount, sp._pCount);
            std::swap(_mtx, sp._mtx);
        }
        //现代式写法
        shared_ptr<T>& operator=(shared_ptr<T,D> sp)
        {
            swap(sp);
            return *this;
        }
        ~shared_ptr()
        {
            release_pCount();
        }
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return &_ptr;
        }
        T* get()
        {
            return _ptr;
        }
        size_t use_count()
        {
            return *_pCount;
        }
    private:
        T* _ptr;//管理的内存资源
        int* _pCount;//计数
        mutex* _mtx;//多线程互斥
        //堆上开辟-多个智能指针共享计数和互斥锁
    };
```

> 注：这里的模拟并不一定就是C++中真真的底层实现

## 8、C++11和boost中智能指针的关系

> 1. C++ 98 中产生了第一个智能指针auto_ptr 
> 2. C++ boost给出了更实用的scoped_ptr和shared_ptr和weak_ptr 
> 3. C++ TR1，引入了shared_ptr等。不过注意的是TR1并不是标准版 
> 4. C++ 11，引入了unique_ptr和shared_ptr和weak_ptr。需要注意的是unique_ptr对应boost的scoped_ptr。并且这些智能指针的实现原理是参考boost中的实现的