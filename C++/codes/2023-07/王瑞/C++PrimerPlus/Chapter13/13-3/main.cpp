#include "dma.h"
#include <iostream>

int main() {
  baseDMA shirt("Portabelly", 8);
  lacksDMA balloon("red", "Blimpo", 4);
  hasDMA map("Mercator", "Buffalo Keys", 5);
  std::cout << "Displaying baseDMA object:\n";
  std::cout << shirt << std::endl;
  std::cout << "Displaying lacksDMA object:\n";
  std::cout << balloon << std::endl;
  std::cout << "Displaying hasDMA object:\n";
  std::cout << map << std::endl;
  lacksDMA balloon2(balloon);
  std::cout << "Result of lacksDMA copy:\n";
  std::cout << balloon2 << std::endl;
  hasDMA map2;
  map2 = map;
  std::cout << "Result of hasDMA assignment:\n";
  std::cout << map2 << std::endl;
  std::cout << std::endl << "Shirt:\n";
  shirt.viewInfo();
  std::cout << std::endl << "Balloon:\n";
  balloon.viewInfo();
  std::cout << std::endl << "Map:\n";
  map.viewInfo();
  std::cout << std::endl << "Balloon2:\n ";
  balloon2.viewInfo();
  std::cout << std::endl << "Map2:\n";
  map2.viewInfo();

  std::cout << "\nHow many inputs: ";
  int number;
  std::cin >> number;
  std::cin.ignore();
  for (int i = 0; i < number; i++) {
    std::cout << "\nEnter 1 for baseDMA class, 2 for lacksDMA class, or 3 for "
                 "hasDMA class: ";
    char flag;
    while (std::cin >> flag && (flag != '1' && flag != '2' && flag != '3')) {
      std::cin.ignore();
      std::cout << "Enter 1, 2, or 3 please: ";
    }
    std::cin.ignore();
    if (flag == '1') {
      char *label = new char[20];
      int rating;
      std::cout << "Enter the label: ";
      std::cin.getline(label, 20);
      std::cout << "Enter the rating: ";
      std::cin >> rating;
      baseDMA *base = new baseDMA(label, rating);
      std::cout << std::endl << "Your input baseDMA is:\n";
      base->viewInfo();
    } else if (flag == '2') {
      char *label = new char[20];
      int rating;
      char *color = new char[40];
      std::cout << "Enter the label: ";
      std::cin.getline(label, 20);
      std::cout << "Enter the rating: ";
      std::cin >> rating;
      std::cin.ignore();
      std::cout << "Enter the color: ";
      std::cin.getline(color, 40);
      lacksDMA *lacks = new lacksDMA(color, label, rating);
      std::cout << std::endl << "Your input lacksDMA is:\n";
      lacks->viewInfo();
    } else if (flag == '3') {
      char *label = new char[20];
      int rating;
      char *style = new char[40];
      std::cout << "Enter the label: ";
      std::cin.getline(label, 20);
      std::cout << "Enter the rating: ";
      std::cin >> rating;
      std::cin.ignore();
      std::cout << "Enter the style: ";
      std::cin.getline(style, 40);
      hasDMA *has = new hasDMA(style, label, rating);
      std::cout << std::endl << "Your input hasDMA is:\n";
      has->viewInfo();
    }
  }

  system("pause");
  return 0;
}