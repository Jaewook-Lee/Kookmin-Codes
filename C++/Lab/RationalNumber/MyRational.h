#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_

#include <iostream>
using namespace std;

class MyRational
{
    // 분수는 항상 내부적으로 기약분수로 표현!, 항상 _den(분모) > 0이다!
    long _num, _den;
    long gcd(long=0, long=1);
    void reduce();

    public:
        /* Constructor */
        MyRational(long num=0, long den=1);
        MyRational(const MyRational&);

        /* Accessor Function */
        long getNumerator() const;
        long getDenominator() const;
        void setNumerator(long);
        void setDenominator(long);

        MyRational reciprocal() const; // 분수의 역수를 리턴하는 함수

        /* Overloaded binary operators(with rational number) */
        MyRational operator +(const MyRational&) const;
        MyRational operator -(const MyRational&) const;
        MyRational operator *(const MyRational&) const;
        MyRational operator /(const MyRational&) const;

        /* Overloaded binary operators(with decimal number) */
        MyRational operator +(int) const;
        MyRational operator -(int) const;
        MyRational operator *(int) const;
        MyRational operator /(int) const;

        friend MyRational operator +(int, const MyRational&);
        friend MyRational operator -(int, const MyRational&);
        friend MyRational operator *(int, const MyRational&);
        friend MyRational operator /(int, const MyRational&);

        /* Overloaded unary operators */
        MyRational operator -();
        MyRational operator --();
        MyRational operator --(int);
        MyRational operator ++();
        MyRational operator ++(int);

        /* Overloaded comparison operators(with rational number) */
        bool operator ==(const MyRational&) const;
        bool operator !=(const MyRational&) const;
        bool operator >(const MyRational&) const;
        bool operator >=(const MyRational&) const;
        bool operator <(const MyRational&) const;
        bool operator <=(const MyRational&) const;

        /* Overloaded comparison operators(with decimal number) */
        bool operator ==(int) const;
        bool operator !=(int) const;
        bool operator >(int) const;
        bool operator >=(int) const;
        bool operator <(int) const;
        bool operator <=(int) const;

        friend bool operator ==(int, const MyRational&);
        friend bool operator !=(int, const MyRational&);
        friend bool operator >(int, const MyRational&);
        friend bool operator >=(int, const MyRational&);
        friend bool operator <(int, const MyRational&);
        friend bool operator <=(int, const MyRational&);
        

        /* Overloaded assignment operators */
        MyRational& operator =(const MyRational&);
        MyRational& operator =(int);

        /* Overloaded complex assignment operators(with rational number) */
        MyRational& operator +=(const MyRational&);
        MyRational& operator -=(const MyRational&);
        MyRational& operator *=(const MyRational&);
        MyRational& operator /=(const MyRational&);

        /* Overloaded complex assignment operators(with decimal number) */
        MyRational& operator +=(int);
        MyRational& operator -=(int);
        MyRational& operator *=(int);
        MyRational& operator /=(int);

        /* Input and Output operators */
        friend ostream& operator <<(ostream&, const MyRational&);
        friend istream& operator >>(istream&, MyRational&);
};

#endif