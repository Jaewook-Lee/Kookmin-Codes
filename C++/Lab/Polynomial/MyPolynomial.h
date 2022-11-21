#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_

#include <iostream>
#include "MyTerm.h"
using namespace std;

class MyPolynomial
{
    unsigned int degree;
    MyTerm *terms; // Array of MyTerm type.
    void sortPoly(MyTerm*, long);

    public:
        /* Constructors */
        MyPolynomial(int=0, unsigned int=0); // Make a term.
        MyPolynomial(int, int[]); // Make a polynomial
        MyPolynomial(const MyPolynomial&); // Copy Constructor

        /* Destructor */
        ~MyPolynomial();

        /* Accessor & Mutator Functions */
        unsigned int getDegree() const; // Get biggest degree
        int getNumTerms() const; // Get numbers of term
        void setCoeff(int); // Set a term's coefficient

        /* Member Function */
        MyPolynomial ddx() const;

        /* Overloaded binary operators(with polynomial) */
        MyPolynomial operator +(const MyPolynomial&) const;
        MyPolynomial operator -(const MyPolynomial&) const;
        MyPolynomial operator *(const MyPolynomial&) const;

        /* Overloaded binary operators(with decimal number)*/
        MyPolynomial operator *(int) const;
        friend MyPolynomial operator *(int, const MyPolynomial&);

        /* Overloaded calculate operator */
        long operator ()(int) const;

        /* Overloaded unary operator */
        MyPolynomial operator -() const;

        /* Overloaded comparison operators */
        bool operator ==(const MyPolynomial&);
        bool operator !=(const MyPolynomial&);

        /* Overloaded assignment operator */
        MyPolynomial& operator =(const MyPolynomial&);

        /* Overloaded complex assignment operators(with polynomial) */
        MyPolynomial& operator +=(const MyPolynomial&);
        MyPolynomial& operator -=(const MyPolynomial&);
        MyPolynomial& operator *=(const MyPolynomial&);

        /* Overloaded complex assignment operators(with decimal number) */
        MyPolynomial& operator *=(int);

        /* Output operator */
        friend ostream& operator <<(ostream&, const MyPolynomial&);
};

#endif