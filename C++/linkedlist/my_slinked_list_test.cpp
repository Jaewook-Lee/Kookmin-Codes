#include <iostream>
#include "my_slinked_list.h"
using namespace std;

int main()
{
    MySingleLinkedList test_list;
    if (test_list.Empty()) { cout << "Empty" << endl; }

    for (int i=0; i<10; i++) { test_list.AppendNode(i + 1); }
    test_list.PrintList();

    test_list.InsertNode(4, 25);
    test_list.PrintList();

    test_list.DeleteNode(3);
    test_list.PrintList();

    int n = test_list.FindAt(2);
    cout << n << endl;

    return 0;
}