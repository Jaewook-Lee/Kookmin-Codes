#include "My2Matrix.h"

int main()
{
    int numTestCases;
    cin >> numTestCases;

    for (int i=0; i<numTestCases; i++)
    {
        int a11, a12, a21, a22;
        cin >> a11 >> a12 >> a21 >> a22;
        My2Matrix m1(a11, a12, a21, a22);

        cin >> a11 >> a12 >> a21 >> a22;
        My2Matrix m2(a11, a12, a21, a22);

        cout << m1 << endl << m2 << endl;
        cout << -m1 + 2*m2 << endl;
    }
    return 0;
}