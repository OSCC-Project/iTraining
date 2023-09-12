#include<iostream>
#include<vector>
#include"Map.h"

// 列表初始化
std::vector<std::vector<int>> one = {{-1,-1}, {0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

Map::Map(){
    _first = {-1, -1};
    _final = {-1, -1};
    _length = 0;
    _weight = 0;
    _map = {{}};
    _point_open = {};
}

Map::Map(int m_length, int m_weight){
    _first = {-1, -1};
    _final = {-1, -1};
    _length = m_length;
    _weight = m_weight;
    for(int i = 0; i < _length; ++i){
        std::vector<Point> one_Col;
        for(int j = 0; j < _weight; ++j){
            one_Col.emplace_back(Point(i, j, 0));
        }
        _map.emplace_back(one_Col);
    }
    _point_open = {};
}

void Map::insertFirst(int x, int y){
    if(_first.x != -1){
        _map[x][y].insertNoAbs();
    }
    _first.x = x;
    _first.y = y;
    _point_open.push(Point(x, y, 1));
    _map[x][y].insertFirst();
}

void Map::insertAbs(int x, int y)noexcept{
    _map[x][y].insertAbs();
}

void Map::insertFinal(int x, int y){
    if(_final.x != -1){
        _map[x][y].insertNoAbs();
    }
    _final.x = x;
    _final.y = y;
    _map[x][y].insertFinal();
}

void Map::deleteAbs(int x, int y)noexcept{
    _map[x][y].insertNoAbs();
}

bool Map::isOnBoard(Xy xy){
    if(xy.x >= 0 && xy.x < _length && xy.y >= 0 && xy.y < _weight)return 1;
    return 0;
}

int Map::twoPointDistance(Xy point1, Xy point2){
    int min_ = std::min(abs(point1.x - point2.x), abs(point1.y - point2.y));
    int max_ = std::max(abs(point1.x - point2.x), abs(point1.y - point2.y));
    return 14 * min_ + 10 * (max_ - min_);
}

int Map::gAdd(Xy point1, Xy point2){
    if(abs(point2.x - point1.x) == 1 && abs(point2.y - point1.y) == 1)return 14;
    return 10;
}

// A-star算法
// 从出发点开始遍历，并不断将元素添加至_point_open中
void Map::aStar() {
    while (!_point_open.empty()) {
        Point it = _point_open.top();
        // std::cout << _point_open.size()<<"*************\n";
        _point_open.pop();

        // auto遍历容器
        for (auto aitem : one) {
            // 能够进入优先队列的结点
            // 1、value状态为0，2、没有在当前的优先队列当中，3、没有出界
            Xy temp;
            temp.x = it.getXy().x + aitem[0];
            temp.y = it.getXy().y + aitem[1];

            // 如果已经到达终点
            if (temp.x == _final.x && temp.y == _final.y) {
                _map[temp.x][temp.y].setParent(_map[it.getXy().x][it.getXy().y]);
                return;
            }

            if (isOnBoard(temp) && _map[temp.x][temp.y].getValue() == NOABS) {
                // 修改路径长度
                _map[temp.x][temp.y]._g = it._g + gAdd(it.getXy(), temp);
                _map[temp.x][temp.y]._h = twoPointDistance(temp, _final);
                _map[temp.x][temp.y].updateF();

                _map[temp.x][temp.y].insertPriority();
                // std::cout << _map[temp.x][temp.y].getXy().x << " y:" << _map[temp.x][temp.y].getXy().y << "IIIIIIII" << _map[temp.x][temp.y]._f << ' ' << _map[temp.x][temp.y]._g << ' ' << _map[temp.x][temp.y]._h << temp << std::endl;
                // 插入优先队列
                _point_open.push(_map[temp.x][temp.y]);

                // 更新父节点
                _map[temp.x][temp.y].setParent(_map[it.getXy().x][it.getXy().y]);
            }

            // 如果优先队列里存在这一个结点的话
            if (isOnBoard(temp) && _map[temp.x][temp.y].getValue() == PRIOQUE) {
                // 比较两个结点的f值，如果f值比其小，则新生成一个结点直接插入，比其大则不插入
                Point tp(temp.x, temp.y, 5);
                tp._g = it._g + gAdd(it.getXy(), temp);
                tp._h = twoPointDistance(temp, _final);
                tp.updateF();
                if (tp._f < _map[temp.x][temp.y]._f) {
                    _point_open.push(tp);
                    _map[temp.x][temp.y].setParent(_map[it.getXy().x][it.getXy().y]);
                }
            }
        }
        // 弹出当前结点
    }
    _haveway = 0;

}

void Map::getPath(){
    Point temp = _map[_final.x][_final.y];
    std::vector<Xy> path;
    while(temp.getXy().x != _first.x || temp.getXy().y != _first.y){
        path.insert(path.begin(), temp.getXy());
        temp = *temp._parent;
    }
    for(int i = 0; i < path.size(); ++i){
        std::cout<<"第"<<i+1<<"次经过的坐标为："<<path[i];
    }
}

std::ostream& operator<<(std::ostream& os, Map& m_map){
    for(int i = 0; i < m_map._length; ++i){
        for(int j = 0; j < m_map._weight; ++j){
            os<<m_map._map[i][j].getValue();
        }
        os<<'\n';
    }
    return os;
}