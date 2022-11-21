#include <iostream>
#include "new_static_stack.h"
#include "new_static_queue.h"
#include "new_static_circular_queue.h"
using namespace std;

int main()
{
    StaticStack stack;
    StaticQueue queue;
    StaticCircularQueue c_queue;

    stack.push('a');
    queue.enqueue('b');
    queue.enqueue('c');
    queue.enqueue('d');
    stack.push('e');

    stack.push('F');
    queue.enqueue('G');

    cout << "Stack: ";
    stack.displayStack();
    cout << "Queue: ";
    queue.displayQueue();

    cout << "Output: " << stack.pop() << " ";
    cout << queue.dequeue() << " " << queue.dequeue() << " " << queue.dequeue() << " ";
    cout << stack.pop() << endl;

    stack.pop();
    queue.dequeue();

    c_queue.c_enqueue('A');
    c_queue.c_enqueue('B');
    c_queue.c_enqueue('C');
    c_queue.c_dequeue();
    c_queue.c_enqueue('D');

    c_queue.displayCircularQueue();

    c_queue.c_dequeue();
    c_queue.c_dequeue();
    c_queue.c_dequeue();
}