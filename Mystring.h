#ifndef MYSTRING_H
#define MYSTRING_H

#include<string.h>
#include<iostream>

using namespace std;

class Mystring{
    friend ostream& operator<<(ostream& os,const Mystring& str);
    friend Mystring operator+(const Mystring& str1,const Mystring& str2);
    friend Mystring operator-(const Mystring& str1,const Mystring& str2);
public:
    Mystring();//默认构造
    Mystring(const char* cstr); //一般构造
    Mystring(const int str_int);//整数构造
    Mystring(const double str_double);//浮点数构造
    Mystring(const Mystring& str);//拷贝构造
    ~Mystring();

    //运算符重载
    Mystring& operator+=(const Mystring& str);
    Mystring& operator-=(const Mystring& str);
    // Mystring& operator+=(const int str_int);
    // Mystring& operator-=(const int str_int);
    // Mystring& operator+=(const double str_double);
    // Mystring& operator-=(const double str_double);

    Mystring substr(int pos,const int n);
    int find(const Mystring& str,int index);
    int toInt();
    double toDouble();
    int length() const{return strlen(m_data);}
private:
    char *m_data;
};


#endif