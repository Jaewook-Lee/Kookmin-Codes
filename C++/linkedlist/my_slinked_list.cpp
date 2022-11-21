#include <iostream>
#include "my_slinked_list.h"
using namespace std;

Node::Node(const int value)
{
    data = value;
    next = nullptr;
}

MySingleLinkedList::MySingleLinkedList() { head = nullptr; }
MySingleLinkedList::~MySingleLinkedList()
{
    Node* next_node = head;
    while (next_node != nullptr)
    {
        next_node = next_node->next;
        delete head;
        head = nullptr;
        head = next_node;
    }
}
bool MySingleLinkedList::Empty()
{
    if (head == nullptr) { return true; }
    else { return false; }
}
void MySingleLinkedList::PrintList()
{
    Node* printer = head;
    while (printer != nullptr)
    {
        if (printer->next == nullptr) { cout << printer->data << endl; }
        else { cout << printer->data << "->"; }
        printer = printer->next;
    }
    delete printer;
}
int MySingleLinkedList::FindAt(const int idx)
{
    if (head == nullptr)
    {
        cout << "EMPTY" << endl;
        return -1;
    }
    else
    {
        int counter = 0;
        Node* target = head;
        while ((counter != idx) && (target != nullptr))
        {
            target = target->next;
            counter++;
        }
        if (target == nullptr)
        {
            cout << "Index is bigger than current length" << endl;
            return -1;
        }
        else
        {
            int answer = target->data;
            return answer;
        }
    }
}
void MySingleLinkedList::DeleteNode(const int value)
{
    if (head == nullptr) { cout << "EMPTY" << endl; }
    else
    {
        Node* front = nullptr;
        Node* current = head;
        while ((current != nullptr) && (current->data != value))
        {
            front = current;
            current = current->next;
        }
        if (current == nullptr) { cout << "NOT FOUND" << endl; }
        else if (current == head)
        {
            front = current;
            current = current->next;
            delete front;
            front = nullptr;
        }
        else
        {
            front->next = current->next;
            delete current;
            current = nullptr;
        }
    }
}
void MySingleLinkedList::InsertNode(const int idx, const int value)
{
    Node* insert = new Node(value);
    if (idx == 0)
    {
        if (head != nullptr) { insert->next = head; }
        head = insert;
    }
    else
    {
        Node* finder = head;
        for (int cnt=0; cnt<idx-1; cnt++) { finder = finder->next; }
        if (finder->next == nullptr) { finder->next = insert; }
        else
        {
            insert->next = finder->next;
            finder->next = insert;
        }
    }
}
void MySingleLinkedList::AppendNode(const int value)
{
    Node* insert = new Node(value);
    if (head == nullptr) { head = insert; }
    else
    {
        Node* traveler = head;
        while (traveler->next != nullptr) { traveler = traveler->next; }
        traveler->next = insert;    
    }
}