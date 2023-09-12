#include <iostream>

const int box_str = 40;
struct box {
  char maker[box_str];
  float height;
  float width;
  float length;
  float volume;
};

void show_box(box temp);
void init_box(box *temp);

int main() {
  box box_abc = {"abc", 20, 10, 20, 30};
  show_box(box_abc);
  init_box(&box_abc);
  show_box(box_abc);
  return 0;
}

void show_box(box temp) {
  std::cout << "Box informations: " << std::endl;
  std::cout << "Name: " << temp.maker << std::endl;
  std::cout << "height: " << temp.height << std::endl;
  std::cout << "width: " << temp.width << std::endl;
  std::cout << "length: " << temp.length << std::endl;
  std::cout << "volume: " << temp.volume << std::endl;
}

void init_box(box *temp) {
  temp->volume = temp->height * temp->width * temp->length;
}