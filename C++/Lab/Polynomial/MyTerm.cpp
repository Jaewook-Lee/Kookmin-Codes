#include "MyTerm.h"

/* Constructors */
MyTerm::MyTerm(int c, unsigned int e) : coefficient(c), exponent(e) {}
MyTerm::MyTerm(const MyTerm& term) : coefficient(term.coefficient), exponent(term.exponent) {} // Copy Constructor

/* Accessor & Mutator Functions */
int MyTerm::getCoeff() const { return coefficient; }
unsigned int MyTerm::getExp() const { return exponent; }
void MyTerm::setCoeff(int c) { coefficient = c; }
void MyTerm::setExp(unsigned int e) { exponent = e; }

/* Member Function */
MyTerm MyTerm::ddx () const
{
    if (exponent == 0) return MyTerm(0, 0);

    MyTerm derivated = MyTerm(coefficient * exponent, exponent - 1);
    return derivated;
}

/* Comparison Operators */
bool MyTerm::operator ==(const MyTerm& term) const { return (coefficient == term.coefficient && exponent == term.exponent); }
bool MyTerm::operator !=(const MyTerm& term) const { return (coefficient != term.coefficient || exponent != term.exponent); }
bool MyTerm::operator <(const MyTerm& term) const { return (exponent > term.coefficient); }

/* Unary Operators */
MyTerm MyTerm::operator -() { return MyTerm(-coefficient, exponent); }

/* Output Operators */
ostream& operator <<(ostream& outStream, const MyTerm& term)
{
    if (term.exponent == 0 && term.coefficient == 0) return outStream;
    else outStream << term.coefficient;

    if (term.coefficient == 1) outStream << "x";
    else if (term.coefficient == -1) outStream << "-x";
    else outStream << term.coefficient << "x";

    if (term.exponent == 1) return outStream;
    else outStream << "^" << term.exponent;

    return outStream;
}