#include <iostream>
#include "my_queue.h"
using namespace std;

int main()
{
    MyQueue test_queue;
    if (test_queue.empty()) { cout << "Empty" << endl; }

    for (int i=0; i<50; i++) { test_queue.enqueue(i + 1); }
    test_queue.print_queue();

    int value;
    for (int j=0; j<5; j++) { value = test_queue.dequeue(); }
    cout << value << endl;
    test_queue.print_queue();

    cout << test_queue[5] << endl;

    test_queue.enqueue(51);
    test_queue.print_queue();

    int array[10] = {-10, -20, -30, -40, -50, -60, -70, -80, -90, -100};
    MyQueue another_test_queue(array, 10);
    another_test_queue.print_queue();
    return 0;
}