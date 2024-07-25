#include <iostream>
#include "cow.h"
int main(int argc, char *argv[])
{
    Cow cow1;
    Cow cow2("777","ball",80);
    cow1.ShowCow();
    cow2.ShowCow();
    cow1=cow2;
    cow1.ShowCow();
    Cow cow3=cow2;
    cow3.ShowCow();
}
