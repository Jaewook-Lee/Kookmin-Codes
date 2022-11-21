#include <iostream>
#include "my_heap.h"
using namespace std;

MyHeap::MyHeap(): item_cnt(0){}
bool MyHeap::Empty()
{
    if (item_cnt == 0) { return true; }
    else { return false; }
}
int MyHeap::Length() { return item_cnt; }
void MyHeap::Print()
{
    for (int i=1; i<=item_cnt; i++)
    {
        if (i == item_cnt) { cout << heap[i] << endl; }
        else { cout << heap[i] << " "; }
    }
}
void MyHeap::Insert(int number)
{
    heap[++item_cnt] = number;
    int idx = item_cnt;
    while (idx != 1 && heap[idx] > heap[int(idx / 2)])
    {
        heap[idx] = heap[int(idx / 2)];
        idx = int(idx / 2);
        heap[idx] = number;
    }
    heap[idx] = number;
}
int MyHeap::Delete()
{
    if (item_cnt == 0) { return -1; }

    int max_value = heap[1];
    int last_value = heap[item_cnt];
    heap[1] = last_value;
    heap[item_cnt] = 0;
    item_cnt--;

    int parent_idx = 1;
    int child_idx = 2;

    while (child_idx <= item_cnt)
    {
        if (heap[child_idx] < heap[child_idx + 1]) { child_idx++; }
        
        if (heap[child_idx] < last_value) { break; }
        heap[parent_idx] = heap[child_idx];
        parent_idx = child_idx;
        child_idx *= 2;
    }
    if (item_cnt != 1) { heap[parent_idx] = last_value; }

    return max_value;
}