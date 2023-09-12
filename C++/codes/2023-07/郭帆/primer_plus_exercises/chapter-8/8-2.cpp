#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
    string brand;
    double weight;
    int heat;
};


CandyBar & create_candybar(CandyBar &c, const char *b = "Millennium Munch", 
                            const double w = 2.85, const int h = 350);

int main() {
    CandyBar c;
    create_candybar(c);
    cout << c.brand << ", " << c.weight << ", " << c.heat << endl;
    create_candybar(c, "hello", 1, 2);
    cout << c.brand << ", " << c.weight << ", " << c.heat << endl;

    return 0;
}

CandyBar & create_candybar(CandyBar &c, const char *b, 
                            const double w, const int h) {
    c.brand = string(b);
    c.weight = w;
    c.heat = h;

    return c;
}
