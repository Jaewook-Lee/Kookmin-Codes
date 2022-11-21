#include <iostream>
#include "my_bst.h"
using namespace std;

int main()
{
    MyBST test_bst;
    if (test_bst.Empty()) { cout << "Empty" << endl; }

    test_bst.Insert(40);
    test_bst.Insert(35);
    test_bst.Insert(56);
    test_bst.Insert(47);
    test_bst.Insert(23);
    test_bst.Insert(89);
    test_bst.Insert(23);

    Node* my_root = test_bst.GetRoot();
    cout << my_root->data << endl;
    test_bst.Traverse(my_root);

    if (test_bst.Find(56, my_root)) { cout << "56 exist" << endl; }
    if (test_bst.Find(100, my_root)) { cout << "100 exist" << endl; }

    test_bst.Delete(my_root, 47);
    test_bst.Delete(my_root, 35);
    test_bst.Delete(my_root, 40);
    test_bst.Traverse(my_root);

    int max_value = test_bst.FindMax();
    int min_value = test_bst.FindMin();
    cout << max_value - min_value << endl;
    return 0;
}