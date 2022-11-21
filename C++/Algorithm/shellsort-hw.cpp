#include <iostream>
using namespace std;

void copyArray(int[], int[], int);
void shellSort(int[], int);

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int size;
        cin >> size;
        int originArray[size] = {0};
        int copiedArray[size] = {0};
        for (int j = 0; j < size; j++)
        {
            cin >> originArray[j];
        }

        copyArray(originArray, copiedArray, size);
        shellSort(copiedArray, size);
    }
    return 0;
}

void copyArray(int original[], int copied[], int size)
{
    for (int idx = 0; idx < size; idx++)
    {
        copied[idx] = original[idx];
    }
}

void shellSort(int arr[], int n)
{
    int cmpCounter = 0;
    int swapCounter = 0;

    int shrinkRatio = 2;
    int gap = n / shrinkRatio;
    while (gap >= 1)
    {
        for (int i = gap; i < n; i++)
        {
            int value = arr[i];
            int idx = i;
            for (int j = i - gap; j >= 0; j -= gap)
            {
                cmpCounter++;
                if (arr[j] > value)
                {
                    arr[j + gap] = arr[j];
                    idx = j;
                    swapCounter++;
                }
                else
                {
                    break;
                }
            }
            arr[idx] = value;
        }
        gap /= shrinkRatio;
    }

    printf("%d %d\n", cmpCounter, swapCounter);
}