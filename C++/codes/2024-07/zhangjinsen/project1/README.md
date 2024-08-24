现代C++的特点：
1. **性能**：C++以其高效的性能著称，特别适合对性能要求高的应用程序。
2. **控制**：C++提供了对硬件和内存的精细控制，使我能够编写更优化的代码。
3. **多范式编程**：现代C++支持多种编程范式，包括面向对象编程、泛型编程和函数式编程。

### 学习资源
在学习现代C++的过程中，我主要参考了以下资源：

- **书籍**：
  - 《C++ Primer Plus》
  - 《现代C++教程：快速上手》
  - 《C++并发编程实战》
- **文档和博客**：
  - [cppreference.com](https://en.cppreference.com)
  - [Stack Overflow](https://stackoverflow.com)

### 学习过程
我的学习主要集中在以下几个方面：

#### 1. C++11/14/17/20的新特性

- **自动类型推导（auto）**
- **范围for循环**
- **智能指针（unique_ptr, shared_ptr）**
- **lambda表达式**
- **constexpr和编译时计算**
- **右值引用和移动语义**
- **并发编程（std::thread, std::async）**

#### 2. C++标准库

- **STL容器和算法**
- **正则表达式**
- **文件系统库**
- **时间库（chrono）**





## 项目概述

本项目是一个使用A*算法实现的路径搜索程序，它允许用户在一个网格地图上指定起点、终点和障碍物，然后找出从起点到终点的最短路径。

## 功能特性

- 用户交互式输入地图尺寸、障碍物位置和起始/终点坐标。
- 支持在一个自定义的网格类`Grid_`上使用A*算法进行路径搜索。
- 通过Google Test框架提供了单元测试，确保算法的正确性。

## 技术栈

- C++17
- Google Test (用于单元测试)

## 项目结构

```plaintext
project/
│
├── include/                  # 项目头文件
│   ├── project/
│   │   ├── a_.h             # A*算法声明
│   │   └── gra.h            # 网格类声明
│
├── src/                      # 项目源文件
│   ├── main.cpp              # 主程序入口
│   └── astar.cpp             # A*算法实现
│
└── test/                     # 单元测试文件
    ├── astar_test.cpp        # A*算法测试
```

## 编译与运行

1. 确保系统中已安装C++编译器和Google Test。
2. 克隆项目到本地机器。
3. 使用CMake或其他构建系统编译项目。
4. 运行编译后的程序并根据提示输入相应的参数。

## 使用方法

1. 启动程序后，首先输入地图的行数和列数。
2. 输入障碍物的数量，并按提示输入每个障碍物的具体位置。
3. 输入起点和终点的坐标。
4. 程序将输出从起点到终点的路径。

## 单元测试

项目中包含了单元测试，用于验证A*算法的正确性。测试用例包括：

- `ASTAR::Assertions`：测试算法在特定网格布局下是否能找到预期长度的路径。
- `ASTAR::Assertions2`：另一个测试用例

## 代码示例

以下是主程序的代码片段：

```cpp
int main() {
    // ... 用户输入和地图初始化代码 ...

    AStarAlgorithm astar;
    std::vector<std::pair<int, int>> path = astar.findPath(grah, start, goal);

    std::cout << "Path: ";
    for (const auto& p : path) {
        std::cout << "(" << p.first << "," << p.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}
```



## 作者信息

- **作者**：张锦森

- **GitHub**：[@bkjx-qyj](https://github.com/qyj-bkjx)

