#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_

#include <iostream>
using namespace std;

class MyComplex
{
    public:
        // Constructor
        MyComplex(int real=0, int img=0);
        // Copy Constructor
        MyComplex(const MyComplex&);

        //Accessor functions
        int getRealPart() const;
        int getImaginaryPart() const;

        //Mutator functions
        void setRealPart(int);
        void setImaginaryPart(int);
        void set(int, int);

        //Overloaded binary operators
        MyComplex operator +(const MyComplex&) const;
        MyComplex operator +(int) const;
        friend MyComplex operator +(int, const MyComplex&);
        MyComplex operator -(const MyComplex&) const;
        MyComplex operator -(int) const;
        friend MyComplex operator -(int, const MyComplex&);
        MyComplex operator *(const MyComplex&) const;
        MyComplex operator *(int) const;
        friend MyComplex operator *(int, const MyComplex&);

        MyComplex& operator +=(const MyComplex&);
        MyComplex& operator +=(int);
        MyComplex& operator -=(const MyComplex&);
        MyComplex& operator -=(int);
        MyComplex& operator *=(const MyComplex&);
        MyComplex& operator *=(int);

        //Overloaded assignment operators
        MyComplex& operator =(const MyComplex&);
        MyComplex& operator =(int);

        //Overloaded relational operators
        bool operator ==(const MyComplex&) const;
        bool operator !=(const MyComplex&) const;
        bool operator >(const MyComplex&) const;
        bool operator >=(const MyComplex&) const;
        bool operator <(const MyComplex&) const;
        bool operator <=(const MyComplex&) const;

        //Overloaded unary operators
        MyComplex operator -();
        MyComplex operator --();
        MyComplex operator --(int);
        MyComplex operator ++();
        MyComplex operator ++(int);
        MyComplex operator ~();

        //Overloaded print and input function
        friend ostream& operator <<(ostream&, const MyComplex&);
        friend istream& operator >>(istream&, MyComplex&);

    private:
        int realPart;
        int imaginaryPart;
        int norm() const;
};

#endif
