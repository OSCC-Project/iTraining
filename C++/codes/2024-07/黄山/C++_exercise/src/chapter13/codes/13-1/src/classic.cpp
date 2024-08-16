#include"classic.h"

Classic::Classic(char* s1, char* s2, char* s3, int n, double x):Cd::Cd(s2, s3, n, x){
    strcpy(this->major_works, s1);
}
// Classic::Classic(const Classic& d):selections(d.selections),playtime(d.playtime){
//     strcpy(this->major_works, d.major_works);
//     strcpy(this->performers, d.performers);
//     strcpy(this->label, d.label);
// }
Classic::Classic(const Classic& d):Cd::Cd(d){
    strcpy(this->major_works, d.major_works);
}
Classic::Classic(){
    this->major_works[0] = '\0';
    this->performers[0] = '\0';
    this->label[0] = '\0';
    this->selections = 0;
    this->playtime = 0;
}
void Classic::Report() const{
    std::cout<<"major works: "<<this->major_works<<std::endl;
    std::cout<<"performers: "<<this->performers<<std::endl;
    std::cout<<"label: "<<this->label<<std::endl;
    std::cout<<"selections: "<<this->selections<<std::endl;
    std::cout<<"playtime: "<<this->playtime<<std::endl<<std::endl;
}
Classic& Classic::operator=(const Classic& d){
    strcpy(this->major_works, d.major_works);
    strcpy(this->performers, d.performers);
    strcpy(this->label, d.label);
    this->selections = d.selections;
    this->playtime = d.playtime;
    return *this;
}
