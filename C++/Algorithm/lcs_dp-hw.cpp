#include <iostream>
using namespace std;

#define _LENGTH_ 100
char inputStr1[_LENGTH_ + 1], inputStr2[_LENGTH_ + 1];
int lcsLengthTable[_LENGTH_ + 1][_LENGTH_ + 1] = {0,};
int readingDirections[_LENGTH_ + 1][_LENGTH_ + 1] = {0, };

void clearString(char*, int);
void clearTable(int(*)[_LENGTH_ + 1], int, int);
void printLCS(int, int);
int getLength(char*);
int findLcsLength(int, int);

int main()
{
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        cin >> inputStr1; cin >> inputStr2;

        int str1Len = getLength(inputStr1);
        int str2Len = getLength(inputStr2);
        clearTable(lcsLengthTable, str1Len, str2Len);
        clearTable(readingDirections, str1Len, str2Len);

        for (int j = 0; j <= str1Len; j++) { for (int k = 0; k <= str2Len; k++) { if (j == 0 || k == 0) { lcsLengthTable[j][k] = 0; } } }

        int lcsLength = findLcsLength(str1Len, str2Len);
        cout << lcsLength << " ";

        printLCS(str1Len, str2Len); cout << endl;

        clearString(inputStr1, str1Len); clearString(inputStr2, str2Len);
    }
    return 0;
}

void clearString(char* str, int len) { for (int i = 0; i < len; i++) { *(str + i) = '\0'; } }
void clearTable(int(*table)[_LENGTH_ + 1], int row, int col) { for (int i = 0; i <= row; i++) { for (int j = 0; j <= col; j++) { table[i][j] = -1; } } }

int getLength(char* usrString)
{
    int idx = 0;
    while (*(usrString + idx) != '\0') { idx++; }
    return idx;
}

int findLcsLength(int str1End, int str2End)
{
    for (int i = 1; i <= str1End; i++)
    {
        for (int j = 1; j <= str2End; j++)
        {
            if (inputStr1[i - 1] == inputStr2[j - 1])
            {
                lcsLengthTable[i][j] = lcsLengthTable[i - 1][j - 1] + 1;
                readingDirections[i][j] = 0;    // Came from left-up side
            }
            else
            {
                int candidate1 = lcsLengthTable[i - 1][j];
                int candidate2 = lcsLengthTable[i][j - 1];

                if (candidate1 > candidate2)
                {
                    lcsLengthTable[i][j] = candidate1;
                    readingDirections[i][j] = 1;    // Came from upside
                }
                else
                {
                    lcsLengthTable[i][j] = candidate2;
                    readingDirections[i][j] = 2;    // Came from left side
                }
            }
        }
    }

    return lcsLengthTable[str1End][str2End];
}

void printLCS(int row, int col)
{
    if (readingDirections[row][col] == -1) {}
    else if (readingDirections[row][col] == 0)
    {
        printLCS(row - 1, col - 1);
        cout << inputStr1[row - 1];
    }
    else if (readingDirections[row][col] == 1) { printLCS(row - 1, col); }
    else { printLCS(row, col - 1); }
}