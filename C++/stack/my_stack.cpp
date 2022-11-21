#include <iostream>
#include "my_stack.h"
using namespace std;

MyStack::MyStack()
{
    top = -1;
    max_size = STACK_SIZE;
}
void MyStack::push(int value)
{
    if (top == max_size) { cout << "Stack is FULL" << endl; }
    else { my_stack[++top] = value; }
}
int MyStack::pop()
{
    if (top == -1) { cout << "Stack is EMPTY" << endl; }
    else
    {
        int val = my_stack[top--];
        return val;
    }
}
int MyStack::length() { return (top + 1); }
bool MyStack::empty()
{
    if (top == -1) { return true; }
    else { return false; }
}
void MyStack::print_stack()
{
    for (int i=top; i>-1; i--)
    {
        if (i == 0) { cout << my_stack[i] << endl; } 
        else { cout << my_stack[i] << " "; }
    }
}
int MyStack::operator[](int idx)
{
    if (idx > top)
    {
        cout << "Index is bigger than stack length" << endl;
        return -1;
    }
    else { return my_stack[top - idx]; }
}