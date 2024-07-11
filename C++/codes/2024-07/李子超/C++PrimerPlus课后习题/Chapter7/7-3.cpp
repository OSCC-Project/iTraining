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
	box testbox{ "testbox",10.0,20.0,30.0 };   //创建10*20*30的大小的箱子，未提供容量，默认为0.0
	show_box(testbox);         //显示成员的值
	setVolume(&testbox);       //设置volunme成员的值
	show_box(testbox);         //重新显示成员的值
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
