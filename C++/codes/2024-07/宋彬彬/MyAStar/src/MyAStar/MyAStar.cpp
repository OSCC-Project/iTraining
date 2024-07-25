#include "MyAStar.hpp"

MyAStar::MyAStar():_out_file("out.txt")
{
    map = nullptr;
    _map_length = 0;
    _map_width = 0;
    _end_point = nullptr;
    _start_point = nullptr;
    _no_path = false;
}

MyAStar::~MyAStar()
{
    
}

void MyAStar::initial_map()
{
    set_map_length_width(25,20);
    map = new MyMap(_map_length,_map_width);
    map->initial_map();
    set_start_end(3,3,10,10);
    set_obstruction(200);
}

void MyAStar::set_start_end(int start_x, int start_y, int end_x, int end_y)
{

    std::random_device rd;  // 获得一个随机种子
    std::mt19937 gen(rd()); // 使用Mersenne Twister算法的随机数引擎

    // 创建一个随机数分布（整数）
    std::uniform_int_distribution<> dis_int(1, 1000); // 在1到100之间的均匀分布

    int tmp = 0;
    tmp = (abs(start_x-end_x)+abs(start_y-end_y))/2;
    while (tmp < ((_map_length+_map_width)/3))
    {
        start_x = dis_int(gen)%_map_length;
        start_y = dis_int(gen)%_map_width;
        end_x = dis_int(gen)%_map_length;
        end_y = dis_int(gen)%_map_width;

        tmp = (abs(start_x-end_x)+abs(start_y-end_y))/2;
    }
    
    


    map->_map_points[start_x][start_y]->set_start_point();
    _start_point = map->_map_points[start_x][start_y];
    _start_point->set_start_point();
    map->_map_points[end_x][end_y]->set_end_point();
    _end_point = map->_map_points[end_x][end_y];
    _end_point->set_end_point();
}

void MyAStar::set_obstruction(int n)
{
    // 设置随机数生成器
    std::random_device rd;  // 用于种子
    std::mt19937 gen(rd()); // 采用 Mersenne Twister 算法的随机数生成器

    // 生成一个范围在 [0, 99] 之间的整数
    std::uniform_int_distribution<> dis_x(0, _map_length);
    std::uniform_int_distribution<> dis_y(0, _map_width);
    // 生成并打印 10 个随机数

    int count = 0;
    while (count < n)
    {
        int l = dis_x(gen)%_map_length;
        int w = dis_y(gen)%_map_width;
        if(map->_map_points[l][w]->is_start_point() || map->_map_points[l][w]->is_end_point()\
         || map->_map_points[l][w]->get_obstruction_station())
        {
            continue;
        }
        map->_map_points[l][w]->set_obstruction_station(true);
        count++;
    }
    
}

void MyAStar::set_map_length_width(int length, int width)
{
    _map_length = length;
    _map_width = width;
}

void MyAStar::draw_map()
{
    for(int i=0;i<_map_length;i++)
    {
        for(int j=0;j<_map_width;j++)
        {
            if(map->_map_points[i][j]->get_obstruction_station())
            {
                std::cout<<"O ";
                _out_file<<"O ";
            }
            else if(map->_map_points[i][j]->is_start_point())
            {
                //std::cout<<"S ";
                //_out_file<<"S ";
                std::cout << termcolor::red << "S " << termcolor::reset;
                _out_file << termcolor::red << "S " << termcolor::reset;
            }
            else if(map->_map_points[i][j]->is_end_point())
            {
                //std::cout<<"E ";
                //_out_file<<"E ";
                std::cout << termcolor::red << "E " << termcolor::reset;
                _out_file << termcolor::red << "E " << termcolor::reset;
            }
            else
            {
                auto it = find(_path.begin(),_path.end(),map->_map_points[i][j]);
                if(it != _path.end())
                {
                    std::cout << termcolor::red << "1 " << termcolor::reset;
                    _out_file << termcolor::red << "1 " << termcolor::reset;
                }
                else
                {
                    std::cout<<"* ";
                    _out_file<<"* ";
                }
                
            }
        }
        std::cout<<"         ";
        _out_file<<"         ";
        for(int k=0;k<_map_width;k++)
        {
            std::cout << std::right << std::setw(5) << map->_map_points[i][k]->get_id();
            _out_file<< std::right << std::setw(5) << map->_map_points[i][k]->get_id();
        }
        std::cout<<std::endl;
        _out_file<<std::endl;
    }
    std::cout<<std::endl<<"path.size()"<<_path.size()<<std::endl;
    
    if(_no_path)
    {
        std::cout<<"无通路，已走路径为： ";
        _out_file<<"无通路，已走路径为： ";
    }
    else
    {
        std::cout<<"有通路，路径为： ";
        _out_file<<"有通路，路径为： ";
    }
    for(auto it = _path.rbegin(); it != _path.rend(); ++it)
    {
        std::cout<<(*it)->get_id()<<" ";
        _out_file<<(*it)->get_id()<<" ";
    }
    std::cout<<std::endl;

}

