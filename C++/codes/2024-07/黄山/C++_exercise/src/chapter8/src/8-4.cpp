#include<iostream>
#include<cstring>

struct stringy
{
    char *str; //points to a string
    int ct; //lenght of string(not counting '\0')
};

void set(stringy& to_string, char* from_string){
    int length_str = 0;
    while (from_string[length_str] != '\0'){
        length_str++;
    }
    char *copy_string = new char[length_str + 1];
    for (int i = 0; i < length_str+1;++i){
        copy_string[i] = from_string[i];
    }
    to_string.str = copy_string;
    to_string.ct = length_str;
}

void show(stringy &string, int count=1){
    for (int i = 0; i < count;++i){
        std::cout << string.str << std::endl;
    }
}

void show(char *string, int count=1){
    for (int i = 0; i < count;++i){
        std::cout << string << std::endl;
    }
}

int main(){
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;
}