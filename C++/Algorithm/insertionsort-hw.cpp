#include <iostream>
using namespace std;

void copyArray(int[], int[], int);
void insertionSort(int[], int);

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
        insertionSort(copiedArray, size);
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

void insertionSort(int arr[], int n)
{
    int cmpCounter = 0;
    int swapCounter = 0;

    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int idx = i;
        for (int j = i - 1; j >= 0; j--)
        {
            cmpCounter++;
            if (arr[j] > value)
            {
                arr[j + 1] = arr[j];
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
    printf("%d %d\n", cmpCounter, swapCounter);
}