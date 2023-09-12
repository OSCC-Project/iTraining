#include <iostream>
#include <string>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_box(const box b);
void calc_volume(box *b);

int main() {
    box b = {"this is a box.", 1, 2, 3};

    show_box(b);
    calc_volume(&b);
    show_box(b);

    return 0;
}

void show_box(const box b) {
    cout << "maker: " << string(b.maker) << endl;
    cout << "height: " << b.height << endl;
    cout << "width: " << b.width << endl;
    cout << "length: " << b.length << endl;
    cout << "volume: " << b.volume << endl;
}

void calc_volume(box *b) {
    b->volume = b->height * b->length * b->width;
}
