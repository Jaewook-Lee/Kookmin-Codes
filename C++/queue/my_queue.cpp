#include <iostream>
#include "my_queue.h"
using namespace std;

MyQueue::MyQueue()
{
    front = -1;
    rear = -1;
    item_cnt = 0;
    max_size = QUEUE_SIZE;
    
    for (int i=0; i<max_size; i++) { my_queue[i] = -1; }
}
MyQueue::MyQueue(int arr[], int size)
{
    front = -1;
    rear = -1;
    item_cnt = size;
    max_size = QUEUE_SIZE;

    for (int i=0; i<max_size; i++)
    {
        if (i < size) { my_queue[i] = arr[i]; }
        else { my_queue[i] = -1; }
    }
    rear = size - 1;
}
void MyQueue::enqueue(int value)
{
    if (item_cnt == max_size) { cout << "FULL" << endl; }
    else
    {
        rear = (rear + 1) % max_size;
        my_queue[rear] = value;
        item_cnt++;
    }
}
int MyQueue::dequeue()
{
    if (item_cnt == 0)
    {
        cout << "EMPTY" << endl;
        return -1;
    }
    else
    {
        item_cnt--;
        front = (front + 1) % max_size;
        return my_queue[front];
    }
}
bool MyQueue::empty()
{
    if (item_cnt == 0) { return true; }
    else { return false; }
}
bool MyQueue::full()
{
    if (item_cnt == max_size) { return true; }
    else { return false; }
}
int MyQueue::length() { return item_cnt; }
void MyQueue::print_queue()
{
    int idx = front + 1;
    for (int print_cnt=0; print_cnt<item_cnt; print_cnt++)
    {
        if (idx == rear) { cout << my_queue[idx] << endl; }
        else { cout << my_queue[idx] << " "; }
        idx = (idx + 1) % max_size;
    }
}
int MyQueue::operator[](const int idx)
{
    if (idx >= item_cnt)
    {
        cout << "Index is bigger than queue size" << endl;
        return -1;
    }
    else { return my_queue[(front + 1 + idx) % max_size]; }
}