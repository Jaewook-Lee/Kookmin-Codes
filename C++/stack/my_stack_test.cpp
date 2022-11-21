#include <iostream>
#include "my_stack.h"
using namespace std;

int main()
{
    MyStack test_stack;
    if (test_stack.empty()) { cout << "Empty!" << endl; }
    else { cout << "Nope!" << endl; }

    for (int i=0; i<5; i++) { test_stack.push(i + 1); }
    test_stack.print_stack();
    cout << test_stack.max_size<< " " << test_stack.length() << endl;

    int number = test_stack.pop();
    cout << number << endl;
    test_stack.print_stack();
    if (test_stack.empty()) { cout << "Empty!" << endl; }
    else { cout << "Nope!" << " " << test_stack.length() << endl; }

    cout << test_stack[3] << endl;

    return 0;
}