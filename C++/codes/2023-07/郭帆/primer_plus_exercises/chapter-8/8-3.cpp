#include <iostream>
#include <string>

using namespace std;

string &capitalization(string &s);

int main() {
    string s;
    while (true) {
        cout << "Enter a string (q to quit): ";
        getline(cin, s);
        if (s == "q") break;
        cout << capitalization(s) << endl;
    }
    cout << "Bye." << endl;

    return 0;
}

string &capitalization(string &s) {
    for (auto &c : s) {
        c = toupper(c);
    }
    return s;
}
