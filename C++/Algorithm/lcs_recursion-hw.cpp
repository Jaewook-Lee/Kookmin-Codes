#include <iostream>
using namespace std;

#define _LENGTH_ 10
char inputStr1[_LENGTH_ + 1], inputStr2[_LENGTH_ + 1];

void clearString(char*, int);
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
        int lcsLength = findLcsLength(str1Len - 1, str2Len - 1);
        cout << lcsLength << endl;

        clearString(inputStr1, str1Len); clearString(inputStr2, str2Len);
    }
    return 0;
}

void clearString(char* str, int len) { for (int i = 0; i < len; i++) { *(str + i) = '\0'; } }

int getLength(char* usrString)
{
    int idx = 0;
    while (*(usrString + idx) != '\0') { idx++; }
    return idx;
}

int findLcsLength(int str1End, int str2End)
{
    if (str1End == -1 || str2End == -1) { return 0; }
    else if (inputStr1[str1End] == inputStr2[str2End])
    {
        int result = findLcsLength(str1End - 1, str2End - 1);
        return result + 1;
    }
    else
    {
        int candidate1 = findLcsLength(str1End - 1, str2End);
        int candidate2 = findLcsLength(str1End, str2End - 1);
        return candidate1 > candidate2 ? candidate1 : candidate2;
    }
}