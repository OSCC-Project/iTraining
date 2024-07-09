#include <iostream>
#include <cstring>

struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    char buffer[1024];
    chaff *num = new (buffer) chaff[2];
    std::strcpy(num[0].dross, "1111111111");
    num[0].slag = 1;
    std::strcpy(num[1].dross, "2222222222");
    num[1].slag = 2;

    for(int a = 0; a < 2; a++)
        std::cout << num[a].dross << "    " 
            << num[a].slag << std::endl;
    return 0;
}