#include <iostream>
using namespace std;

void copyArray(int[], int[], int);
void selectionSort(int[], int);

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
        selectionSort(copiedArray, size);
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

void selectionSort(int arr[], int n)
{
    int cmpCounter = 0;
    int swapCounter = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minVal = arr[i];
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            cmpCounter++;
            if (minVal > arr[j])
            {
                minVal = arr[j];
                minIdx = j;
            }
        }

        if (minIdx != i)
        {
            swap(arr[i], arr[minIdx]);
            swapCounter++;
        }
    }
    printf("%d %d\n", cmpCounter, swapCounter);
}