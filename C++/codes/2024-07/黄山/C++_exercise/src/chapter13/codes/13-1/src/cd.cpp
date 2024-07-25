#include"cd.h"

Cd::Cd(char* s1, char* s2, int n, double x):selections(n),playtime(x){
    strcpy(this->performers, s1);
    strcpy(this->label, s2);
}
Cd::Cd(const Cd& d):selections(d.selections),playtime(d.playtime){
    strcpy(this->performers, d.performers);
    strcpy(this->label, d.label);
}
Cd::Cd(){
    this->performers[0] = '\0';
    this->label[0] = '\0';
    this->selections = 0;
    this->playtime = 0;
}

void Cd::Report() const{
    std::cout<<"performers: "<<this->performers<<std::endl;
    std::cout<<"label: "<<this->label<<std::endl;
    std::cout<<"selections: "<<this->selections<<std::endl;
    std::cout<<"playtime: "<<this->playtime<<std::endl<<std::endl;
}
Cd& Cd::operator=(const Cd& d){
    strcpy(this->performers, d.performers);
    strcpy(this->label, d.label);
    this->selections = d.selections;
    this->playtime = d.playtime;
    return *this;
}