void MyAStar::set_end_point(MyPoint* p)
{
    _end_point = p;
}

MyPoint* MyAStar::get_end_point()
{
  return _end_point;
}

void MyAStar::set_start_point(MyPoint* p)
{
    _start_point = p;
    _start_point->set_father_point(p);
}

MyPoint* MyAStar::get_start_point()
{
  return _start_point;
}

double MyAStar::calculate_f_value(MyPoint* p1,MyPoint* p2)
{
    double fv = 0.0;
    MyPoint * tmp2 = _end_point;
    int end_x = tmp2->get_coordinate_X();
    int end_y = tmp2->get_coordinate_Y();
    int p1_x = p1->get_coordinate_X();
    int p1_y = p1->get_coordinate_Y();
    int p2_x = p2->get_coordinate_X();
    int p2_y = p2->get_coordinate_Y();


    fv = sqrt((p1_x-p2_x)*(p1_x-p2_x)+(p1_y-p2_y)*(p1_y-p2_y))+abs(p2_x-end_x)+abs(p2_y-end_y);
    return fv;
}

MyPoint* MyAStar::id_to_point(int id)
{
    for(int i=0;i<_map_length;i++)
    {
        for(int j=0;j<_map_width;j++)
        {
            if(map->_map_points[i][j]->get_id() == id)
            {
                return map->_map_points[i][j];
            }
        }
    }
  return nullptr;
}

void MyAStar::push_open_list(MyPoint* p)
{
    _open_list.push_back(p);
}

void MyAStar::pop_open_list(MyPoint* p)
{
    auto it = std::find(_open_list.begin(),_open_list.end(),p);
    if(it != _open_list.end())
    {
        _open_list.erase(it);
    }
}

void MyAStar::push_close_list(MyPoint* p)
{
    _close_list.push_back(p);
}

void MyAStar::pop_close_list(MyPoint* p)
{
    auto it = std::find(_close_list.begin(),_close_list.end(),p);
    if(it != _close_list.end())
    {
        _close_list.erase(it);
    }
}

void MyAStar::update_path(MyPoint* p)
{
    MyPoint *tmp = p;
    _path.clear();
    while (1)
    {
        if(tmp == _start_point)
        {
            _path.push_back(tmp);
            break;
        }
        _path.push_back(tmp);
        tmp = tmp->get_father_point();
    }
    tmp = nullptr;
}

