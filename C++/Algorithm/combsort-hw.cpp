#include <iostream>
using namespace std;

void copyArray(int[], int[], int);
void combSort(int[], int);
void bubbleSort(int[], int, int*, int*);

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
        combSort(copiedArray, size);
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

void combSort(int arr[], int n)
{
    int cmpCounter = 0;
    int swapCounter = 0;

    int gap = n / 1.3;
    bool sorted = false;
    while (!sorted)
    {
        if (gap <= 1)
        {
            gap = 1;
            sorted = true;
        }

        for (int i = 0; i + gap < n; i++)
        {
            cmpCounter++;
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapCounter++;
                sorted = false;
            }
        }

        gap /= 1.3;
    }
    printf("%d %d\n", cmpCounter, swapCounter);
}