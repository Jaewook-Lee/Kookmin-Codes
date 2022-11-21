#include <iostream>
#include "my_binary_tree.h"
using namespace std;

Node::Node(const char value, const char prior=3)
{
    data = value;
    priority = prior;
    left = nullptr;
    right = nullptr;
}
BinaryTree::BinaryTree() { root = nullptr; }
void BinaryTree::InsertNode(const char value)
{
    Node* insert = new Node(value, 3);
    if (root == nullptr) { root = insert; }
    else
    {
        int row_size = sizeof(priority_table) / sizeof(priority_table[0]);
        for(int idx=0; idx<row_size; idx++)
        {
            if (value == priority_table[idx][0])
            {
                insert->priority = priority_table[idx][1] - '0';
                break;
            }
        }
        if (insert->priority == 3)
        {
            Node* p = root;
            while (p->right != nullptr) { p = p->right; }
            p->right = insert;
        }
        else if (root->priority >= insert->priority)
        {
            insert->left = root;
            root = insert;
        }
        else
        {
            insert->left = root->right;
            root->right = insert;
        }
        
    }
}
void BinaryTree::Traverse(Node* point, const int order)    // 0: Inorder, 1: Postorder, 2: Preorder
{
    if (order == 0)
    {
        if (point != nullptr)
        {
            Traverse(point->left, order);
            cout << point->data << " ";
            Traverse(point->right, order);

            if (point == root) { cout << endl; }
        }
    }
    else if (order == 1)
    {
        if (point != nullptr)
        {
            Traverse(point->left, order);
            Traverse(point->right, order);
            cout << point->data << " ";

            if (point == root) { cout << endl; }
        }
    }
    else
    {
        if (point != nullptr)
        {
            cout << point->data << " ";
            Traverse(point->left, order);
            Traverse(point->right, order);

            if (point == root) { cout << endl; }
        }
    }
}
double BinaryTree::Evaluate(Node* point)
{
    if (root == nullptr) { return 0; }
    else if ((point->data - '0' >= 0) && (point->data - '0' < 10)) { return (point->data - '0'); }
    else
    {
        double left_val = Evaluate(point->left);
        double right_val = Evaluate(point->right);
        double answer;
        switch (point->data)
        {
            case '+':
                answer = left_val + right_val;
                break;
            case '-':
                answer = left_val - right_val;
                break;
            case '*':
                answer = left_val * right_val;
                break;
            case '/':
                answer = left_val / right_val;
                break;
        }

        return answer;
    }
}