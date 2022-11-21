#include <iostream>
using namespace std;

void mergeSort(int*, int, int, int*);
void printArray(int*, int);

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int size;
        cin >> size;

        int numbers[size];
        for (int j = 0; j < size; j++) { cin >> numbers[j]; }

        int baseOperationCnt = 0;
        mergeSort(numbers, 0, size - 1, &baseOperationCnt);
        cout << baseOperationCnt << endl;
        printArray(numbers, size);
    }
    return 0;
}

void printArray(int* numArray, int n)
{
    for (int i = 0; i < n; i++) { cout << numArray[i] << " "; }
    cout << endl;
}

void mergeSort(int* numArray, int start, int end, int* cnt)
{
    if (end - start != 0)
    {
        int mid = (start + end) / 2;
        mergeSort(numArray, start, mid, cnt);
        mergeSort(numArray, mid + 1, end, cnt);

        int tmp[end - start + 1];
        int tmpPtr = 0; int leftPtr = start; int rightPtr = mid + 1;
        while (leftPtr <= mid && rightPtr <= end)
        {
            (*cnt)++;
            if (numArray[leftPtr] <= numArray[rightPtr]) { tmp[tmpPtr++] = numArray[leftPtr++]; }
            else { tmp[tmpPtr++] = numArray[rightPtr++]; }
        }

        while (leftPtr <= mid) { tmp[tmpPtr++] = numArray[leftPtr++]; }
        while (rightPtr <= end) { tmp[tmpPtr++] = numArray[rightPtr++]; }

        tmpPtr = 0;
        for (int i = start; i <= end; i++) { numArray[i] = tmp[tmpPtr++]; }
    }
}