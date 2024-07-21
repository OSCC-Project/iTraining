#pragma once

#include"cd.h"

class Classic : public Cd{
public:
    Classic(char* s1, char* s2, char* s3, int n, double x);
    Classic(const Classic& d);
    Classic();
    virtual void Report() const;
    virtual Classic& operator=(const Classic& d);
private:
    char major_works[50];
};