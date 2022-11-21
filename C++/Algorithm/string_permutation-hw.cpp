#include <iostream>
using namespace std;

#define _MAX_STRING_LENGTH_ 9    // Max length of input is 9

int getLength(const char*);    // Getting length of string
int pow(int, int);    // Calculating power
void countPosWeight(char*, int, int, int*);    // Main algorithm

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        char input[_MAX_STRING_LENGTH_ + 1];
        cin >> input;
        int strLen = getLength(input);
        int counter = 0;    // Counting positive weight for each permutation
        countPosWeight(input, 0, strLen, &counter);    // Sending counter via argument.
        cout << counter << endl;
    }
    return 0;
}

int getLength(const char* str)
{
    int idx = 0;
    while (*(str + idx++)) {}
    return idx - 1;
}

int pow(int value, int cnt)
{
    int result = value;
    if (cnt == 0) { return 1; }
    for (int i = 2; i <= cnt; i++) { result *= value; }
    return result;
}

void countPosWeight(char* str, int start, int end, int* cnt)
{
    if (end - start == 1)    // Start Calculating weight
    {
        int sum = 0;
        for (int j = 0; j < end; j++) { sum += (pow(-1, j) * ((str[j] - '0') - ('a' - '0'))); }
        if (sum > 0) { (*cnt)++; }
    }
    else
    {
        for (int i = 0; i < end - start; i++)
        {
            /* Swapping char */
            char tmp = str[start];
            str[start] = str[start + i];
            str[start + i] = tmp;

            countPosWeight(str, start + 1, end, cnt);    // Go deeper

            /* Recovering char */
            tmp = str[start];
            str[start] = str[start + i];
            str[start + i] = tmp;
        }
    }
}