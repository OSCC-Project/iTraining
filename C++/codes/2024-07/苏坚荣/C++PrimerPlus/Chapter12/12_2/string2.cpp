#include <cstring>
#include "string2.h"

using namespace std;

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}

String::String(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 10];
	strcpy_s(str, len + 1, st.str);
}

String::~String()
{
	--num_strings;
	delete[]str;
}

void String::stringLow()
{
	for (int i = 0; i < len; i++) {
		str[i] = tolower(str[i]);
	}
}

void String::stringUp()
{
	for (int i = 0; i < len; i++) {
		str[i] = toupper(str[i]);
	}
}

int String::calculateString(char ch)
{
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ch) {
			cnt++;
		}
	}
	return cnt;
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[]str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[]str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

String operator+(const String& st, const String& st2)
{
	String st3;
	delete[] st3.str;
	st3.len = st.len + st2.len;
	st3.str = new char[st3.len + 1];
	for (int i = 0; i < st.len; i++) {
		st3.str[i] = st.str[i];
	}
	for (int j = 0; j < st2.len; j++) {
		st3.str[st.len + j] = st2.str[j];
	}
	st3.str[st3.len] = '\0';

	return st3;
}

String operator+(const char* st, const String& st2)
{
	String st3;
	delete[] st3.str;
	st3.len = strlen(st) + st2.len;
	st3.str = new char[st3.len + 1];
	for (int i = 0; i < strlen(st); i++) {
		st3.str[i] = st[i];
	}
	for (int j = 0; j < st2.len; j++) {
		st3.str[strlen(st) + j] = st2.str[j];
	}
	st3.str[st3.len] = '\0';
	return st3;
}
