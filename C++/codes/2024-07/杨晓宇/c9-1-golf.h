#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int Len = 40;

struct golf
{
    char fullname[Len];
    int handicap;
};

/**
 * @brief 设置golf
 * 
 * @param g     设置对象
 * @param name  修改后的name
 * @param hc    修改后的hc
 */
void setgolf(golf &g, const char *name, int hc);

/**
 * @brief 交互设置golf
 * 
 * @param g    设置对象
 * @return int 若人名为空返回0，否则返回1
 */
int setgolf(golf &g);

/**
 * @brief 设置handicap
 * 
 * @param g    设置对象
 * @param hc   修改后的handicap值
 */
void handicap(golf &g, int hc);

/**
 * @brief 展示golf数据
 * 
 * @param g   展示对象
 */
void showgolf(const golf &g);