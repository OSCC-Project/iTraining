#include "cow.h"
#include <string.h>
#include <iostream>

Cow::Cow()
{
    name[0]='\0';
    hobby=new char[1];
    hobby[0]='\0';
    weight=0.0;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
    
    strncpy(name,nm,19);
    name[19]='\0';
    hobby=new char[strlen(ho)+1];
    strcpy(hobby,ho);
    weight=wt;
}

Cow &Cow::operator=(const Cow &c)
{
    if(this==&c)
        return *this;
    strncpy(name,c.name,19);
    delete[] hobby;
    hobby=new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight=c.weight;
    return *this;
}

Cow::Cow(const Cow &c)
{
    strncpy(name, c.name, 19);
    name[19] = '\0';
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete []hobby;
}



void Cow::ShowCow() const
{
    std::cout<<"cow message:"<<std::endl;
    std::cout<<"name:"<<name<<std::endl;
    std::cout<<"hobby:"<<hobby<<std::endl;
    std::cout<<"weight:"<<weight<<std::endl;
}
