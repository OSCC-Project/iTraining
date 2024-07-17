#include <iostream>
#include <new>  
#include <cstring>  

using namespace std;

struct chaff {
    char dross[20];
    int slag;
};

int main() {
    
    char buffer[sizeof(chaff) * 2];
    chaff* chaffs = new (buffer) chaff[2];

    
    strcpy(chaffs[0].dross, "chaff1");
    chaffs[0].slag = 10;
    strcpy(chaffs[1].dross, "chaff2");
    chaffs[1].slag = 15;

    
    for (int i = 0; i < 2; i++) {
        cout << "chaffs[" << i << "]:";
        cout << "  dross: " << chaffs[i].dross;
        cout << "  slag: " << chaffs[i].slag << endl;
    }

    return 0;
}
