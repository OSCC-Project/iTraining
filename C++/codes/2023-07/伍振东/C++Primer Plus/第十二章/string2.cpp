#include<iostream>
#include"string2.h"

int String::num_strings = 0;

int String::HowMany() {
	return num_strings;
}
String::String(const char* s) {
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len+1, s);
	num_strings++;
}
String::String() {
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
String::String(const String& st) {
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len+1, st.str);
	num_strings++;
}
String::~String() {
	num_strings--;
	delete[]str;
}
void String::stringlow() {
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = tolower(str[i]);
		}
	}
}
void String::stringup() {
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = toupper(str[i]);
		}
	}
}
int String::count(char x) {
	int res = 0;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == x)res++;
	}
	return res;
}
String& String::operator=(const String& st) {
	if (this == &st) {
		return *this;
	}
	delete[]str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}
String& String::operator=(const char* c) {
	delete[]str;
	len = strlen(c);
	str = new char[len + 1];
	strcpy_s(str, len+1, c);
	return *this;
}
char& String::operator[] (int i) {
	return str[i];
}
const char& String::operator[] (int i) const {
	return str[i];
}
bool operator<(const String& st1, const String& st2) {
	return (strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String& st1, const String& st2) {
	return (strcmp(st1.str, st2.str) > 0);
 }
bool operator==(const String& st1, const String& st2) {
	return (strcmp(st1.str, st2.str) == 0);
}
ostream& operator<<(ostream& os, const String& st) {
	os << st.str;
	return os;
}
istream& operator>>(istream& is, String& st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
String String::operator+(const String& st) const {
	char* temp = new char[len + strlen(st.str) + 1];
	strcpy_s(temp, len + 1, str);
	strcat_s(temp + len, st.len + 1, st.str);
	return temp;
}
String String::operator+(const char* s) const {
	char* temp = new char[len + strlen(s) + 1];
	strcpy_s(temp, len + 1, str);
	strcat_s(temp + len, strlen(s) + 1, s);
	return temp;
}
String operator+(const char* s, const String& st) {
	char* temp = new char[st.len + strlen(s) + 1];
	strcpy_s(temp, strlen(s) + 1, s);
	strcat_s(temp + strlen(s), st.len + 1, st.str);
	return temp;
}