#include<iostream>
#include<vector>
#include"Map.h"

std::vector<std::vector<int>> one = { {-1,-1}, {0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1} };
// std::vector<std::vector<int>> one = { {0,-1},{-1,0},{1,0},{0,1}};

Map::Map() {
    _first.x = -1;
    _first.y = -1;
    _final.x = -1;
    _final.y = -1;
    _length = 0;
    _weight = 0;
    _map = { {} };
    _point_open = {};
}

Map::Map(int m_length, int m_weight) {
    // _first = { -1, -1 };
    // _final = { -1, -1 };
    _first.x = -1;
    _first.y = -1;
    _final.x = -1;
    _final.y = -1;
    _length = m_length;
    _weight = m_weight;
    for (int i = 0; i < _length; ++i) {
        std::vector<Point> one_Col;
        for (int j = 0; j < _weight; ++j) {
            one_Col.emplace_back(Point(i, j, 0));
        }
        _map.emplace_back(one_Col);
    }
    _point_open = {};
}

void Map::insertFirst(int x, int y) {
    if (_first.x != -1) {
        _map[_first.x][_first.y].insertNoAbs();
        if(!_point_open.empty())_point_open.pop();
    }
    _first.x = x;
    _first.y = y;
    _point_open.push(Point(x, y, 2));
    _map[x][y].insertFirst();
}

void Map::insertAbs(int x, int y) {
    // Xy xy = { x, y };
    Xy xy;
    xy.x = x;
    xy.y = y;
    _map[x][y].insertAbs();
}

void Map::insertFinal(int x, int y) {
    if (_final.x != -1) {
        _map[_final.x][_final.y].insertNoAbs();
    }
    _final.x = x;
    _final.y = y;
    _map[x][y].insertFinal();
}

void Map::deleteAbs(int x, int y) {
    _map[x][y].insertNoAbs();
}

bool Map::isOnBoard(Xy xy) {
    if (xy.x >= 0 && xy.x < _length && xy.y >= 0 && xy.y < _weight)return 1;
    return 0;
}

int Map::twoPointDistance(Xy point1, Xy point2) {
    int min_ = std::min(abs(point1.x - point2.x), abs(point1.y - point2.y));
    int max_ = std::max(abs(point1.x - point2.x), abs(point1.y - point2.y));
    return 14 * min_ + 10 * (max_ - min_);
}

