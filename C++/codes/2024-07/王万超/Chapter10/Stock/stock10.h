#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>
#include <iostream>
class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();// default constructor
    Stock(const std::string & co, long n = 0, double pr = 0.0);//  constructor
    ~Stock();// destructor

    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    const Stock & topval(const Stock & s) const;
};


//类的实现

Stock::Stock() // default constructor
{
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}
Stock::Stock(const std::string & co, long n, double pr) // constructor
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock() // destructor
{ 
}

//buy
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}
//sell
void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        std::cout<<"Number of shares sold can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        std::cout << "You can't sell more than you have! "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }

}
//update
void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

//show
void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "Company: " << company
         << " Shares: " << shares << '\n'
         << " Share Price: $" << share_val;
    // set format to #.##
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';
    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

#endif