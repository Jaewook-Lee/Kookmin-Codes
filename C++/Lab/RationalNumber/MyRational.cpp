#include "MyRational.h"

/* Private Functions */
long MyRational::gcd(long m, long n)
{
    if (m == n) return n;
    else if (m < n) return gcd(m, n - m);
    else return gcd(m - n, n);
}
void MyRational::reduce()
{
    if (_num == 0 || _den == 0)
    {
        _num = 0;
        _den = 1;
    }

    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }

    if (_num == 1) return;

    int sgn = _num < 0 ? -1 : 1; // 숫자의 부호를 표현하기 위한 변수라 추측.
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
}

/* Constructor */
MyRational::MyRational(long num, long den)
{
    _num = num;
    _den = den;

    if (_num != 0) reduce();
}
MyRational::MyRational(const MyRational& r)
{
    _num = r._num;
    _den = r._den;

    if (_num != 0) reduce();
}

/* Accessor Function */
long MyRational::getNumerator() const { return _num; }
long MyRational::getDenominator() const { return _den; }
void MyRational::setNumerator(long num)
{
    _num = num;
    reduce();
}
void MyRational::setDenominator(long den)
{
    _den = den;
    reduce();
}

MyRational MyRational::reciprocal() const { return MyRational(_den, _num); }

/* Overloaded binary operations(with rational number) */
MyRational MyRational::operator +(const MyRational& r) const
{
    long new_num = _num * r._den + r._num * _den;
    long new_den = _den * r._den;
    MyRational new_rational = MyRational(new_num, new_den);

    return new_rational;
}
MyRational MyRational::operator -(const MyRational& r) const
{
    long new_num = _num * r._den - r._num * _den;
    long new_den = _den * r._den;
    MyRational new_rational = MyRational(new_num, new_den);
    
    return new_rational;
}
MyRational MyRational::operator *(const MyRational& r) const
{
    long new_num = _num * r._num;
    long new_den = _den * r._den;
    MyRational new_rational = MyRational(new_num, new_den);
    
    return new_rational;
}
MyRational MyRational::operator /(const MyRational& r) const { return (*(this) * r.reciprocal()); }

/* Overloaded binary operations(with decimal number) */
MyRational MyRational::operator +(int decimal) const
{
    MyRational new_rational = MyRational(_num + decimal * _den, _den);
    return new_rational;
}
MyRational MyRational::operator -(int decimal) const
{
    MyRational new_rational = MyRational(_num - decimal * _den, _den);
    return new_rational;
}
MyRational MyRational::operator *(int decimal) const
{
    MyRational new_rational = MyRational(_num * decimal, _den);
    return new_rational;
}
MyRational MyRational::operator /(int decimal) const
{
    MyRational new_rational = MyRational(_num, _den * decimal);
    return new_rational;
}
MyRational operator +(int number, const MyRational& r)
{
    MyRational new_rational = MyRational(r._den * number + r._num, r._den);
    return new_rational;
}
MyRational operator -(int number, const MyRational& r)
{
    MyRational new_rational = MyRational(r._den * number - r._num, r._den);
    return new_rational;
}
MyRational operator *(int number, const MyRational& r)
{
    MyRational new_rational = MyRational(number * r._num, r._den);
    return new_rational;
}
MyRational operator /(int number, const MyRational& r)
{
    MyRational new_rational = MyRational(number * r._den, r._num);
    return new_rational;
}

/* Overloaded unary operators */
MyRational MyRational::operator -() { return MyRational((-1) * _num, _den); }
MyRational MyRational::operator --()
{
    this->_num -= _den;
    return MyRational(_num, _den);
}
MyRational MyRational::operator --(int dummy)
{
    MyRational origin_rational = *this;
    _num -= _den;
    return origin_rational;
}
MyRational MyRational::operator ++()
{
    this->_num += _den;
    return MyRational(_num, _den);
}
MyRational MyRational::operator ++(int dummy)
{
    MyRational origin_rational = *this;
    _num += _den;

    return origin_rational;
}

/* Overloaded comparison operators(with rational number) */
bool MyRational::operator ==(const MyRational& r) const { return (_num == r._num && _den == r._den); }
bool MyRational::operator !=(const MyRational& r) const { return (_num != r._num || _den != r._den); }
bool MyRational::operator >(const MyRational& r) const
{
    long left = _num * r._den;
    long right = r._num * _den;

    if (left > right) return true;
    else return false;
}
bool MyRational::operator >=(const MyRational& r) const
{
    long left = _num * r._den;
    long right = r._num * _den;

    if (left >= right) return true;
    else return false;
}
bool MyRational::operator <(const MyRational& r) const
{
    long left = _num * r._den;
    long right = r._num * _den;

    if (left < right) return true;
    else return false;
}
bool MyRational::operator <=(const MyRational& r) const
{
    long left = _num * r._den;
    long right = r._num * _den;

    if (left <= right) return true;
    else return false;
}

/* Overloaded comparison operators(with decimal number) */
bool MyRational::operator ==(int number) const { return (*this == MyRational(number)); }
bool MyRational::operator !=(int number) const { return (*this != MyRational(number)); }
bool MyRational::operator >(int number) const { return (*this - MyRational(number) > 0); }
bool MyRational::operator >=(int number) const { return (*this - MyRational(number) >= 0); }
bool MyRational::operator <(int number) const { return (*this - MyRational(number) < 0); }
bool MyRational::operator <=(int number) const { return (*this - MyRational(number) <= 0); }

bool operator ==(int number, const MyRational& r) { return (MyRational(number) == r); }
bool operator !=(int number, const MyRational& r) { return (MyRational(number) != r); }
bool operator >(int number, const MyRational& r) { return (MyRational(number) > r); }
bool operator >=(int number, const MyRational& r) { return (MyRational(number) >= r); }
bool operator <(int number, const MyRational& r) { return (MyRational(number) < r); }
bool operator <=(int number, const MyRational& r) { return (MyRational(number) <= r); }

/* Overloaded assignment operators */
MyRational& MyRational::operator =(const MyRational& r)
{
    _num = r._num;
    _den = r._den;

    return *this;
}
MyRational& MyRational::operator =(int number)
{
    _num = number;
    _den = 1;

    return *this;
}

/* Overloaded complex assignment operators(with rational number) */
MyRational& MyRational::operator +=(const MyRational& r)
{
    *this = *this + r;

    return *this;
}
MyRational& MyRational::operator -=(const MyRational& r)
{
    *this = *this - r;

    return *this;
}
MyRational& MyRational::operator *=(const MyRational& r)
{
    *this = *this * r;

    return *this;
}
MyRational& MyRational::operator /=(const MyRational& r)
{
    *this = *this / r;

    return *this;
}

/* Overloaded complex assignment operators(with decimal number) */
MyRational& MyRational::operator +=(int number)
{
    *this = *this + number;

    return *this;
}
MyRational& MyRational::operator -=(int number)
{
    *this = *this - number;

    return *this;
}
MyRational& MyRational::operator *=(int number)
{
    *this = *this * number;

    return *this;
}
MyRational& MyRational::operator /=(int number)
{
    *this = *this / number;

    return *this;
}

ostream& operator <<(ostream& outStream, const MyRational& r)
{
    
    if (r._num == 0) outStream << 0;
    else if (r._den == 1) outStream << r._num;
    else outStream << r._num << "/" << r._den;

    return outStream;
}

istream& operator >>(istream& inStream, MyRational& r)
{
    inStream >> r._num >> r._den;
    if (r._den == 0)
    {
        r._num = 0;
        r._den = 1;
    }
    r.reduce();

    return inStream;
}