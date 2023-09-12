// golf.h -- for pe9-1.cpp

const int Len = 40;
class Golf
{
private:
    char fullname[Len];
    int handicap;
public:
    Golf(const char * name, int hc);
    Golf();
    void set_handicap(int hc);
    void show() const;
};
