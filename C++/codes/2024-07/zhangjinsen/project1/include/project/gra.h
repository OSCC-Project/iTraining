#ifndef GRID_H
#define GRID_H
#include<bits/stdc++.h>


class Grid_ {
private:
    std::vector<std::vector<int>> data;
    

public:
    int rows;
    int cols;
    // 构造函数，初始化网格大小和默认值
    Grid_(int rows, int cols, int initialValue = 0) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<int>(cols, initialValue));
    }

    // 设置网格中指定单元格的值
    void setValue(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        }
    }

    // 获取网格中指定单元格的值
    int getValue(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        }
        return -1;  // 返回-1表示无效索引
    }

    // 打印整个网格
    void print() const {
        for (const auto& row : data) {
            for (int cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif