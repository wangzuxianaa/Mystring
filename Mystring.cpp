#include"Mystring.h"
#include<stdlib.h>
#include<cassert>  

inline Mystring::Mystring():m_data(nullptr){}

inline Mystring::Mystring(const char* cstr){
    if(cstr){
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data,cstr);
    }
    else{
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline Mystring::Mystring(const Mystring& str){
    if(str.m_data == nullptr){
        m_data = new char[1];
        *m_data = '\0';
    }
    else{
        m_data = new char[strlen(str.m_data)+1];
        strcpy(m_data,str.m_data);
    }
}

inline Mystring::Mystring(const int str_int){
    int count = 0;
    int temp = str_int;
    while(temp != 0){
        temp /= 10;
        count++;
    }
    m_data = new char[count+1];
    itoa(str_int,m_data,10);
}

inline Mystring::Mystring(const double str_double){
    int count = 0;
    int temp = str_double;
    if(str_double == temp){
        
    }
    while(temp != 0){
        temp /= 10;
        count++;
    }
    m_data = new char[count+3];
    gcvt(str_double,count+1,m_data);
}

inline Mystring::~Mystring(){
    delete[] m_data;
}

ostream& operator<<(ostream& os,const Mystring& str){
    if(str.m_data != nullptr){
        os << str.m_data;
    }
    return os;
}

Mystring operator+(const Mystring& str1,const Mystring& str2){
    Mystring ret;
    ret.m_data = new char[str1.length()+str2.length()+1];
    strcpy(ret.m_data,str1.m_data);
    strcat(ret.m_data,str2.m_data);
    return ret;
}

Mystring& Mystring::operator+=(const Mystring& str){
    if(str.m_data == nullptr){
        return *this;
    }
    else{
        char* temp = m_data;
        m_data = new char[str.length()+strlen(m_data)+1];
        strcpy(m_data,temp);
        strcat(m_data,str.m_data);
        delete[] temp;
        return *this;
    }
}

Mystring Mystring::substr(int pos,const int n){
    if((pos+n)>=strlen(m_data))
    {
        cout << "error:超出最大限制" << endl;
    }
        Mystring ret;
        ret.m_data = new char[n+1]; 
        for(int i=0;i<n;i++)
        {
            ret.m_data[i] = m_data[pos+i];
        }
        ret.m_data[n] = '\0';
        return ret;
}

int Mystring::toInt(){
    int i;
    int res = 0;
    for(int i = 0;i < strlen(m_data);i++){
        if((m_data[i]-'0' >= 0) && (m_data[i]-'0') <=9)
            res = (m_data[i] - '0') + res * 10;
        else
            return -1;
    }
    return res;
}

double Mystring::toDouble(){
    double res = -1;
    int index = strlen(m_data); 
    int i;
    for (i = 0; i < strlen(m_data); i++)
    {
        if (m_data[i] - '.' == 0)
            index = i;
    }
    for (i = 0; i < index; i++)
        res = res*10 + (m_data[i] - '0');
    for (i = index; i < strlen(m_data); i++)
        res = res +((m_data[i]-'0') / 10 / (i - index + 1));
    return res;
}


int main()
{
    Mystring temp3("123");
    cout << temp3 << endl;

    cout << temp3.substr(0,2) << endl;

    int temp5 = temp3.toInt();
    cout << temp5 << endl;

    Mystring temp4(temp3);
    cout << temp4 << endl;

    Mystring temp(13);
    cout << temp << endl;

    Mystring temp1(12.34);
    cout << temp1 << endl;

    Mystring temp2 = temp + temp1;
    cout << temp2 << endl;

    temp += temp1;
    cout << temp << endl;

}