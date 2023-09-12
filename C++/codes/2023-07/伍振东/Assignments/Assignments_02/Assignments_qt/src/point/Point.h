#ifndef POINT_H_
#define POINT_H_
#define ADS 1
#define FIRST 2
#define FINAL 3
#define NOABS 0
#define PRIOQUE 5

struct Xy
{
    int x = 0;
    int y = 0;
};

std::ostream& operator<<(std::ostream& os, Xy& m_point);

// Point存储的是坐标，标识是否为障碍物，以及父节点的指向
class Point {
private:
    Xy _xy;
    int _value = 0;

public:
    // Point还应该保存代价的总值
    int _f = 0;
    int _g = 0;
    int _h = 0;
    Point* _parent;
    Point();
    Point(int m_x, int m_y, int m_value);
    ~Point();
    // 障碍是1
    void insertAbs()noexcept;
    // 起点是2
    void insertFirst()noexcept;
    // 终点是3
    void insertFinal()noexcept;
    // 非障碍是0
    void insertNoAbs()noexcept;
    // 在优先队列中5
    void insertPriority()noexcept;

    int getValue();

    Xy getXy();
    void updateF();

    void setParent(Point& p);

    friend std::ostream& operator<<(std::ostream& os, Point& m_point);

    bool operator<(const Point& point1)const;
};

#endif // !POINT_H_