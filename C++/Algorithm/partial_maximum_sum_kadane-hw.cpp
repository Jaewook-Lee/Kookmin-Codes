#include <iostream>
using namespace std;

int partMaximumSum(int*, int, int*, int*);

int main()
{
    int testCases;
    cin >> testCases;
    int size;
    for (int i = 0; i < testCases; i++)
    {
        cin >> size;
        int numbers[size];
        for (int j = 0; j < size; j++) { cin >> numbers[j]; }

        int startIdx = -1; int endIdx = -1;
        int result = partMaximumSum(numbers, size, &startIdx, &endIdx);
        printf("%d %d %d\n", result, startIdx, endIdx);
    }
    return 0;
}

int partMaximumSum(int* numArray, int length, int* sIdx, int* eIdx)
{
    int maxSum = 0; int thisSum = 0;
    for (int i = 0, j = 0; j < length; j++)
    {
        if (numArray[i] == 0)
        {
            i++;
            continue;
        }
        thisSum += numArray[j];
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
            *sIdx = i;
            *eIdx = j;
        }
        else if (thisSum < 0)
        {
            thisSum = 0;
            i = j + 1;
        }
    }
    return maxSum;
}