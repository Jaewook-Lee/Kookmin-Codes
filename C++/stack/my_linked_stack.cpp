#include <iostream>
#include "my_linked_stack.h"
using namespace std;

Node::Node(int n)
{
    value = n;
    next = nullptr;
}

LinkedStack::LinkedStack()
{
    head = nullptr;
    max_size = STACK_SIZE;
    idx = -1;    
}
LinkedStack::~LinkedStack()
{
    while (head != nullptr)
    {
        Node *target = head;
        head = head->next;
        delete target;
    }
}
void LinkedStack::push(int n)
{
    int count = 0;
    Node *p = head;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    if (count == max_size)
    {
        cout << "Full" << endl;
        return;
    }
    else
    {
        Node *temp = new Node(n);
        if (head != nullptr)
        {
            temp->next = head;
        }
        head = temp;
    }
    delete p;
}
int LinkedStack::pop()
{
    if (head == nullptr) { cout << "EMPTY" << endl; }
    else
    {
        int result = head->value;
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return result;
    }
    return 0;
}
bool LinkedStack::empty()
{
    if (head == nullptr) { return true; }
    else { return false; }
}
void LinkedStack::display_stack()
{
    Node *print = head;
    while (print != nullptr)
    {
        if (print->next == nullptr) { cout << print->value << endl; }
        else { cout << print->value << " -> "; }
        print = print->next;
    }
}
int LinkedStack::length()
{
    int count = 0;
    Node *travel = head;
    while (travel != nullptr) 
    {
        travel = travel->next;
        count++;
    }
    return count;
}
int LinkedStack::operator[](int idx)
{
    if (idx >= max_size) { cout << "Index is bigger than stack size" << endl; }
    else
    {
        Node *target = head;
        int count = 0;
        while ((count < idx) && (target != nullptr))
        {
            target = target->next;
            count += 1;
        }
        int n = target->value;
        return n;
    }
    return -1;
}