#include<iostream>
#include<new>
#include<cstring>

const int SIZE = 512;


struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    char *buffer = new char[SIZE];
    struct chaff *MyChaff1 = new (buffer) chaff;
    struct chaff *MyChaff2 = new (buffer + sizeof(struct chaff)) chaff;

    strcpy(MyChaff1->dross,"fjdajlkljdkaljkk");
    strcpy(MyChaff2->dross,"]fakhjkffjl");

    std::cout<<MyChaff1->dross<<std::endl;
    std::cout<<MyChaff2->dross<<std::endl;

    return 0;
}