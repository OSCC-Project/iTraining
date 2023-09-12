#include <iostream>

using namespace std;

const int MAX_LEN = 10;

int input_score(int s[], int size);
void show_score(const int s[], int size);
double calc_avg(const int s[], int size);

int main() {
    int scores[MAX_LEN] = {};
    int size = MAX_LEN;
    double avg;

    size = input_score(scores, size);
    show_score(scores, size);
    avg = calc_avg(scores, size);

    cout << "average score: " << avg << endl;

    return 0;
}

int input_score(int s[], int size) {
    int x;

    cout << "input atmost 10 scores(-1 to finish): ";

    int i;
    for (i = 0; i < size; i++) {
        cin >> x;
        if (x < 0) break;
        s[i] = x;
    }
    return i;
}

void show_score(const int s[], int size) {
    cout << "score: ";
    for (int i = 0; i < size; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}

double calc_avg(const int s[], int size) {
    double sum;

    for (int i = 0; i < size; i++) {
        sum += s[i];
    }

    return sum / size;
}
