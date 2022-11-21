#include <iostream>
using namespace std;

#define _LENGTH_ 100
char inputStr1[_LENGTH_ + 1], inputStr2[_LENGTH_ + 1];
int lcsLengthTable[_LENGTH_ + 1][_LENGTH_ + 1] = {0,};

void clearString(char*, int);
void clearTable(int(*)[_LENGTH_ + 1], int, int);
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

        for (int j = 0; j <= str1Len; j++) { for (int k = 0; k <= str2Len; k++) { if (j == 0 || k == 0) { lcsLengthTable[j][k] = 0; } } }

        int lcsLength = findLcsLength(str1Len, str2Len);
        cout << lcsLength << endl;

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
    if (lcsLengthTable[str1End][str2End] != -1) { return lcsLengthTable[str1End][str2End]; }
    else if (inputStr1[str1End - 1] == inputStr2[str2End - 1])
    {
        int result = findLcsLength(str1End - 1, str2End - 1);
        lcsLengthTable[str1End][str2End] = result + 1;
        return lcsLengthTable[str1End][str2End];
    }
    else
    {
        int candidate1 = findLcsLength(str1End - 1, str2End);
        int candidate2 = findLcsLength(str1End, str2End - 1);
        int maxVal = candidate1 > candidate2 ? candidate1 : candidate2;

        lcsLengthTable[str1End][str2End] = maxVal;
        return lcsLengthTable[str1End][str2End];
    }
}