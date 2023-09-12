#include <iostream>

using namespace std;

const int Seasons = 4;
const char *Snames[] = {"Spring", "Summer", "Fall", "Winter"};

struct Expense {
    double value[Seasons];
};

void fill(double pa[]);
void show(double da[]);
void fill(Expense &e);
void show(Expense &e);

int main() {
    double expenses[Seasons];
    Expense e;

    fill(expenses);
    show(expenses);

    fill(e);
    show(e);

    return 0;
}

void fill(double pa[]) {
    for (int i = 0; i < Seasons; i++) {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pa[i];
    }
}

void show(double da[]) {
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++) {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

void fill(Expense &e) {
    fill(e.value);
}

void show(Expense &e) {
    show(e.value);
}
