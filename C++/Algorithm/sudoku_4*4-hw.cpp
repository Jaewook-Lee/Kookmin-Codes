#include <iostream>
using namespace std;

#define _SUDOKU_SIZE_ 4
int sudokuBoard[_SUDOKU_SIZE_][_SUDOKU_SIZE_];

bool solveSudoku(int, int);
void printAnswer();
bool isPossible(int, int);

int main()
{
    int numCases; cin >> numCases;
    for (int i = 0; i < numCases; i++)
    {
        for (int j = 0; j < _SUDOKU_SIZE_; j++)
        {
            for (int k = 0; k < _SUDOKU_SIZE_; k++)
            { cin >> sudokuBoard[j][k]; }
        }

        solveSudoku(0, 0);
        printAnswer();
    }
    return 0;
}

void printAnswer()
{
    for (int i = 0; i < _SUDOKU_SIZE_; i++)
    {
        for (int j = 0; j < _SUDOKU_SIZE_; j++) { cout << sudokuBoard[i][j] << " "; }
        cout << endl;
    }
}

bool solveSudoku(int row, int col)
{
    if (row == _SUDOKU_SIZE_ - 1 && col == _SUDOKU_SIZE_) { return true; }

    if (col == _SUDOKU_SIZE_) { row++; col = 0; }
    if (sudokuBoard[row][col] > 0) { return solveSudoku(row, col + 1); }
    else
    {
        for (int value = 1; value <= _SUDOKU_SIZE_; value++)
        {
            sudokuBoard[row][col] = value;

            if (isPossible(row, col) && solveSudoku(row, col + 1)) { return true; }
            else { sudokuBoard[row][col] = 0; }
        }
    }
    return false;
}

bool isPossible(int r, int c)
{
    for (int i = 0; i < _SUDOKU_SIZE_; i++)
    {
        if (i == c) { continue; }
        else if (sudokuBoard[r][i] == sudokuBoard[r][c]) { return false; }
    }

    for (int j = 0; j < _SUDOKU_SIZE_; j++)
    {
        if (j == r) { continue; }
        else if (sudokuBoard[j][c] == sudokuBoard[r][c]) { return false; }
    }

    int startRow = r < 2 ? 0 : 2; int startCol = c < 2 ? 0 : 2;
    for (int k = 0; k < 2; k++)
    {
        for (int l = 0; l < 2; l++)
        {
            if (startRow + k == r && startCol + l == c) { continue; }
            else if (sudokuBoard[startRow + k][startCol + l] == sudokuBoard[r][c]) { return false; }
        }
    }

    return true;
}