#include <iostream>
#include "my_linked_stack.h"
using namespace std;

int main()
{
    LinkedStack test_stack;
    if (test_stack.empty()) { cout << "EMPTY" << endl; }

    for (int i=0; i<100; i++) { test_stack.push(i + 1); }
    test_stack.display_stack();
    cout << test_stack.max_size << ", " << test_stack.length() << endl;
    test_stack.push(101);

    int popped = test_stack.pop();
    cout << popped << endl;
    test_stack.display_stack();

    return 0;
}