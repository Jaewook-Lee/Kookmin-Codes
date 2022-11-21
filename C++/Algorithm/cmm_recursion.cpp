#include <iostream>
using namespace std;

#define _NUM_MATRIX_ 10

int minMultiple(int[], int, int);

int main()
{
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        int matrixInfomations[_NUM_MATRIX_ + 1];
        int numMatrix;
        cin >> numMatrix;

        for (int j = 0; j <= numMatrix; j++) { cin >> matrixInfomations[j]; }

        int result = minMultiple(matrixInfomations, 0, numMatrix);
        cout << result << endl;
    }
}

int minMultiple(int informations[], int start, int end)
{
    if (end - start == 1) { return 0; }
    else
    {
        int minimum = __INT32_MAX__;
        for (int i = start + 1; i < end; i++)
        {
            int mul = informations[start] * informations[i] * informations[end];
            int leftResult = minMultiple(informations, start, i);
            int rightResult = minMultiple(informations, i, end);
            int hap = leftResult + rightResult + mul;
            if (hap < minimum) { minimum = hap; }
        }

        return minimum;
    }
}