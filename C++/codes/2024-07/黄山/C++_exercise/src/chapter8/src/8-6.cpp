#include<iostream>
#include<string.h>

template<typename T>
T maxn(T *nums, int counts){
    int max_i = 0;
    for (int i = 1; i < counts;++i){
        if(nums[i] > nums[max_i]){
            max_i = i;
        }
    }
    return nums[max_i];
}

template<>
char* maxn(char** strings, int counts){
    int max_i = 0;
    for (int i = 1; i < counts;++i){
        if(strlen(strings[i]) > strlen(strings[i])){
            max_i = i;
        }
    }
    return strings[max_i];
}

int main(int argc, char** argv){
    int int_arrays[6] = {0, 2, 3, 1, 5, 4};
    double double_arrays[4] = {0.5, -1.4, 4.5, 3.9};
    char *string_arrays[5] = {"hello", "world", "str", "bool", "int"};

    int max_int = maxn(int_arrays, 6);
    double max_double = maxn(double_arrays, 4);
    char *max_string = maxn(string_arrays, 5);

    std::cout << "max int: " << max_int << std::endl;
    std::cout << "max_double: " << max_double << std::endl;
    std::cout << "max_string: " << max_string << std::endl;
    return 0;
}