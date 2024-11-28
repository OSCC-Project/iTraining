#include <iostream>
#include <string>

class Bank
{
public:
    Bank(std::string name, std::string id)
    {
        _name = name;
        _id = id;
    }
    Bank(std::string name, std::string id, long long count)
    {
        _name = name;
        _id = id;
        _count = count;
    }
    void show()
    {
        std::cout << _name << std::endl << _id 
        << std::endl << _count << std::endl;
    }
    void add(long long val)
    {
        _count += val;
    }
    void del(long long val)
    {
        _count -= val;
    }

private:
    std::string _name;
    std::string _id;
    long long   _count = 0;
};

int main()
{
    Bank bank("test", "000001");
    bank.show();
    bank.add(10000);
    bank.show();
    bank.del(1000);
    bank.show();
    return 0;
}