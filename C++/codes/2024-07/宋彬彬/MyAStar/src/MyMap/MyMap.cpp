#include"MyMap.hpp"

MyMap::MyMap(int length,int width):_map_length(length),_map_width(width)
{
    _map_points_number = length * width;

    _map_points.resize(_map_length);
    for (size_t i = 0; i < _map_length; ++i) {
        _map_points[i].resize(_map_width, nullptr);
    }

    //initial_map();
}

MyMap::~MyMap()
{
    for (size_t i = 0; i < _map_length; ++i) {
        for (size_t j = 0; j < _map_width; ++j) {
            delete _map_points[i][j];
        }
    }
}

double MyMap::calculate_linear_distance(MyPoint p1, MyPoint p2)
{
    int p1_x,p1_y;
    int p2_x,p2_y;

    p1_x = p1.get_coordinate_X();
    p1_y = p1.get_coordinate_Y();
    p2_x = p2.get_coordinate_X();
    p2_y = p2.get_coordinate_Y();

    return std::sqrt((p1_x-p2_x)*(p1_x-p2_x) + (p1_y-p2_y)*(p1_y-p2_y));
}

double MyMap::calculate_manhattan_distance(MyPoint p1, MyPoint p2)
{
    int p1_x,p1_y;
    int p2_x,p2_y;

    p1_x = p1.get_coordinate_X();
    p1_y = p1.get_coordinate_Y();
    p2_x = p2.get_coordinate_X();
    p2_y = p2.get_coordinate_Y();


    return (std::abs(p1_x-p2_x)+std::abs(p1_y-p2_y));
}

void MyMap::set_map_length(int length)
{
    _map_length = length;
}
void MyMap::set_map_width(int width)
{
    _map_width = width;
}
void MyMap::initial_map()
{
    for(int i=0;i<_map_length;i++)
    {
        for(int j=0;j<_map_width;j++)
        {
            MyPoint *tmp_point = new MyPoint(i,j,(i*_map_width)+j);
            _map_points[i][j] = tmp_point;
        }
    }
}

void MyMap::draw_map()
{
    for(int i=0;i<_map_length;i++)
    {
        for(int j=0;j<_map_width;j++)
        {
            std::cout<<"* ";
        }
        std::cout<<std::endl;
    }
}
