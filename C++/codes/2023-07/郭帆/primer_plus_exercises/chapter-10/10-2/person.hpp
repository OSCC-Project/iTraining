//
//  person.hpp
//  10-2
//
//  Created by 郭帆 on 2023/7/20.
//

#ifndef person_hpp
#define person_hpp

#include <string>

class Person {
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
public:
    Person() {lname = ""; fname[0] = '\0';}
    Person(const std::string & ln, const char * fn = "Heyyou");
    void Show() const;
    void FormalShow() const;
};

#endif /* person_hpp */
