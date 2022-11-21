#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    public:
        Node(int n) : value(n), left(0), right(0) {}
};

class BinarySearchTree
{
    public:
        Node *root;
        BinarySearchTree() : root(0) {}
        Node* insertVal (Node*, int);
        Node* deleteVal(Node*, int);
        bool searchVal(Node*, int);
        int leaf(Node*);
        Node* findMax(Node*);
        void infixTraverse(Node *a);
        void postfixTraverse(Node *a);
        void prefixTraverse(Node *a);
        void traverse(Node*);
        void drawTree(Node*, int level=1);
};
Node* BinarySearchTree::insertVal(Node *ptr, int key)
{
    if (ptr == NULL){
        ptr = new Node(key);
        if (root == NULL) root = ptr;
    } 
    else if (key < ptr->value) ptr->left = insertVal(ptr->left, key);
    else if (key > ptr->value) ptr->right = insertVal(ptr->right, key);
    return ptr;
}
Node* BinarySearchTree::deleteVal(Node *a, int key)
{
    if (a == NULL) std::cout << "Key Not Found!\n";
    else
    {
        if (key < a->value)
            a->left = deleteVal(a->left, key);
        else if (key > a->value)
            a->right = deleteVal(a->right, key);
        else if (a->left == NULL && a->right == NULL) a = NULL;
        else if (a->left == NULL)
        {
            Node *temp = a;
            a = a->right;
            delete temp;
        }
        else if (a->right == NULL)
        {
            Node *temp = a;
            a = a->left;
            delete temp;
        }
        else
        {
            Node* max = findMax(a->left);
            a->value = max->value;
            a->left = deleteVal(a->left, a->value);
        }
    }
    return a;
}
bool BinarySearchTree::searchVal(Node *a, int key)
{
    bool checker;
    if (a == NULL) checker = false;
    else
    {
        if (key == a->value) checker = true;
        else if (key < a->value) checker = searchVal(a->left, key);
        else checker = searchVal(a->right, key);
    }

    return checker;
}
int BinarySearchTree::leaf(Node *a)
{
    unsigned int count = 0;
    if (a == NULL) return 0;

    if (a->left == NULL && a->right == NULL) count += 1;
    else count = leaf(a->left) + leaf(a->right);
    
    return count;
}
Node* BinarySearchTree::findMax(Node *a)
{
    if (a->right == NULL) return a;
    else findMax(a->right);
}
void BinarySearchTree::infixTraverse(Node *a)
{
    if (a)
    {
        infixTraverse(a->left);
        cout << a->value << " ";
        infixTraverse(a->right);
    }

    if (a == root) cout << endl;
}
void BinarySearchTree::postfixTraverse(Node *a)
{
    if (a)
    {
        postfixTraverse(a->left);
        postfixTraverse(a->right);
        cout << a->value << " ";
    }
    if (a == root) cout << endl;
}
void BinarySearchTree::prefixTraverse(Node *a)
{
    if (a)
    {
        cout << a->value << " ";
        prefixTraverse(a->left);
        prefixTraverse(a->right);
    }
    if (a == root) cout << endl;
}
void BinarySearchTree::traverse(Node *a)
{
    if (a == 0) cout << "Tree is emtpy.\n";
    else
    {
        cout << "inorder : ";
        infixTraverse(a);
        cout << "postorder : ";
        postfixTraverse(a);
        cout << "preorder : ";
        prefixTraverse(a);
        cout << endl;   
    }
}
void BinarySearchTree::drawTree(Node *a, int level)
{
    if (a != 0)
    {
        drawTree(a->right, level + 1);

        for (int i=0; i<level-1; i++) cout << "    ";
        cout << a->value << " ";

        if (a->left != 0 && a->right != 0) cout << "<" << endl;
        else if (a->right != 0) cout << "/" << endl;
        else if (a->left != 0) cout << "\\" << endl;
        else cout << endl;

        drawTree(a->left, level + 1);
    }
}


int main()
{
    bool exit = false;
    BinarySearchTree bst;
    while(!exit)
    {
        int selector;
        cout << "1. Insert\t2.Delete\t3.Search\t4.Print\t5.Traverse\t6.Leaf\t7.Quit\n";
        cin >> selector;
        
        switch (selector)
        {
            case 1:
                int insert_value;
                cout << "Enter number to insert : ";
                cin >> insert_value;
                bst.insertVal(bst.root, insert_value);
                break;
            case 2:
                int delete_value;
                cout << "Enter number to delete : ";
                cin >> delete_value;
                bst.deleteVal(bst.root, delete_value);
                break;
            case 3:
                {
                    int search_value;
                    cout << "Enter number to search : ";
                    cin >> search_value;
                    bool checker = bst.searchVal(bst.root, search_value);
                    if (checker) cout << "Found!" << endl;
                    else cout << "Not Found" << endl;
                    break;
                }
            case 4:
                bst.drawTree(bst.root);
                break;
            case 5:
                bst.traverse(bst.root);
                break;
            case 6:
                cout << bst.leaf(bst.root) << endl;
                break;
            case 7:
                exit = true;
                break;
        }
    }
}