#include <iostream>
#include "my_bst.h"
using namespace std;

Node::Node(const int value): data(value), left(nullptr), right(nullptr){}
MyBST::MyBST(): root(nullptr){}
bool MyBST::Empty()
{
    if (root == nullptr) { return true; }
    else { return false; }
}
MyBST::~MyBST() {}
Node* MyBST::GetRoot() { return root; }
void MyBST::Insert(const int value)
{
    Node* insert = new Node(value);
    if (root == nullptr) { root = insert; }
    else
    {
        Node* ptr = root;
        while (true)
        {
            if (ptr->data == value)
            {
                cout << "Already Exist" << endl;
                break;
            }
            else if (ptr->data < value)
            {
                if (ptr->right == nullptr)
                {
                    ptr->right = insert;
                    break;
                }
                else { ptr = ptr->right; }
            }
            else
            {
                if (ptr->left == nullptr)
                {
                    ptr->left = insert;
                    break;    
                }
                else { ptr = ptr->left; }
            }
        }
    }
}
Node* MyBST::Delete(Node* point, const int value)
{
    if(root == nullptr) { return nullptr; }
    else
    {
        if (point->data > value) { point->left = Delete(point->left, value); }
        else if (point->data < value) { point->right = Delete(point->right, value); }
        else
        {
            if (point->left == nullptr and point->right == nullptr)
            {
                delete point;
                point = nullptr;
            }
            else if (!(point->left == nullptr || point->right == nullptr))
            {
                Node* max_of_min = point->left;
                while (max_of_min->right != nullptr) { max_of_min = max_of_min->right; }
                point->data = max_of_min->data;
                point->left = Delete(point->left, point->data);
            }
            else
            {
                Node* temp = point;
                if (point->left != nullptr) { point = point->left; }
                else { point = point->right; }
                delete temp;
                temp = nullptr;
            }
        }
        return point;
    }
}
Node MyBST::PopRoot()
{
    Node ret = *root;

    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        root = nullptr;
    }
    else if (root->right != nullptr)
    {
        Node* min_of_max = root->right;
        while (min_of_max->left != nullptr) { min_of_max = min_of_max->left; }
        root->data = min_of_max->data;
        delete min_of_max;
        min_of_max = nullptr;
    }
    else if (root->left != nullptr)
    {
        Node* max_of_min = root->left;
        while (max_of_min->right != nullptr) { max_of_min = max_of_min->right; }
        root->data = max_of_min->data;
        delete max_of_min;
        max_of_min = nullptr;
    }
    
    return ret;
}
void MyBST::Traverse(Node* printer)
{
    if (printer != nullptr)
    {
        Traverse(printer->left);
        cout << printer->data << " ";
        Traverse(printer->right);

        if (printer == root) { cout << endl; }
    }
}
bool MyBST::Find(const int value, Node* start_point=nullptr)
{
    if (start_point == nullptr) { start_point = root; }
    bool is_found = false;

    if (start_point->data == value)
    {
        is_found = true;
        return is_found;
    }
    else if (start_point->left == nullptr && start_point->right == nullptr) { return is_found; }
    else if (start_point->data < value && start_point->right != nullptr) { return Find(value, start_point->right); }
    else if (start_point->data > value && start_point->left != nullptr) { return Find(value, start_point->left); }
    else { return is_found; }
}
int MyBST::FindMin()
{
    Node* finder = root;
    while (finder->left != nullptr) { finder = finder->left; }
    return finder->data;
}
int MyBST::FindMax()
{
    Node* finder = root;
    while (finder->right != nullptr) { finder = finder->right; }
    return finder->data;
}