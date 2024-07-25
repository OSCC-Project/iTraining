#pragma once

#include"port.h"

class VintagePort : public Port{
public:
    VintagePort();
    VintagePort(const char* br, int b, const char * nn, int y);
    VintagePort(const VintagePort& vp);
    ~VintagePort(){delete[] nickname;}
    VintagePort& operator=(const VintagePort& vp);
    void show() const;
    friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
private:
    char* nickname;
    int year;
};