#include <iostream>
using namespace std;

#define _SIZE_ 1000
int numbers[_SIZE_ + 1];

void clearArray(int*, int);
void fixHeap(int, int, int, int*);
void heapSort(int*, int, int*);

int main()
{
    int numCases; cin >> numCases;
    for (int i = 0; i < numCases; i++)
    {
        int numItem; cin >> numItem;
        clearArray(numbers, numItem);

        for (int j = 1; j <= numItem; j++) { cin >> numbers[j]; }
        int compareCnt = 0;
        heapSort(numbers, numItem, &compareCnt);

        cout << compareCnt << endl;
    }
    return 0;
}

void clearArray(int* arr, int size)
{ for (int i = 1; i <= size; i++) { *(arr + i) = 0; } }

void heapSort(int* arr, int size, int* counter)
{
    // Construct MaxHeap
    for (int idx = size / 2; idx >= 1; idx--) { fixHeap(idx, numbers[idx], size, counter); }

    for (int i = size; i > 1; i--)
    {
        int maxKey = numbers[1];
        fixHeap(1, numbers[i], i - 1, counter);
        numbers[i] = maxKey;
    }
}

void fixHeap(int index, int key, int length, int* cnt)
{
    int largerChild, largerIdx;
    while (index * 2 + 1 <= length || index * 2 <= length)
    {
        if (index * 2 + 1 > length)
        {
            largerChild = numbers[index * 2];
            largerIdx = index * 2;
        }
        else
        {
            (*cnt)++;
            if (numbers[index * 2] > numbers[index * 2 + 1])
            {
                largerChild = numbers[index * 2];
                largerIdx = index * 2;
            }
            else
            {
                largerChild = numbers[index * 2 + 1];
                largerIdx = index * 2 + 1;
            }
        }

        (*cnt)++;
        if (key < largerChild)
        {
            numbers[index] = numbers[largerIdx];
            index = largerIdx;
        }
        else { break; }
    }
    numbers[index] = key;
}