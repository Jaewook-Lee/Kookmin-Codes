#include <iostream>
#include "my_binary_tree.h"
using namespace std;

int main()
{
    BinaryTree test_tree;
    string expression;
    cin >> expression;
    for (int i=0; i<expression.length(); i++) { test_tree.InsertNode(expression[i]); }

    test_tree.Traverse(test_tree.root);
    test_tree.Traverse(test_tree.root, 1);
    test_tree.Traverse(test_tree.root, 2);

    double result = test_tree.Evaluate(test_tree.root);
    cout << result << endl;
    return 0;
}
