#include <iostream>
using namespace std;

void copyArray(int[], int[], int);
void bubbleSort(int[], int);
void bubbleSortImproved1(int[], int);
void bubbleSortImproved2(int[], int);

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
        bubbleSort(copiedArray, size);

        copyArray(originArray, copiedArray, size);
        bubbleSortImproved1(copiedArray, size);

        copyArray(originArray, copiedArray, size);
        bubbleSortImproved2(copiedArray, size);
        cout << "\n";
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

void bubbleSort(int arr[], int n)
{
    int cmpCounter = 0;
    int swapCounter = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cmpCounter++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCounter++;
            }
        }
    }
    printf("%d %d ", cmpCounter, swapCounter);
}

void bubbleSortImproved1(int arr[], int n)
{
    int cmpCounter = 0;
    int swapCounter = 0;
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            cmpCounter++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCounter++;
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
    printf("%d %d ", cmpCounter, swapCounter);
}

void bubbleSortImproved2(int arr[], int n)
{
    int cmpCounter = 0;
    int swapCounter = 0;

    int last_swapped_idx = n;
    while (last_swapped_idx > 0)
    {
        int swapped_idx = 0;
        for (int i = 0; i < last_swapped_idx - 1; i++)
        {
            cmpCounter++;
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapCounter++;
                swapped_idx = i + 1;
            }
        }
        last_swapped_idx = swapped_idx;
    }
    printf("%d %d ", cmpCounter, swapCounter);
}