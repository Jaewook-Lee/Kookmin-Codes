#include <iostream>
using namespace std;

int traverseLedger(const string*, int, int, int);

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int startNumbers, ledgerRows, destination;
        cin >> startNumbers >> ledgerRows >> destination;
        cin.ignore();    // 'cin' leaves '\n' at buffer. So I use 'cin.ignore' to get '\n'
        string allLedger[ledgerRows];
        for (int j = 0; j < ledgerRows; j++)
        {
            string singleRow;
            getline(cin, singleRow);
            allLedger[j] = singleRow;
        }

        int startLocation = traverseLedger(allLedger, 2 * startNumbers - 1, ledgerRows - 1, 2 * (destination - 1));
        cout << startLocation << endl;
    }
    return 0;
}

int traverseLedger(const string* board, int numCols, int row, int col)
{
    if (row == 0) { return col / 2 + 1; }
    else
    {
        int result;
        if (col + 1 < numCols && board[row][col + 1] == '+') { result = traverseLedger(board, numCols, row - 1, col + 2); }
        else if (col - 1 >= 0 && board[row][col - 1] == '+') { result = traverseLedger(board, numCols, row - 1, col - 2); }
        else { result  = traverseLedger(board, numCols, row - 1, col); }
        return result;
    }
}