#include <iostream>
using namespace std;

#define _MATRIX_SIZE_ 2

struct FibonacciMatrix
{
    int myMatrix[_MATRIX_SIZE_][_MATRIX_SIZE_] = {{1, 1}, {1, 0}};
};

int fibonacci(int, FibonacciMatrix*);
FibonacciMatrix* matrixPower(FibonacciMatrix*, int);
FibonacciMatrix* matmul(FibonacciMatrix*, FibonacciMatrix*);

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int n;
        cin >> n;
        FibonacciMatrix myMatrix;
        cout << fibonacci(n, &myMatrix) << endl;
    }
    return 0;
}

int fibonacci(int n, FibonacciMatrix* target)
{
    if (n <= 1) { return n; }
    else if (n == 2) { return 1; }
    else
    {
        FibonacciMatrix* resultMatrix = matrixPower(target, n - 1);
        return resultMatrix->myMatrix[0][0];
    }
}

FibonacciMatrix* matrixPower(FibonacciMatrix* matrix, int m)
{
    if (m == 1)
    {
        FibonacciMatrix* returnMatrix = new FibonacciMatrix;
        return returnMatrix;
    }
    else if (m % 2)
    {
        FibonacciMatrix* resultMatrix = matrixPower(matrix, (m - 1) / 2);
        FibonacciMatrix* restMatrix = new FibonacciMatrix;
        return matmul(restMatrix, matmul(resultMatrix, resultMatrix));
    }
    else
    {
        FibonacciMatrix* resultMatrix = matrixPower(matrix, m / 2);
        return matmul(resultMatrix, resultMatrix);
    }
}

FibonacciMatrix* matmul(FibonacciMatrix* matrixA, FibonacciMatrix* matrixB)
{
    FibonacciMatrix* matrixC = new FibonacciMatrix;
    for (int i = 0; i < _MATRIX_SIZE_; i++)
    {
        for (int j = 0; j < _MATRIX_SIZE_; j++)
        {
            int sum = 0;
            for (int k = 0; k < _MATRIX_SIZE_; k++) { sum += matrixA->myMatrix[i][k] * matrixB->myMatrix[k][j]; }
            matrixC->myMatrix[i][j] = sum % 1000;
        }
    }
    return matrixC;
}