#include <iostream>
using namespace std;

void magicSquare();
int main()
{
    magicSquare();
}

void magicSquare()
{
    int size;
    cout << "Enter size -> ";
    cin >> size;

    int magic_square[size][size] = {{0}};
    int row = 0, col = size / 2;
    magic_square[row][col] = 1;

    int value = 2;
    while (value <= size * size)
    {
        if (value % size == 1)
        {
            row += 1;
            magic_square[row][col] = value++;
            continue;
        }

        if (row - 1 < 0)
            row = size - 1;
        else
            row -= 1;
        if (col - 1 < 0)
            col = size - 1;
        else
            col -= 1;

        magic_square[row][col] = value++;
    }

    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            cout << magic_square[i][j] << " ";
        }
        cout << endl;
    }
}