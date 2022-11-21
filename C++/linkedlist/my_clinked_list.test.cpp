#include <iostream>
#include "my_clinked_list.h"
using namespace std;

int main()
{
    MyCircularLinkedList test_list;
    if (test_list.Empty()) { cout << "This is empty now" << endl; }

    for (int i=0; i<10; i++) { test_list.AppendNode(i); }
    test_list.PrintList();

    test_list.DeleteNode(7);
    test_list.PrintList();
    cout << test_list.length() << endl;

    test_list.InsertNode(3, 15);
    test_list.PrintList();

    test_list.DeleteNode(0);
    test_list.PrintList();
    test_list.DeleteNode(9);
    test_list.PrintList();

    test_list.InsertNode(0, 100);
    test_list.PrintList();

    int value = test_list.FindAt(5);
    cout << value << endl;
    return 0;
}