#ifndef _MYTERM_H_
#define _MYTERM_H_

#include <iostream>
using namespace std;

class MyTerm
{
    int coefficient;
    unsigned int exponent;

    public:
        /* Constructors */
        MyTerm(int=0, unsigned int=0);
        MyTerm(const MyTerm&); // Copy Constructor

        /* Accessor & Mutator Functions */
        int getCoeff() const;
        unsigned int getExp() const;
        void setCoeff(int);
        void setExp(unsigned int);

        /* Member Function*/
        MyTerm ddx() const;

        /* Comparison Operators */
        bool operator ==(const MyTerm&) const;
        bool operator !=(const MyTerm&) const;
        bool operator <(const MyTerm&) const;

        /* Unary Operators */
        MyTerm operator -();

        /* Output Operator */
        friend ostream& operator <<(ostream&, const MyTerm&);

        friend class MyPolynomial; // Friend Class declaration
};

#endif