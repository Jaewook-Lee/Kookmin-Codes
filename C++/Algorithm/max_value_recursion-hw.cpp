#include <iostream>
using namespace std;

int maxValue(const int*, int);

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int length;
        cin >> length;

        int numbers[length];
        for (int j = 0; j < length; j++) { cin >> numbers[j]; }
        cout << maxValue(numbers, length) << endl;
    }
    return 0;
}

int maxValue(const int* numArray, int size)
{
    if (size == 1) { return numArray[size - 1]; }
    else
    {
        int maxNumber = maxValue(numArray, size - 1);
        if (numArray[size - 1] > maxNumber) { maxNumber = numArray[size - 1]; }
        return maxNumber;
    }
}