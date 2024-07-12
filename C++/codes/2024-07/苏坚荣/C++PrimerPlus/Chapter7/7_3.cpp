#include<iostream>
using namespace std;

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void Init(box* b);
void Show(const box* b);
void SetVolume(box* b);

int main() {
	box B;
	Init(&B);
	SetVolume(&B);
	Show(&B);
	return 0;
}

void Init(box* b) {
	cout << "请输入这个box的名称：";
	cin >> b->maker;
	cout << endl << "请分别输入这个box的高宽长：";
	cin >> b->height >> b->width >> b->length;
	cout << endl;
}

void Show(const box* b) {
	cout << "这个box的名称为：" << b->maker << endl;
	cout << "这个box的高宽长分别为：" << b->height << " " << b->width << " " << b->length << endl;
	cout << "这个box的体积为：" << b->volume << endl;
}

void SetVolume(box* b) {
	b->volume = b->height * b->width * b->length;
}