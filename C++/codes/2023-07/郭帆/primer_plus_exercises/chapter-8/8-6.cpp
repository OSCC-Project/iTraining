#include <iostream>

using namespace std;

template <typename T>
T maxn(T arr[], int n);

template <> const char * maxn(const char *arr[], int n);

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    double b[] = {4, 3, 2, 1};
    const char *c[] = {"hello", "a", "b", "world!", "c"};

    cout << maxn(a, 6) << endl;
    cout << maxn(b, 4) << endl;
    cout << maxn(c, 5) << endl;

    return 0;
}

template <typename T>
T maxn(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

template <> const char * maxn(const char *arr[], int n) {
    int max_len = strlen(arr[0]);
    const char * longest_str = arr[0];
    for (int i = 1; i < n; i++) {
        int l = strlen(arr[i]);
        if (l > max_len) {
            max_len = l;
            longest_str = arr[i];
        }
    }
    return longest_str;
}
