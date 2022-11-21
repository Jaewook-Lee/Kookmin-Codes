#include <fstream>
#include <cstdlib>
#include "MyPolynomial.h"

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
    /* Test static variables */
    cout << MyPolynomial::ZERO << endl;
    cout << MyPolynomial::ONE << endl;
    cout << MyPolynomial::X << endl;

    MyPolynomial p0, p1(1), p2(1, 1), p3(3, 5);

    int testData4[10] = {1, 0, 1, 1, 1, 2, 1, 3, 1, 4};
    int testData5[10] = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4};
    int testData6[10] = {1, 0, -1, 1, 1, 2, -1, 3, 1, 4};
    int testData7[10] = {2, 2, 5, 5, 4, 4, 1, 1, 3, 3};
    int testData8[12] = {1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0};

    MyPolynomial p4(5, testData4);
    MyPolynomial p5(5, testData5);
    MyPolynomial p6(5, testData6);
    MyPolynomial p7(5, testData7);
    MyPolynomial p8(6, testData8);
    MyPolynomial p9(p7);

    /* Test Constructor */
    cout << p0 << endl << p1 << endl << p2 << endl;
    cout << p4 << endl << p8 << endl;

    /* Test Copy Constructor */
    cout << p9 << endl;

    /* Test Accessor Function */
    cout << p8.getDegree() << " " << p8.getNumTerms() << endl;

    /* Test Evaluation Function */
    cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
    cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;

    /* Test Comparison Operators */
    cout << (p7 == p9) << " " << (p7 != p9) << endl;

    /* Test Derivative Function */
    cout << MyPolynomial::ZERO.ddx() << endl;
    cout << MyPolynomial::ONE.ddx() << endl;
    cout << MyPolynomial::X.ddx() << endl;
    cout << p4.ddx() << endl;
    cout << p8.ddx() << endl;

    /* Test Unary Operator - */
    cout << -MyPolynomial::ZERO << endl;
    cout << -p4 << endl;

    /* Test (k * p(x)) or (p(x) * k) */
    cout << 3 * MyPolynomial::ZERO << endl;
    cout << 3 * MyPolynomial::ONE << endl;
    cout << MyPolynomial::X * 3 << endl;
    cout << 3 * p4 << " " << p4 * 3 << endl;
    cout << 0 * p5 << " " << p5 * 5 << endl;

    /* Test binary operator + */
    cout << p4 + p5 << endl;

    /* Test binary operator - */
    cout << p6 - p7 << endl;

    /* Test binary operator * */
    cout << p8 * p9 << endl;

    MyPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;

    cout << (tmp1 += p5) << endl;
    cout << (tmp2 -= p5) << endl;
    cout << (tmp3 *= p5) << endl;
    cout << (tmp4 *= 3) << endl;
}

void testDataFromFile()
{
    ifstream inStream;
    int numTestCases;
    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }

    inStream >> numTestCases;
    for (int i=0; i<numTestCases; i++)
    {
        int numTerms, terms[100];

        /* Read First Polynomial */
        inStream >> numTerms;
        for (int j=0; j<numTerms; j++)
        {
            inStream >> terms[2 * j] >> terms[2 * j + 1];
        }
        MyPolynomial p1(numTerms, terms);

        /* Read Second Polynomial */
        inStream >> numTerms;
        for (int j=0; j<numTerms; j++)
        {
            inStream >> terms[2 * j] >> terms[2 * j + 1];
        }
        MyPolynomial p2(numTerms, terms);

        cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;

        MyPolynomial p3(MyPolynomial::ZERO), p4(MyPolynomial::ONE), p5(MyPolynomial::X);
        p3 += p1;
        p4 -= p2;
        p5 *= p4;
        p5 *= 2;

        cout << p5 << endl;
    }

    inStream.close();
}