#include <iostream>
#include <string>

using namespace std;

const int ArSize = 10;

void strcount(const string &s);

int main() {
    string input;
    
    cout << "Enter a line:" << endl;
    getline(cin, input);
    while (cin) {
        strcount(input);
        cout << "Enter next line (empty line to quit):" << endl;
        getline(cin, input);
        if (input == "") break;
    }
    cout << "Bye" << endl;
    
    return 0;
}

void strcount(const string &s) {
    static int total = 0;
    cout << "\"" << s << "\" contains " << s.size() << " characters" << endl;
    total += s.size();
    cout << total << " characters total\n";
}
