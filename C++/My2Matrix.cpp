#include <cstdlib>
#include "My2Matrix.h"

// constructors
My2Matrix::My2Matrix() : a11(0), a12(0), a21(0), a22(0) {}
My2Matrix::My2Matrix(int a, int b, int c, int d) : a11(a), a12(b), a21(c), a22(d) {}

//operators
My2Matrix My2Matrix::operator+ (const My2Matrix& m)
{
    return My2Matrix(a11 + m.a11, a12 + m.a12, a21 + m.a21, a22 + m.a22);
}
My2Matrix operator* (int c, const My2Matrix& m)
{
    return My2Matrix(m.a11*c, m.a12*c, m.a21*c, m.a22*c);
}
My2Matrix My2Matrix::operator- ()
{
    return My2Matrix(-a11, -a12, -a21, -a22);
}
ostream& operator <<(ostream& os, const My2Matrix& m)
{
    os << m.a11 << " " << m.a12 << endl;
    os << m.a21 << " " << m.a22;

    return os;
}