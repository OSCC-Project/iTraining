#include "cd.h"
#include <cstring>
#include <iostream>

Cd::Cd(char *s1, char *s2, int n, double x)
{
    strncpy(performers,s1,49);
    performers[49]='\0';
    strncpy(label,s2,19);
    label[19]='\0';
    selections=n;
    playtime=x;
}

Cd::Cd(const Cd &d)
{
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
}

Cd::Cd()
{
     performers[0]='\0';
     label[0]='\0';
     selections=0;
     playtime=0;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
    std::cout<<"performers:"<<performers<<std::endl;
    std::cout<<"label:"<<label<<std::endl;
    std::cout<<"selections:"<<selections<<std::endl;
    std::cout<<"playtime:"<<playtime<<std::endl;
}

Cd &Cd::operator=(const Cd &d)
{
    if(this==&d)
        return *this;
    strncpy(performers,d.performers,49);
    strncpy(label,d.label,19);
    performers[49]='\0';
    label[19]='\0';
    selections=d.selections;
    playtime=d.playtime;
    return *this;
}

Classic::Classic():Cd()
{
    mainwork=new char[1];
    mainwork[0]='\0';
}

Classic::Classic(const Classic &d):Cd(d)
{
    int len=strlen(d.mainwork);
    mainwork=new char[len+1];
    strcpy(mainwork,d.mainwork);
}

Classic::Classic(char *m, char *s1, char *s2, int n, double x):Cd(s1,s2,n,x)
{
    mainwork=new char[strlen(m)+1];
    strcpy(mainwork,m);
}

Classic::~Classic()
{
    delete []mainwork;
}

void Classic::Report() const
{
    std::cout<<"mainwork:"<<mainwork;
    Cd::Report();
}

Classic &Classic::operator=(const Classic &d)
{
    if(this==&d)
        return *this;
    Cd::operator=(d);
    delete []mainwork;
    mainwork=new char[strlen(d.mainwork)+1];
    strcpy(mainwork,d.mainwork);
    return *this;
}
