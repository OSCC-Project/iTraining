#include <iostream>
#include <string>

using namespace std;

string& toUpperCase(string& str);

int main() {
    string input;
    while (true) {
        cout << "Enter a string (q to quit): ";
        getline(cin, input);
        if (input == "q") break;
        cout << toUpperCase(input) << endl;
    }
    cout << "Bye." << endl;
    return 0;
}

string& toUpperCase(string& str) {
    for (char& c : str) {
        c = toupper(c);
    }
    return str;
}
