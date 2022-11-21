#include <iostream>
using namespace std;

#define _MAX_SIZE_ 100
int numbers[_MAX_SIZE_] = {0};

void mergeSortIter(int*, int, int, int*);
void merge(int*, int, int, int, int*);
void clearArray(int*, int);

int main()
{
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        int size;
        cin >> size;
        for (int j = 0; j < size; j++) { cin >> numbers[j]; }

        int counter = 0;
        mergeSortIter(numbers, 0, size - 1, &counter);
        cout << counter << endl;
    }
    return 0;
}

void clearArray(int* numArray, int n)
{
    for (int i = 0; i < n; i++) { *(numArray + i) = 0; }
}

void mergeSortIter(int* numArray, int start, int end, int* cnt)
{
    int arraySize = end - start + 1;
    int incrementSize = 1;
    while (incrementSize < arraySize)
    {
        for (int i = 0; i < arraySize; i += 2 * incrementSize)
        {
            int low = i;
            int mid = low + incrementSize - 1 > end ? end : low + incrementSize - 1;
            int high = low + (2 * incrementSize - 1) > end ? end : i + (2 * incrementSize - 1);

            merge(numArray, low, mid, high, cnt);
        }

        incrementSize *= 2;
    }
}

void merge(int* numArray, int s, int m, int e, int* c)
{
    int tmp[_MAX_SIZE_] = {0};
    for (int i = s; i <= e; i++) { tmp[i] = *(numArray + i); }

    int leftPtr = s; int rightPtr = m + 1; int numArrayPtr = s;
    while (leftPtr <= m && rightPtr <= e)
    {
        (*c)++;
        if (tmp[leftPtr] <= tmp[rightPtr]) { numArray[numArrayPtr++] = tmp[leftPtr++]; }
        else { numArray[numArrayPtr++] = tmp[rightPtr++]; }
    }

    while (leftPtr <= m) { numArray[numArrayPtr++] = tmp[leftPtr++]; }
    while (rightPtr <= e) { numArray[numArrayPtr++] = tmp[rightPtr++]; }
}