#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<list>

int main(int argc, char** argv){
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<int> vi0, vi;
    std::list<int> li;
    clock_t start, end;
    for(int length=100000;length<=10000000;length*=10){
        std::cout << "length: " << length << std::endl;
        vi0.resize(length); //预先分配内存
        for(int i=0;i<length;++i){
            vi0[i] = std::rand() % length;
        }

        vi = vi0;
        li.assign(vi0.begin(), vi0.end());

        start = clock();
        std::sort(vi.begin(), vi.end());
        end = clock();
        std::cout << "vector sort time:" << (double)(end-start)/CLOCKS_PER_SEC << std::endl;

        start = clock();
        li.sort();
        end = clock();
        std::cout << "list sort time:" << (double)(end-start)/CLOCKS_PER_SEC << std::endl;

        li.assign(vi0.begin(), vi0.end());

        start = clock();
        vi.assign(li.begin(), li.end());
        std::sort(vi.begin(), vi.end());
        li.assign(vi.begin(), vi.end());
        end = clock();
        std::cout << "list sort time by copy:" << (double)(end-start)/CLOCKS_PER_SEC << std::endl;
    }

    return 0;
}