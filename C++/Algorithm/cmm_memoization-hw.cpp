#include <iostream>
using namespace std;

#define _NUM_MATRIX_ 100
int minMulTable[_NUM_MATRIX_][_NUM_MATRIX_];

void clearTable(int(*)[_NUM_MATRIX_], int); 
int minMultiple(int*, int, int);

int main()
{
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        int matrixInfomations[_NUM_MATRIX_ + 1];
        int numMatrix;
        cin >> numMatrix;
        clearTable(minMulTable, numMatrix);
        for (int k = 0; k < numMatrix; k++) { minMulTable[k][k] = 0; }    // base case

        for (int j = 0; j <= numMatrix; j++) { cin >> matrixInfomations[j]; }

        int result = minMultiple(matrixInfomations, 0, numMatrix);
        cout << result << endl;
    }
}

void clearTable(int(*table)[_NUM_MATRIX_], int n)
{ for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { table[i][j] = __INT32_MAX__; } } }

int minMultiple(int* informations, int start, int end)
{
    if (minMulTable[start][end - 1] != __INT32_MAX__) { return minMulTable[start][end - 1]; }
    for (int k = start + 1; k < end; k++)
    {
        int mul = informations[start] * informations[k] * informations[end];
        int result = minMultiple(informations, start, k) + minMultiple(informations, k, end) + mul;
        if (result < minMulTable[start][end - 1]) { minMulTable[start][end - 1] = result; }
    }
    return minMulTable[start][end - 1];
}