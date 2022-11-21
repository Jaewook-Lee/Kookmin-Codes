#include <iostream>
using namespace std;

#define _NUM_MATRIX_ 100
int minMulTable[_NUM_MATRIX_][_NUM_MATRIX_];
int orderToPrint[_NUM_MATRIX_][_NUM_MATRIX_];

void clearTable(int(*)[_NUM_MATRIX_], int); 
void printOrder(int, int);
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
        clearTable(orderToPrint, numMatrix);
        for (int k = 0; k < numMatrix; k++) { minMulTable[k][k] = 0; }    // base case

        for (int j = 0; j <= numMatrix; j++) { cin >> matrixInfomations[j]; }

        int result = minMultiple(matrixInfomations, 0, numMatrix);

        printOrder(0, numMatrix - 1); cout << endl;
        cout << result << endl;
    }
}

void clearTable(int(*table)[_NUM_MATRIX_], int n)
{ for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { table[i][j] = __INT32_MAX__; } } }

int minMultiple(int* informations, int start, int end)
{
    for (int diagonal = start + 1; diagonal < end; diagonal++)
    {
        for (int i = start; i < end - diagonal; i++)
        {
            int j = diagonal + i;
            for (int k = i; k < j; k++)
            {
                int mul = informations[i] * informations[k + 1] * informations[j + 1];
                int result = minMulTable[i][k] + minMulTable[k + 1][j] + mul;
                if (result < minMulTable[i][j])
                {
                    minMulTable[i][j] = result;
                    orderToPrint[i][j] = k;
                }
            }
        }
    }
    return minMulTable[start][end - 1];
}

void printOrder(int i, int j)
{
    if (i == j) { cout << "M" << i + 1; }
    else
    {
        int k = orderToPrint[i][j];
        cout << "(";
        printOrder(i, k);
        printOrder(k + 1, j);
        cout << ")";
    }
}