#include "MyRational.h"
using namespace std;

void testSimpleCase();
void testDataFromFile();
void sortRationals(MyRational[], int);
void printRationals(MyRational[], int);
int main()
{
    testSimpleCase();
    testDataFromFile();
    return 0;
}

void testSimpleCase()
{
    MyRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << endl;
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;

    // Check arithmetic operators
    cout << frac1 * frac2 << " " << frac1 + frac3 << " " << frac2 - frac1 << " " << frac3 / frac2 << endl;

    // Check comparison operators
    cout << ((frac1 < frac2) ? 1 : 0) << " " << ((frac1 <= frac2) ? 1 : 0) << " " << ((frac1 > frac2) ? 1 : 0) << " " << ((frac1 >= frac2) ? 1 : 0) << " " << ((frac1 == frac2) ? 1 : 0) << " " << ((frac1 != frac2) ? 1 : 0) << " " << ((frac2 < frac3) ? 1 : 0) << " " << ((frac2 <= frac3) ? 1 : 0) << " " << ((frac2 > frac3) ? 1 : 0) << " " << ((frac2 >= frac3) ? 1 : 0) << " " << ((frac2 == frac3) ? 1 : 0) << " " << ((frac2 != frac3) ? 1 : 0) << endl;

    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << endl;

    cout << -frac6 << endl;

    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;

    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;

    cout << 2 * frac3 << " " << frac3 * 2 << " " << 2 / frac3 << " " << frac3 / 2 << endl;
}

void testDataFromFile()
{
    int numTestCases;
    cin >> numTestCases;
    for (int i=0; i<numTestCases; i++)
    {
        int numRationals;
        cin >> numRationals;
        MyRational rationals[numRationals];
        for (int j=0; j<numRationals; j++)
        {
            MyRational tmp;
            cin >> tmp;
            rationals[j] = tmp;
        }

        sortRationals(rationals, numRationals);
        printRationals(rationals, numRationals);
    }
}

void sortRationals(MyRational rational_array[], int size)
{
    for (int i=0; i<size-1; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (rational_array[i] > rational_array[j])
            {
                MyRational temp = rational_array[i];
                rational_array[i] = rational_array[j];
                rational_array[j] = temp;
            }
        }
    }
}

void printRationals(MyRational rational_array[], int size)
{
    for (int i=0; i<size; i++) cout << rational_array[i] << " ";
    cout << endl;
}