int Map::gAdd(Xy point1, Xy point2) {
    if (abs(point2.x - point1.x) == 1 && abs(point2.y - point1.y) == 1)return 14;
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

void Map::getPath() {
    if (_haveway == 0) {
        start_button = 0;
        final_button = 0;
        a_star_button = 0;
        abs_button = 0;
        clear_button = 1;
        reStart();
    }
    else {

        Point temp = _map[_final.x][_final.y];
        std::cout << "[getPath]temp: " << temp << ", final: " << _map[_final.x][_final.y].getXy().x << _map[_final.x][_final.y].getXy().y << '\n';
        while (temp.getXy().x != _first.x || temp.getXy().y != _first.y) {
            _path.insert(_path.begin(), temp.getXy());
            temp = *temp._parent;
        }
    }
}

void Map::reStart() {
    // 清空状态码和优先队列
    for (int i = 0; i < _length; ++i) {
        for (int j = 0; j < _weight; ++j) {
            std::cout << _map[i][j].getValue() << ' ';
            if (_map[i][j].getValue() == PRIOQUE) {
                _map[i][j].insertNoAbs();
            }
            // 父节点也要清除
            _map[i][j]._parent = nullptr;
        }
        std::cout << '\n';
    }
    _haveway = 1;
    while (!_point_open.empty()) {
        Point a = _point_open.top();
        std::cout << a.getXy().x << a.getXy().y<< " f:" << a._f << " g:" << a._g << " h:" << a._h << "oooo\n";
        _point_open.pop();
    }
    _point_open.push(Point(_first.x, _first.y, 2));
    // 清空列表
    _path.clear();
    std::cout << _point_open.empty() << "pppp\n";
}

std::ostream& operator<<(std::ostream& os, Map& m_map) {
    for (int i = 0; i < m_map._length; ++i) {
        for (int j = 0; j < m_map._weight; ++j) {
            os << m_map._map[i][j].getValue();
        }
        os << '\n';
    }
    return os;
}

// 前端部分
void Map::paintEvent(QPaintEvent* event) {
    // 创建绘制对象
    QPainter p;
    p.begin(this);
    int pen_len = 3;

    // 网格的行和列
    int col = _weight;
    int row = _length;

    // 绘制画笔
    QPen pen;

    // 根据不同的状态绘制颜色
    // 绘制网格布局
    pen.setWidth(pen_len);
    p.setPen(pen);
    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(0, 0, 0));
    for (int i = 0; i <= row; ++i) {
        p.drawLine(start_x, start_y + gsize * i, start_x + gsize * col, start_y + gsize * i);
    }
    for (int i = 0; i <= col; ++i) {
        p.drawLine(start_x + gsize * i, start_y, start_x + gsize * i, start_y + gsize * row);
    }



    // 创建画刷
    QBrush brush;

    if (_first.x != -1 && _map[_first.x][_first.y].getValue() == FIRST) {
        brush.setColor(Qt::green);
        brush.setStyle(Qt::SolidPattern);
        p.setBrush(brush);
        // 绘制起点
        p.drawRect(start_y + _first.y * gsize, start_x + _first.x * gsize, gsize, gsize);
    }

    if (_final.x != -1 && _map[_final.x][_final.y].getValue() == FINAL) {
        // 绘制终点
        brush.setColor(Qt::red);
        brush.setStyle(Qt::SolidPattern);
        p.setBrush(brush);
        p.drawRect(start_y + _final.y * gsize, start_x + _final.x * gsize, gsize, gsize);
    }

    // 绘制障碍
    brush.setColor(Qt::lightGray);
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);
    // 绘制障碍
    for (int i = 0; i < _length; ++i) {
        // 通过当前状态码绘制网格图
        for (int j = 0; j < _weight; ++j) {
            if (_map[i][j].getValue() == ADS) {
                brush.setColor(Qt::black);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
                p.drawRect(start_y + _map[i][j].getXy().y * gsize, start_x + _map[i][j].getXy().x * gsize, gsize, gsize);
                brush.setColor(Qt::lightGray);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
            if (_map[i][j].getValue() == PRIOQUE) {
                p.drawRect(start_y + _map[i][j].getXy().y * gsize, start_x + _map[i][j].getXy().x * gsize, gsize, gsize);
            }
        }
    }

    // 绘制路径
    if (a_star_button == 1) {
        brush.setColor(Qt::yellow);
        brush.setStyle(Qt::SolidPattern);
        p.setBrush(brush);
        for (int i = 0; i < _path.size() - 1; ++i) {
            p.drawRect(start_y + _path[i].y * gsize, start_x + _path[i].x * gsize, gsize, gsize);
        }
    }

    // 绘制设置开始点按钮
    if (start_button == 0) {

        brush.setColor(Qt::cyan);
        brush.setStyle(Qt::SolidPattern);

    }
    else {
        brush.setColor(Qt::darkGray);
        brush.setStyle(Qt::Dense6Pattern);
    }
    p.setBrush(brush);
    p.drawRect(start_x, start_y + gsize * (row + 1), gsize * 2, gsize);
    p.drawText(start_x + 10, start_y + gsize * (row + 1.5), "ADD_FIRST");

    // 绘制设置结束点按钮
    if (final_button == 0) {

        brush.setColor(Qt::cyan);
        brush.setStyle(Qt::SolidPattern);

    }
    else {
        brush.setColor(Qt::darkGray);
        brush.setStyle(Qt::Dense6Pattern);
    }
    p.setBrush(brush);
    p.drawRect(start_x + gsize * 3, start_y + gsize * (row + 1), gsize * 2, gsize);
    p.drawText(start_x + gsize * 3 + 10, start_y + gsize * (row + 1.5), "ADD_FINAL");

    // 绘制A-star按钮
    if (a_star_button == 0) {

        brush.setColor(Qt::cyan);
        brush.setStyle(Qt::SolidPattern);

    }
    else {
        brush.setColor(Qt::darkGray);
        brush.setStyle(Qt::Dense6Pattern);
    }
    p.setBrush(brush);
    p.drawRect(start_x + gsize * 6, start_y + gsize * (row + 1), gsize * 2, gsize);
    p.drawText(start_x + gsize * 6 + 10, start_y + gsize * (row + 1.5), "A_STAR");


    // 绘制设置障碍按钮
    if (abs_button == 0) {

        brush.setColor(Qt::cyan);
        brush.setStyle(Qt::SolidPattern);

    }
    else {
        brush.setColor(Qt::darkGray);
        brush.setStyle(Qt::Dense6Pattern);
    }
    p.setBrush(brush);
    p.drawRect(start_x, start_y + gsize * (row + 3), gsize * 2, gsize);
    p.drawText(start_x + 10, start_y + gsize * (row + 3.5), "ADD_ABS");

    // 绘制清除障碍按钮
    if (clear_button == 0) {

        brush.setColor(Qt::cyan);
        brush.setStyle(Qt::SolidPattern);

    }
    else {
        brush.setColor(Qt::darkGray);
        brush.setStyle(Qt::Dense6Pattern);
    }
    p.setBrush(brush);
    p.drawRect(start_x + gsize * 3, start_y + gsize * (row + 3), gsize * 2, gsize);
    p.drawText(start_x + gsize * 3 + 10, start_y + gsize * (row + 3.5), "CLEAR_ABS");

    // 绘制重新开始
    if (restart_button == 0) {

        brush.setColor(Qt::cyan);
        brush.setStyle(Qt::SolidPattern);

    }
    else {
        brush.setColor(Qt::darkGray);
        brush.setStyle(Qt::Dense6Pattern);
    }
    p.setBrush(brush);
    p.drawRect(start_x + gsize * 6, start_y + gsize * (row + 3), gsize * 2, gsize);
    p.drawText(start_x + gsize * 6 + 10, start_y + gsize * (row + 3.5), "RESTART");

    p.end();
}


