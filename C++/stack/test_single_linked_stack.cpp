#include <iostream>
#include "single_linked_stack.h"
using namespace std;

int main()
{
    SingleLinkedStack stack;
    stack.traverse();
    stack.pop();

    for (int i=1; i<6; i++)
    {
        stack.push(i);
    }
    stack.traverse();
    stack.search(0);
    stack.search(3);

    for (int i=0; i<3; i++)
    {
        stack.pop();
    }
    stack.traverse();

    stack.~SingleLinkedStack();
    stack.push(19);
    stack.traverse();
}