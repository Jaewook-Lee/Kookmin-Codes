#include "MyComplex.h"

void testSimpleCase();
void testDataFromFile();

int main()
{
    testSimpleCase();
    testDataFromFile();
    return 0;
}

void testSimpleCase()
{
    MyComplex c0, c1(1), c2(2, 2), c3(c2), c4, c5, c6, c7, c8, c9;

    // Test Constructor
    cout << c0 << endl << c1 << endl << c2 << endl;

    // Test Copy Constructor
    cout << c3 << endl;

    // Test Accessor function
    cout << c3 << endl;

    // Test Mutator function
    c3.set(3, 3);
    cout << c3 << endl;
    c3.setRealPart(4);
    cout << c3 << endl;
    c3.setImaginaryPart(4);
    cout << c3 << endl;

    // Test binary operations
    c4 = c1 + c3;
    c5 = c1 - c3;
    c6 = c4 * c5;
    cout << c4 << endl << c5 << endl << c6 << endl;

    c7 = c6 + 2;
    c8 = c6 - 2;
    c9 = c6 * 2;
    cout << c7 << endl << c8 << endl << c9 << endl;

    c7 += c4;
    c8 -= c5;
    c9 *= c6;
    cout << c7 << endl << c8 << endl << c9 << endl;

    c7 += 2;
    c8 -= 2;
    c9 *= 2;
    cout << c7 << endl << c8 << endl << c9 << endl;

    // Test comparison operators
    cout << (c8 != c9) << " " << (c8 == c9) << endl;
    cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <= c9) << endl;

    c7 = c8 = c9;
    cout << (c8 != c9) << " " << (c8 == c9) << endl;
    cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <= c9) << endl;

    // Test unary operation
    c7 = -MyComplex(2, 3); // -2 -3i
    c8 = (++c7) * 2; // -2 -6i, c7 = -1 -3i
    c9 = 2 * (c7++); // -2 -6i, c7 = 0 -3i
    cout << c7 << " " << c8 << " " << c9 << endl;

    c7 = ~MyComplex(2, 3); // 2 -3i
    c8 = (--c7) * 2; // 2 -6i, c7 = 1 - 3i
    c9 = 2 * (c7--); // 2 - 6i, c7 = 0 - 3i
    cout << c7 << " " << c8 << " " << c9 << endl;

    // Test expressions with MyComplex numbers
    c1 = MyComplex(1, 2);
    c2 = MyComplex(2, 3);
    c3 = MyComplex(4, 5);
    c4 = MyComplex(5, 6);
    c5 = MyComplex(6, 7);
    c6 = 3;
    cout << -(c1 * c2) - 2 * c3 + ~c4 * c5 * 3 + 2 - c6 << endl;
}

void testDataFromFile()
{
    int numTestCases;
    cin >> numTestCases;
    for (int i=0; i<numTestCases; i++)
    {
        MyComplex c1, c2, c3, c4;
        MyComplex c5, c6, c7, c8, c9;

        cin >> c1 >> c2 >> c3 >> c4;

        cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
        cout << (2 + c1 + 3) + (2 - c2 - 3) * (2 * c3 * 3) - ( 2 * c4 - 3) << endl;
        c5 = c6 = c7 = c8 = c1;
        cout << (c5 == c2) << " " << (c5 != c2) << endl;
        cout << (c5 > c2) << " " << (c5 >= c2) << " " << (c5 < c2) << " " << (c5 <= c2) << endl;
        cout << (c5 == c6) << " " << (c5 != c6) << endl;
        cout << (c5 > c6) << " " << (c5 >= c6) << " " << (c5 < c6) << " " << (c5 <= c6) << endl;

        c5 += c2;
        c6 -= c3;
        c7 *= c4;
        c8 = c2.getRealPart();
        c9 = c3.getImaginaryPart();
        cout << c5 << " " << c6 << " " << c7 << " " << c8 << " " << c9 << endl;

        c7 = -c6;
        c8 = (++c7) * 2;
        c9 = 2 * (c7++);
        cout << c7 << " " << c8 << " " << c9 << endl;

        c7 = ~c6;
        c8 = (++c7) * 2;
        c9 = 2 * (c7++);
        cout << c7 << " " << c8 << " " << c9 << endl;
    }
}