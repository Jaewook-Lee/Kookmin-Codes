#include <iostream>
using namespace std;

const int SIZE = 10;
int sumMaxValueMatrix(int matrix[][SIZE], int rowSize, int colSize);

int main()
{
    int t;
    unsigned int rowSize, colSize;
    int matrix[SIZE][SIZE];

    cin >> t;

    for (int i=0; i<t; i++)
    {
        cin >> rowSize >> colSize;
        for (int j=0; j<rowSize; j++)
            for (int k=0; k<colSize; k++)
                cin >> matrix[j][k];

        cout << sumMaxValueMatrix(matrix, rowSize, colSize) << endl;
    }
    return 0;
}

int sumMaxValueMatrix(int matrix[][SIZE], int rowSize, int colSize)
{
    int sum = 0;
    for (int i=0; i<rowSize; i++)
    {
        int max_num = matrix[i][0];
        for (int j=0; j<colSize; j++)
        {
            if (max_num < matrix[i][j])
                max_num = matrix[i][j];
        }
        sum += max_num;
    }

    for (int i=0; i<colSize; i++)
    {
        int max_num = matrix[0][i];
        for (int j=0; j<rowSize; j++)
        {
            if (max_num < matrix[j][i])
                max_num = matrix[j][i];
        }
        sum += max_num;
    }

    return sum;
}