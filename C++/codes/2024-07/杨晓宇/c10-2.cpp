#include <iostream>

class plorg
{
public:
    plorg(){}
    plorg(char *name_in, int CI_in)
    {
        int a = 0;
        while(name_in[a] != '\0')
        {    
            name[a] = name_in[a];
            ++a;
        }
        name[a] = name_in[a];
        CI = CI_in;
    }
    ~plorg(){}

    void setCI(int CI_in){CI=CI_in;}
    void show()
    {
        std::cout << name << "    " << CI << std::endl;
    }
private:
    char name[20] = "Plorga";
    int  CI       = 0;
};

int main()
{
    plorg plorg1("TEST", 1), plorg2;
    plorg1.show();
    plorg2.setCI(2);
    plorg2.show();
    return 0;
}