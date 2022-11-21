#ifndef _MY_2Matrix_H_
#define _MY_2Matrix_H_
#include <iostream>
using namespace std;

class My2Matrix
{
    int a11, a12, a21, a22;
    public:
        // constructors
        My2Matrix();
        My2Matrix(int a, int b, int c, int d);

        // operators
        My2Matrix operator +(const My2Matrix&);
        friend My2Matrix operator *(int, const My2Matrix&);
        My2Matrix operator -();

        friend ostream& operator<<(ostream&, const My2Matrix&);
};

#endif