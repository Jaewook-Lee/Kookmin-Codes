#include <iostream>
using namespace std;

int partMaximumSum(int*, int, int);

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

        int result = partMaximumSum(numbers, 0, size - 1);
        cout << result << endl;
    }
    return 0;
}

int partMaximumSum(int* numArray, int start, int end)
{
    if (start == end) { return numArray[start] > 0 ? numArray[start] : 0; }
    else
    {
        int mid = (start + end) / 2;
        int leftPartMaxSum = partMaximumSum(numArray, start, mid);
        int rightPartMaxSum = partMaximumSum(numArray, mid + 1, end);

        int midToLeftMaxSum = numArray[mid];
        int midToRightMaxSum = 0;
        int thisSum = numArray[mid];
        for (int i = mid - 1; i >= start; i--)
        {
            thisSum += numArray[i];
            if (thisSum > midToLeftMaxSum) { midToLeftMaxSum = thisSum; }
        }
        thisSum = 0;
        for (int j = mid + 1; j <= end; j++)
        {
            thisSum += numArray[j];
            if (thisSum > midToRightMaxSum) { midToRightMaxSum = thisSum; }
        }
        int throughMidMaxSum = midToLeftMaxSum + midToRightMaxSum;

        int returnValue = leftPartMaxSum > rightPartMaxSum ? leftPartMaxSum : rightPartMaxSum;
        if (throughMidMaxSum > returnValue) { returnValue = throughMidMaxSum; }

        return returnValue;
    }
}