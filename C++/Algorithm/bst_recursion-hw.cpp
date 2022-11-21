#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

void insert(node**, int);
void preOrder(node*);
void inOrder(node*);
void postOrder(node*);
int size(node*);
int height(node*);
int sumOfWeight(node*);
int maxPathWeight(node*);
void mirror(node**);
void destruct(node**);

int main()
{
    int testCases;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        node* bst = NULL;
        int numNode;
        cin >> numNode;
        for (int j = 0; j < numNode; j++)
        {
            int data;
            cin >> data;
            insert(&bst, data);
        }
        cout << size(bst) << endl;
        cout << height(bst) << endl;
        cout << sumOfWeight(bst) << endl;
        cout << maxPathWeight(bst) << endl;
        mirror(&bst);
        preOrder(bst); printf("\n");
        inOrder(bst); printf("\n");
        postOrder(bst); printf("\n");
        destruct(&bst);

        if (bst == NULL) { cout << 0 << endl; }
        else { cout << 1 << endl; }

    }
    return 0;
}

void insert(node** root, int value)
{
    if (*root == NULL)
    {
        node* newNode = new node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        *root = newNode;
    }
    else
    {
        if (value < (*root)->data) { insert(&((*root)->left), value); }
        else { insert(&((*root)->right), value); }
    }
}

void destruct(node** root)
{
    if (*root != NULL)
    {
        destruct(&((*root)->left));
        destruct(&((*root)->right));
        delete *root;
        *root = NULL;
    }
}

int size(node* root)
{
    if (root == NULL) { return 0; }
    else
    {
        int leftSize = size(root->left);
        int rightSize = size(root->right);
        return leftSize + rightSize + 1;
    }
}

int height(node* root)
{
    if (root == NULL) { return -1; }
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
}

int sumOfWeight(node* root)
{
    if (root == NULL) { return 0; }
    else
    {
        int leftWeight = sumOfWeight(root->left);
        int rightWeight = sumOfWeight(root->right);
        return leftWeight + rightWeight + root->data;
    }
}

int maxPathWeight(node* root)
{
    if (root == NULL) { return 0; }
    else
    {
        int leftMax = maxPathWeight(root->left);
        int rightMax = maxPathWeight(root->right);
        int currData = root->data;
        return leftMax > rightMax ? leftMax + currData : rightMax + currData;
    }
}

void mirror(node** root)
{
    if ((*root) != NULL)
    {
        mirror(&(*root)->left);
        mirror(&(*root)->right);

        node* tmp = (*root)->left;
        (*root)->left = (*root)->right;
        (*root)->right = &(*tmp);
    }
}

void preOrder(node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(node* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}