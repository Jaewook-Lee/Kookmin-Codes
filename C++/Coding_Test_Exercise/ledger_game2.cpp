#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define _MAX_STARTS_ 100
#define _MAX_HEIGHT_ 200
string ledgerBoard[_MAX_HEIGHT_];

void clearBoard(string*, int);
int traverseBoard(int, int, int, int);

int main()
{
    int testCases;
    cin >> testCases;

    int startNumbers, ledgerHeight, destination;
    for (int i = 0; i < testCases; i++)
    {
        cin >> startNumbers >> ledgerHeight >> destination;
        cin.ignore();
        string ledgerRow;
        for (int j = 0; j < ledgerHeight; j++)
        {
            getline(cin, ledgerRow);
            ledgerBoard[j] = ledgerRow;
        }
        int startPoints = traverseBoard(ledgerHeight - 1, 2 * (destination - 1), ledgerHeight - 1, 2 * startNumbers - 1);
        
        clearBoard(ledgerBoard, ledgerHeight);
    }
    return 0;
}

void clearBoard(string* board, int height)
{
    for (int i = 0; i < height; i++) { board[i] = ""; }
}

int traverseBoard(int startRow, int startCol, int rowSize, int colSize)
{
    int currRow = startRow; int currCol = startCol;
    int results[3] = {_MAX_STARTS_+ 1, _MAX_STARTS_+ 1, _MAX_STARTS_+ 1};

    while (ledgerBoard[currRow][currCol] != '?' && currRow > 0)
    {
        if (currCol - 1 >= 0 && ledgerBoard[currRow][currCol - 1] != '0') { currCol -= 2; }
        else if (currCol + 1 < colSize && ledgerBoard[currRow][currCol + 1] != '0') { currCol += 2; }
        currRow -= 1;
    }

    if (currRow == 0) { return currCol / 2 + 1; }

    if (currCol - 1 >= 0) { results[0] = traverseBoard(currRow - 1, currCol - 2, rowSize, colSize); }
    if (currCol + 1 < colSize) { results[1] = traverseBoard(currRow - 1, currCol + 2, rowSize, colSize); }
    results[2] = traverseBoard(currRow - 1, currCol, rowSize, colSize);
    sort(results, results + 3);

    for (int i = 0; i < 3; i++)
    {
        if (results[i] == _MAX_STARTS_ + 1) { break; }
        else { cout << results[i] << " "; }
    }
    cout << endl;

    return results[0];
}