void Map::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        QPoint m_point = event->pos();
        // 将当前坐标映射程x，y
        
        last_x = (m_point.x() - start_x) / gsize;
        last_y = (m_point.y() - start_y) / gsize;

        // 设置起点
        if ( last_y == _length + 1 && (last_x == 0 || last_x == 1)) {
            start_button = 1;
        }
        // 设置终点
        else if (last_y == _length + 1 && (last_x == 3 || last_x == 4)) {
            final_button = 1;
        }
        else if (last_y == _length + 1 && (last_x == 6 || last_x == 7) && a_star_button == 0) {
            a_star_button = 1;
            aStar();
            getPath();
        }
        else if (last_y == _length + 3 && (last_x == 0 || last_x == 1)) {
            abs_button = 1;
            clear_button = 0;
        }
        else if (last_y == _length + 3 && (last_x == 3 || last_x == 4)) {
            clear_button = 1;
            abs_button = 0;
        }
        // restart
        else if (last_y == _length + 3 && (last_x == 6 || last_x == 7)) {
            start_button = 0;
            final_button = 0;
            a_star_button = 0;
            abs_button = 0;
            clear_button = 1;
            reStart();
        }
        else if (last_x >= 0 && last_x < _weight && last_y >= 0 && last_y < _length) {
            if (_map[last_y][last_x].getValue() == NOABS) {
                if (start_button == 1) {
                    insertFirst(last_y, last_x);
                    start_button = 0;
                }
                else if (final_button == 1) {
                    insertFinal(last_y, last_x);
                    final_button = 0;
                }
                else if (abs_button == 1) {
                    insertAbs(last_y, last_x);
                }
            }
            else if (_map[last_y][last_x].getValue() == ADS) {
                if (clear_button == 1) {
                    deleteAbs(last_y, last_x);
                }
            }
        }
    }
    update();
}
