#include <iostream>

using namespace std;

#include <cstring>

struct stringy {
    char * str;
    int ct;
};

void set(struct stringy &in_stringy, char * in_string);
void show(const struct stringy &in_stringy, int print_times = 1);
void show(const char * str, int print_times = 1);

int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}

void set(struct stringy &in_stringy, char * in_string) {
    int string_length = strlen(in_string);
    in_stringy.str = new char(string_length + 1);
    strcpy(in_stringy.str, in_string);
    in_stringy.ct = string_length;
}

void show(const struct stringy &in_stringy, int print_times) {
    for (int i = 0; i < print_times; i++) {
        cout << "member string of struct stringy: " << in_stringy.str << endl;
    }
}

void show(const char * str, int print_times) {
    for (int i = 0; i < print_times; i++) {
        cout << "Print char string: " << str << endl;
    }
}
