#include <iostream>
using namespace std;

#define _MAX_LENGTH_ 1000
void clearArray(int*, int);
int lomutoPartition(int*, int, int, int*, int*);
void lomutoQuickSort(int*, int, int, int*, int*);
int hoarePartition(int*, int, int, int*, int*);
void hoareQuickSort(int*, int, int, int*, int*);


int main()
{
    int testCases;
    cin >> testCases;

    int numbers[_MAX_LENGTH_] = {0};
    int copyArray[_MAX_LENGTH_] = {0};
    for (int i = 0; i < testCases; i++)
    {
        int size;
        cin >> size;
        for (int j = 0; j < size; j++) { cin >> numbers[j]; }

        for (int k = 0; k < size; k++) { copyArray[k] = numbers[k]; }
        int lomutoSwapCnt = 0, lomutoCmpCnt = 0;
        lomutoQuickSort(copyArray, 0, size - 1, &lomutoSwapCnt, &lomutoCmpCnt);

        for (int k = 0; k < size; k++) { copyArray[k] = numbers[k]; }
        int hoareSwapCnt = 0, hoareCmpCnt = 0;
        hoareQuickSort(copyArray, 0, size - 1, &hoareSwapCnt, &hoareCmpCnt);

        printf("%d %d %d %d\n", hoareSwapCnt, lomutoSwapCnt, hoareCmpCnt, lomutoCmpCnt);
        clearArray(numbers, size);
        clearArray(copyArray, size);
    }
    return 0;
}

void clearArray(int* numArray, int size)
{
    for (int i = 0; i < size; i++) { *(numArray + i) = 0; }
}

int lomutoPartition(int* numArray, int start, int end, int* sCnt, int* cCnt)
{
    int pivot = *(numArray + start), pivotIdx = start;
    for (int i = start + 1; i <= end; i++)
    {
        (*cCnt)++;
        if (*(numArray + i) < pivot)
        {
            pivotIdx++;

            int tmp = *(numArray + pivotIdx);
            *(numArray + pivotIdx) = *(numArray + i);
            *(numArray + i) = tmp;
            (*sCnt)++;
        }
    }

    int tmp2 = *(numArray + start);
    *(numArray + start) = *(numArray + pivotIdx);
    *(numArray + pivotIdx) = tmp2;
    (*sCnt)++;

    return pivotIdx;
}

int hoarePartition(int* numArray, int start, int end, int* sCnt, int* cCnt)
{
    int pivot = *(numArray + start);
    int low = start - 1, high = end + 1;
    while (low < high)
    {
        while (true)
        {
            low++;
            (*cCnt)++;
            if (*(numArray + low) >= pivot) { break; }
        }
        while (true)
        {
            high--;
            (*cCnt)++;
            if (*(numArray + high) <= pivot) { break; }
        }

        if (low < high)
        {
            int tmp = *(numArray + low);
            *(numArray + low) = *(numArray + high);
            *(numArray + high) = tmp;
            (*sCnt)++;
        }
    }

    return high;
}

void lomutoQuickSort(int* numArray, int start, int end, int* swapCnt, int* cmpCnt)
{
    if (start < end)
    {
        int pivotIdx = lomutoPartition(numArray, start, end, swapCnt, cmpCnt);
        lomutoQuickSort(numArray, start, pivotIdx - 1, swapCnt, cmpCnt);
        lomutoQuickSort(numArray, pivotIdx + 1, end, swapCnt, cmpCnt);
    }
}

void hoareQuickSort(int* numArray, int start, int end, int* swapCnt, int* cmpCnt)
{
    if (start < end)
    {
        int pivotIdx = hoarePartition(numArray, start, end, swapCnt, cmpCnt);
        hoareQuickSort(numArray, start, pivotIdx, swapCnt, cmpCnt);
        hoareQuickSort(numArray, pivotIdx + 1, end, swapCnt, cmpCnt);
    }
}