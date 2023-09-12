#include<iostream>
#include"Point.h"
#include"Map.h"

int main()
{

    Map m_map(4, 8);
    m_map.insertFirst(0, 0);
    m_map.insertFinal(3, 7);
    m_map.insertAbs(2, 0);
    m_map.insertAbs(2, 1);
    m_map.insertAbs(3, 0);
    m_map.insertAbs(2, 3);
    m_map.insertAbs(2, 4);
    m_map.insertAbs(0, 4);
    m_map.insertAbs(0, 5);
    m_map.insertAbs(0, 6);
    m_map.insertAbs(0, 7);
    m_map.insertAbs(1, 5);
    m_map.insertAbs(1, 6);
    m_map.insertAbs(1, 7);
    std::cout<<"寻路以前的地图为："<<std::endl;
    std::cout << m_map;
    m_map.aStar();
    std::cout<<"\n寻路以后的地图为："<<std::endl;
    std::cout << m_map;
    m_map.getPath();

    //Assignments_qt w; 
    //MyPaint window;
    //window.show();


}
