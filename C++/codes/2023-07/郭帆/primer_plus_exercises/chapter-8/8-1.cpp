#include <iostream>
#include <string>

using namespace std;

void print_str(string *str, int n);

int main() {
    string s;
    int n;

    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Enter a number: ";
    cin >> n;

    print_str(&s, n);

    return 0;
}

void print_str(string *str, int n) {
    cout << n << " string left: " << *str << endl;
    if (n > 1) {
        print_str(str, --n);
    }
}
