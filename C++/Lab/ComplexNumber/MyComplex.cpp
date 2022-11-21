#include "MyComplex.h"

// Constructor
MyComplex::MyComplex(int real, int img)
{
    realPart = real;
    imaginaryPart = img;
}

// Copy Constructor
MyComplex::MyComplex(const MyComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}

// Accessor functions
int MyComplex::getRealPart() const { return realPart; }
int MyComplex::getImaginaryPart() const { return imaginaryPart; }

// Mutator functions
void MyComplex::setRealPart(int real) { realPart = real; }
void MyComplex::setImaginaryPart(int img) { imaginaryPart = img; }
void MyComplex::set(int real, int img)
{
    realPart = real;
    imaginaryPart = img;
}

// Overloaded binary operators
MyComplex MyComplex::operator+(const MyComplex& number) const
{
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return MyComplex(newReal, newImag);
}
MyComplex MyComplex::operator-(const MyComplex& number) const
{
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return MyComplex(newReal, newImag);
}
MyComplex MyComplex::operator*(const MyComplex& number) const
{
    int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
    int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
    return MyComplex(newReal, newImag);
}
MyComplex& MyComplex::operator+=(const MyComplex& number)
{
    *this = *this + number;
    return *this;
}
MyComplex& MyComplex::operator-=(const MyComplex& number)
{
    *this = *this - number;
    return *this;
}
MyComplex& MyComplex::operator*=(const MyComplex& number)
{
    *this = *this * number;
    return *this;
}

MyComplex MyComplex::operator+(int value) const { return MyComplex(value) + *(this); }
MyComplex MyComplex::operator-(int value) const { return *(this) - MyComplex(value); }
MyComplex MyComplex::operator*(int value) const
{
    int newReal = realPart * value;
    int newImag = imaginaryPart * value;
    return MyComplex(newReal, newImag);
}
MyComplex& MyComplex::operator+=(int value)
{
    *this = *this + value;
    return *this;
}
MyComplex& MyComplex::operator-=(int value)
{
    *this = *this - value;
    return *this;
}
MyComplex& MyComplex::operator*=(int value)
{
    *this = *this * value;
    return *this;
}

// Assignment operators
MyComplex& MyComplex::operator=(const MyComplex& number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
MyComplex& MyComplex::operator=(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}

// Overloading comparison operators
bool MyComplex::operator ==(const MyComplex& number) const { return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart); }
bool MyComplex::operator !=(const MyComplex& number) const { return (realPart != number.realPart) || (imaginaryPart != number.imaginaryPart); }
bool MyComplex::operator >(const MyComplex& number) const { return norm() > number.norm(); }
bool MyComplex::operator >=(const MyComplex& number) const { return norm() >= number.norm(); }
bool MyComplex::operator <(const MyComplex& number) const { return norm() < number.norm(); }
bool MyComplex::operator <=(const MyComplex& number) const { return norm() <= number.norm(); }

// Overloading unary operators
MyComplex MyComplex::operator -() { return MyComplex(-realPart, -imaginaryPart); }
MyComplex MyComplex::operator --()
{ 
    this->realPart--;
    return MyComplex(realPart, imaginaryPart);
}
MyComplex MyComplex::operator --(int dummy)
{
    MyComplex origin_complex = *this;
    this->realPart--;
    return origin_complex;
}
MyComplex MyComplex::operator ++()
{
    this->realPart++;
    return MyComplex(realPart, imaginaryPart);
}
MyComplex MyComplex::operator ++(int dummy)
{
    MyComplex origin_complex = *this;
    this->realPart++;
    return origin_complex;
}
MyComplex MyComplex::operator ~() { return MyComplex(realPart, -imaginaryPart); }

// private function
int MyComplex::norm() const { return realPart * realPart + imaginaryPart * imaginaryPart; }

// Friend Funtions
MyComplex operator +(int value, const MyComplex& number) { return MyComplex(value + number.realPart, number.imaginaryPart); }
MyComplex operator -(int value, const MyComplex& number) { return MyComplex(value - number.realPart, -number.imaginaryPart); }
MyComplex operator *(int value, const MyComplex& number) { return MyComplex(value * number.realPart, value * number.imaginaryPart); }

ostream &operator <<(ostream &outStream, const MyComplex& number)
{
    outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return outStream;
}
istream &operator >>(istream &inStream, MyComplex& number)
{
    inStream >> number.realPart >> number.imaginaryPart;
    return inStream;
}