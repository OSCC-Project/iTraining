/**
 * @file Visual.h
 * 
 * @brief 这个文件定义了可视化类Visualization
 * 
 * 包含了可视化函数Put_Visual()
 * 
 */
#pragma once
#include "public_header.h"
#include "Graph.h"

//!可视化函数,我知道QT可以可视化，但是我没学过QT，最近实验室事情实在太多了，浅浅用终端代替一下
class Visualization {
public:
    Visualization(Graph* ptr);
    /**
     * @brief 可视化函数，没有输入文件，输出到终端
     * 
     */
    void Put_Visual();
    ~Visualization();
private:
    Graph* _P_Graph;
};