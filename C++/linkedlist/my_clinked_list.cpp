#include <iostream>
#include "my_clinked_list.h"
using namespace std;

Node::Node(int value)
{
    data = value;
    link = nullptr;
}
MyCircularLinkedList::MyCircularLinkedList()
{
    head = nullptr;
    tail = nullptr;
    item_cnt = 0;
}
MyCircularLinkedList::~MyCircularLinkedList()
{
    Node* executer = head;
    tail->link = nullptr;
    while (executer != nullptr)
    {
        executer = executer->link;
        delete head;
        head = nullptr;
        head = executer;
    }
}
bool MyCircularLinkedList::Empty()
{
    if (item_cnt == 0) { return true; }
    else { return false; }
}
int MyCircularLinkedList::length() { return item_cnt; }
void MyCircularLinkedList::PrintList()
{
    if (item_cnt == 0) { cout << "EMPTY" << endl; }
    else
    {
        int print_cnt = 0;
        Node* printer = head;
        while (print_cnt < item_cnt)
        {
            if (print_cnt == item_cnt - 1) { cout << printer->data << endl; }
            else { cout << printer->data << " -> "; }
            print_cnt++;
            printer = printer->link;
        }
    }
}
int MyCircularLinkedList::FindAt(int idx)
{
    if (head == nullptr)
    {
        cout << "EMPTY LIST" << endl;
        return -1;
    }
    else if (idx >= item_cnt)
    {
        cout << "Index is over the length" << endl;
        return -1;
    }
    else
    {
        Node* finder = head;
        for (int i=0; i<idx; i++) { finder = finder->link; }
        int result = finder->data;
        return result;
    }
}
void MyCircularLinkedList::InsertNode(int idx, int n)
{
    Node* insert = new Node(n);
    if (idx == 0)
    {
        if (head == nullptr)
        {
            head = insert;
            tail = head;
            head->link = head;
        }
        else
        {
            insert->link = head;
            tail->link = insert;
            head = insert;
        }
    }
    else if (idx >= item_cnt) { cout << "Index is bigger than list length" << endl; }
    else
    {
        Node* finder = head;
        for (int cnt=0; cnt<idx-1; cnt++) { finder = finder->link; }
        insert->link = finder->link;
        finder->link = insert;
    }
    item_cnt++;
}
void MyCircularLinkedList::AppendNode(int n)
{
    Node* insert = new Node(n);
    if (head == nullptr)
    {
        head = insert;
        tail = head;
        head->link = head;
    }
    else
    {
        tail->link = insert;
        insert->link = head;
        tail = insert;
    }
    item_cnt++;
}
void MyCircularLinkedList::DeleteNode(int n)
{
    if (head == nullptr) { cout << "EMPTY LIST" << endl; }
    else
    {
        Node* front = nullptr;
        Node* curr = head;
        int counter = 0;
        while (curr->data != n && counter < item_cnt)
        {
            front = curr;
            curr = curr->link;
            counter++;
        }
        if (counter == item_cnt)
        {
            cout << "NOT FOUND" << endl;
            return;
        }
        else if (curr == head)
        {
            tail->link = head->link;
            head = head->link;
        }
        else if (curr == tail)
        {
            front->link = curr->link;
            tail = front;
        }
        else { front->link = curr->link; }
        delete curr;
        item_cnt--;
    }
}