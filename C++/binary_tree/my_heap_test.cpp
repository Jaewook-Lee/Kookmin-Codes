#include <iostream>
#include "my_heap.h"
using namespace std;

int main()
{
    MyHeap max_heap;
    for (int i=0; i<7; i++) { max_heap.Insert(i + 1); }
    max_heap.Print();

    int item = max_heap.Delete();
    max_heap.Print();
    cout << item << endl;
    return 0;
}
