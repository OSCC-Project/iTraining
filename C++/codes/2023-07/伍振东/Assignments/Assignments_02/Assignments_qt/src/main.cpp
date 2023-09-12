#include<iostream>
#include"Point.h"
#include"Map.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    int length;
    int weight;
    std::cout << "输入地图大小（行+列）：" << std::endl;
    std::cin >> length >> weight;
    QApplication a(argc, argv);
    Map m_map(length, weight);
    //m_map.insertFirst(0, 0);
    //m_map.insertFinal(3, 7);
    //m_map.insertAbs(2, 0);
    //m_map.insertAbs(2, 1);
    //m_map.insertAbs(3, 0);
    //m_map.insertAbs(2, 3);
    //m_map.insertAbs(2, 4);
    //m_map.insertAbs(0, 4);
    //m_map.insertAbs(0, 5);
    //m_map.insertAbs(0, 6);
    //m_map.insertAbs(0, 7);
    //m_map.insertAbs(1, 5);
    //m_map.insertAbs(1, 6);
    //m_map.insertAbs(1, 7);

    //std::cout << m_map;
    //m_map.aStar();
    //std::cout << m_map;
    //m_map.getPath();

    //Assignments_qt w; 
    //MyPaint window;
    //window.show();


    m_map.show();
    return a.exec();
}
