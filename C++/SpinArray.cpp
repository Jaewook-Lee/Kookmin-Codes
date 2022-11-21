#include <iostream>
using namespace std;

const int SIZE = 10;
void rotateArray(int array[], int size, int rotateSize);
void printArray(int array[] ,int size);

int main(void)
{
    int t;
    unsigned int size, rotateSize;
    int array[SIZE];

    cin >> t;

    for (int i=0; i<t; i++)
    {
        cin >> size >> rotateSize;
        for (int j=0; j<size; j++)
            cin >> array[j];

        rotateArray(array, size, rotateSize);
        printArray(array, size);
    }

    return 0;
}

void rotateArray(int array[], int size, int rotateSize)
{
    if (rotateSize <= 0) return;

    int appending_array[rotateSize];
    int idx = 0;
    for (; idx<rotateSize; idx++) appending_array[idx] = array[idx];
    for (; idx<size; idx++) array[idx - rotateSize] = array[idx];

    for (idx=0; idx<size; idx++) array[size - rotateSize + idx] = appending_array[idx];
}

void printArray(int array[], int size)
{
    for (int i=0; i<size; i++) cout << array[i] << " ";
    cout << endl;
}