#include <iostream>
using namespace std;

#define _BOARD_SIZE_ 16
int queensCol[_BOARD_SIZE_ + 1];

bool solveNQueen(int, int);
bool isPossible(int, int);

int main()
{
    int numCases; cin >> numCases;
    for (int i = 0; i < numCases; i++)
    {
        int boardSize; cin >> boardSize;
        for (int k = 1; k <= boardSize; k++)
        {
            queensCol[1] = k;
            if (solveNQueen(1, boardSize)) { break; };
        }
    }
    return 0;
}

bool isPossible(int r, int pSize)
{
    int idx = 1;
    bool possible = true;
    while (idx < r && possible)
    {
        if (queensCol[r] == queensCol[idx] || (abs(queensCol[r] - queensCol[idx])) == r - idx)
        {
            possible = false;
            break;
        }
        else { idx++; }
    }
    return possible;
}

bool solveNQueen(int row, int size)
{
    if (isPossible(row, size))
    {
        if (row != size)
        {
            bool result = false;
            for (int i = 1; i <= size; i++)
            {
                queensCol[row + 1] = i;
                result = solveNQueen(row + 1, size);
                if (result)
                { return true; };
            }
            return false;
        }
        else
        {
            for (int j = 1; j <= size; j++) { cout << queensCol[j] << " "; }
            cout << endl;
            return true;
        }
    }
    else { return false; }
}