void MyAStar::a_star()
{
    //初始化地图
    initial_map();
    MyPoint * tmp_start_point = get_start_point();
    std::cout<<tmp_start_point->get_id()<<" "<<get_end_point()->get_id()<<std::endl;
    //储存临时f值
    double tmp_fv = 99999.0;
    int a =0;
    
    while (1)
    {
        tmp_fv = 99999.0;
        //路径回溯
        update_path(tmp_start_point);

        _out_file<<"当前路径为： ";
        for(auto it = _path.rbegin();it!=_path.rend();it++)
        {
            _out_file<<(*it)->get_id()<<" ";
        }
        _out_file<<std::endl<<std::endl;
        //将当前起点加入到关闭列表
        _close_list.push_back(tmp_start_point);


        if(tmp_start_point == _end_point)
        {
            break;
        }
        //创建临时列表，加入当前点的周围点
        create_tmp_list(tmp_start_point);

        //将临时列表合并到开放列表
        for(MyPoint *point:_tmp_list)
        {
            double f = 0;
            f = calculate_f_value(tmp_start_point,point);
            point->set_f_value(f);
            _open_list.push_back(point);
        }

        //取open_list里面f值最小的
        for(auto it = _open_list.begin();it != _open_list.end();it++)
        {
            double f = (*it)->get_f_value();
            if(tmp_fv > f)
            {
                tmp_fv = f;
                tmp_start_point = *it;
            }
        }
        //检查开放列表和关闭列表，后续为打印当前运行信息可不管
        _out_file<<"第"<<a<<"次的open_list ";

        for(auto it = _open_list.begin();it!= _open_list.end();it++)
        {
            _out_file<<(*it)->get_id()<<" ";
        }
        _out_file<<std::endl;

        auto it = std::find(_open_list.begin(),_open_list.end(),tmp_start_point);
        if(it != _open_list.end())
        {
            _open_list.erase(it);
        }

        //检查开放列表和关闭列表
        _out_file<<"第"<<a<<"次删除后的open_list ";
        for(auto it = _open_list.begin();it!= _open_list.end();it++)
        {
            _out_file<<(*it)->get_id()<<" ";
        }
        _out_file<<std::endl;
        _out_file<<"第"<<a<<"次的close_list ";
        for(auto it = _close_list.begin();it!= _close_list.end();it++)
        {
            _out_file<<(*it)->get_id()<<" ";
        }
       _out_file<<std::endl;
        a++;
        if(_open_list.empty())
        {
            if(tmp_start_point != _end_point)
            {
                update_path(tmp_start_point);
                _no_path = true;
                break;
            }
        }
    }
}

void MyAStar::create_tmp_list(MyPoint* p)
{
    int p_x = p->get_coordinate_X();
    int p_y = p->get_coordinate_Y();

    _tmp_list.clear();

    if((p_y+1) < _map_width)
    {
        _tmp_list.push_back(id_to_point(p_x * _map_width + p_y + 1));
    }
    if(((p_x-1) >=0) && ((p_y+1) < _map_width))
    {
        _tmp_list.push_back(id_to_point((p_x-1) * _map_width + p_y +1));
    }
    if(((p_x-1) >= 0))
    {
        _tmp_list.push_back(id_to_point((p_x-1) * _map_width + p_y));
    }
    if(((p_x-1) >=0) && ((p_y-1)>= 0))
    {
        _tmp_list.push_back(id_to_point((p_x-1) * _map_width + p_y -1));
    }
    if((p_y-1) >= 0)
    {
        _tmp_list.push_back(id_to_point((p_x) * _map_width + p_y -1));
    }
    if(((p_x+1) < _map_length) && ((p_y-1) >= 0))
    {
        _tmp_list.push_back(id_to_point((p_x+1) * _map_width + p_y -1));
    }
    if((p_x+1) < _map_length)
    {
        _tmp_list.push_back(id_to_point((p_x+1) * _map_width + p_y));
    }
    if(((p_x+1) < _map_length) && ((p_y+1) < _map_width))
    {
        _tmp_list.push_back(id_to_point((p_x+1) * _map_width + p_y + 1));
    }

//这里容易出问题
    for(auto it = _tmp_list.begin();it != _tmp_list.end();)
    {
        if(std::find(_open_list.begin(),_open_list.end(),*it) != _open_list.end())
        {
            it = _tmp_list.erase(it);
        }
        else if(std::find(_close_list.begin(),_close_list.end(),*it) != _close_list.end())
        {
            it = _tmp_list.erase(it);
        }
        else if((*it)->get_obstruction_station())
        {
            it = _tmp_list.erase(it);
        }
        else
        {
            it++;
        }
    }

    for(auto it = _tmp_list.begin(); it!= _tmp_list.end(); it++)
    {
        if(!(*it)->get_father_point())
        {
            (*it)->set_father_point(p);
        }
    }
    _out_file<<"_tmp_list ";
    for(auto it = _tmp_list.begin();it != _tmp_list.end(); it++)
    {
        
        _out_file<<(*it)->get_id()<<" ";
    }
    _out_file<<std::endl;
}
