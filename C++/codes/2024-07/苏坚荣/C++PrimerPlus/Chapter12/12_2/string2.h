#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
using namespace std;

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;

public:
	String(const char* s);
	String();
	String(const String&);
	~String();
	int length() const { return len; };
	void stringLow();
	void stringUp();
	int calculateString(char ch);

	//overloaded operator methods
	String& operator=(const String&);
	String& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i) const;

	//overloaded operator friends
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend ostream& operator << (ostream& os, const String& st);
	friend istream& operator >> (istream& is, String& st);
	friend String operator+(const String& st, const String& st2);
	friend String operator+(const char* st, const String& st2);


	//static function
	static int HowMany();
};
#endif //STRING1_H_