#include"VintagePort.h"
#include"Port.h"

using namespace std;


int main()
{
    Port po1("dfadfa","errqtgqq",2);
    Port po2("oafaof","haidf",4);
    po1.Show();
    po2.Show();

    VintagePort vp1("dafad",3,"irqerq",4342);
    VintagePort vp2(vp1);
    vp1.Show();
    vp2.Show();

    return 0;
}