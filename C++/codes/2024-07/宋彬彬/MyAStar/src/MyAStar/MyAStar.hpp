#include"../MyMap/MyMap.hpp"
#include <random>
#include <iomanip>
#include<cmath>
#include <algorithm>
#include<stack>
#include <fstream>
#include "../../external/termcolor.hpp"

/// @brief 算法接口，但是没封装好，应该只是一个接口工具
class MyAStar
{

public:
    MyAStar(/* args */);
    ~MyAStar();
    /// @brief 初始化地图、选定起终点、设置障碍物个数
    void initial_map();
    void set_start_end(int start_x,int start_y,int end_x,int end_y);
    void set_obstruction(int n);
    void set_map_length_width(int length,int width);
    void draw_map();
    void set_end_point(MyPoint *p);
    MyPoint *get_end_point();
    void set_start_point(MyPoint *p);
    MyPoint *get_start_point();

    double calculate_f_value(MyPoint* p1,MyPoint* p2);

    /// @brief 用id找到对应的MyPoint对象
    /// @param id 
    /// @return 返回对应点对象
    MyPoint *id_to_point(int id);
    void push_open_list(MyPoint* p);
    void pop_open_list(MyPoint* p);
    void push_close_list(MyPoint* p);
    void pop_close_list(MyPoint* p);
    /// @brief 每走一步，根据起点和当前点更新路径
    void update_path(MyPoint *p);

    /// @brief 主算法
    void a_star();

    /// @brief 将当前点周围节点加入到_tmp_list中
    /// @param p 当前点
    void create_tmp_list(MyPoint* p);

private:
    MyMap *map;
    /// @brief 长宽变量map类里也有，这里定义显得冗余了
    int _map_length;
    int _map_width;
    MyPoint *_end_point;
    MyPoint *_start_point;
    /// @brief 用于储存当前节点的周围节点
    std::vector<MyPoint *> _tmp_list;
    /// @brief 保存路径，没走一个点更换一次
    std::vector<MyPoint *> _path;
    /// @brief 程序运行文件，打印每次运行的关键数据结构用以检查异常
    std::ofstream _out_file;
    bool _no_path;
    /// @brief 开放列表，用来保存已经就算了f值的点，并作为候选点
    std::vector<MyPoint *> _open_list;
    /// @brief 已经走过的列表，不再走了
    std::vector<MyPoint *> _close_list;

};

