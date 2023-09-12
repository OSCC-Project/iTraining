#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>

class String {
public:
  String();
  String(const char *s);
  String(const String &);
  ~String();
  int length() const { return _len; }
  void stringlow();
  void stringup();
  int has(char c);
  String &operator=(const String &);
  String &operator=(const char *);
  char &operator[](int i);
  const char &operator[](int i) const;
  friend bool operator<(const String &s1, const String &s2);
  friend bool operator>(const String &s1, const String &s2);
  friend bool operator==(const String &s1, const String &s2);
  friend std::ostream &operator<<(std::ostream &os, const String &s);
  friend std::istream &operator>>(std::istream &is, String &s);
  static int HowMany();
  String operator+(const String &) const;
  String operator+(const char *) const;
  friend String operator+(const char *, const String &);

private:
  char *_str;
  int _len;
  static int _num_strings;
  static const int CINLIM = 80;
};
#endif