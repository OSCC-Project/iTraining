#include <iostream>
using std::cout;
using std::endl;
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void show_box(const box b);
void setVolume(box *b);
int main() {
	box testbox{ "testbox",10.0,20.0,30.0 };   //����10*20*30�Ĵ�С�����ӣ�δ�ṩ������Ĭ��Ϊ0.0
	show_box(testbox);         //��ʾ��Ա��ֵ
	setVolume(&testbox);       //����volunme��Ա��ֵ
	show_box(testbox);         //������ʾ��Ա��ֵ
	return 0;
}

void show_box(const box b)
{
	cout << b.maker << " " << b.height << " " << b.width << " " << b.length << " " << b.volume << endl;
}

void setVolume(box * b)
{
	b->volume = b->height*b->length*b->width;
}
