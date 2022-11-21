#include <iostream>
using namespace std;

int binarySearch(const int*, int, int, int, int);

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int length, target;
        cin >> length >> target;

        int orderedArray[length];
        for (int j = 0; j < length; j++) { cin >> orderedArray[j]; }

        int low = 0;
        int high = length - 1;
        cout << binarySearch(orderedArray, length, target, low, high) << endl;
    }
    return 0;
}

int binarySearch(const int* numArray, int size, int pTarget, int start, int end)
{
    if (start > end) { return -1; }
    else
    {
        int midPoint = (start + end) / 2;
        int midValue = numArray[midPoint];

        if (midValue == pTarget) { return midPoint; }
        else if (midValue < pTarget)
        {
            start = midPoint + 1;
            return binarySearch(numArray, size, pTarget, start, end);
        }
        else
        {
            end = midPoint - 1;
            return binarySearch(numArray, size, pTarget, start, end);
        }
    }
}