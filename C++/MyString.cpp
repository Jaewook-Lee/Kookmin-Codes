#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    private:
        char *pBuf;
    public:
        MyString(const char *s=NULL);
        MyString(MyString &s);
        ~MyString();
        
        int getSize();
        void add(MyString &s);
        void print();
};
MyString::MyString(const char *s)
{
    if (s == NULL)
    {
        pBuf = new char[1];
        pBuf[0] = '\0';
    }
    else
    {
        pBuf = new char[::strlen(s) + 1];
        strcpy(pBuf, s);
    }
}
MyString::MyString(MyString &s)
{
    pBuf = new char[s.getSize() + 1];
    strcpy(pBuf, s.pBuf);
}
MyString::~MyString()
{
    if (pBuf)
        delete [] pBuf;
}
int MyString::getSize()
{
    return strlen(pBuf);
}
void MyString::add(MyString &s)
{
    char *tmp = new char[strlen(pBuf) + strlen(s.pBuf) + 1];
    strcpy(tmp, pBuf);
    strcat(tmp, s.pBuf);
    delete [] pBuf;
    pBuf = tmp;
}
void MyString::print()
{
    cout << pBuf << endl;
}

int main()
{
    MyString str1("Kookmin");
    MyString str2("Univ");
    MyString str3(str1);

    str1.print();
    str2.print();
    str3.print();

    str1.add(str2);
    str1.print();
}