#include <iostream>
#include <new>

using namespace std;

struct chaff {
    char dross[20];
    int slag;
};

char buffer[1024];

int main() {
    chaff *pcha = new (buffer) chaff[2];
    char *pc = new char[1024];
    chaff *pcha2 = new (pc) chaff[2];
    char dross[20] = { 0 };
    int slag = 0;
 
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter dross of #" << i << " chaff: " << endl;
        cin.getline(dross, 20);
        cout << "Enter slag of #" << i << " chaff: " << endl;
        cin >> slag;
        cin.get();
 
        strcpy(pcha[i].dross, dross);
        strcpy(pcha2[i].dross, dross);
        pcha[i].slag = pcha2[i].slag = slag;
    }
 
    for (int i = 0; i < 2; i++)
    {
        cout << "staff #" << (i + 1) << ":" << endl;
        cout << "pcha.dross: " << pcha[i].dross << ". pcha.slag: " << pcha[i].slag << endl;
        cout << "pcha2.dross: " << pcha2[i].dross << ". pcha2.slag: " << pcha2[i].slag << endl;
    }
 
    cout << "address of buffer: " << (void *)buffer << endl;
    cout << "address of pcha: " << pcha << ". address of pcha[0]: " << &pcha[0] << ". address of pcha[1]: " << &pcha[1] << endl;
    cout << "address of pc: " << (void *)pc << endl;
    cout << "address of pcha2:" << pcha2 << ". address of pcha2[0]: " << &pcha2[0] << ". address of pcha2[1]: " << &pcha2[1] << endl;;
 
    delete[] pc;
    
    return 0;
}
