#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    char data;
    int prior;
    Node *left_link;
    Node *right_link;

    public:
        Node(char token) : prior(4), left_link(0), right_link(0)
        {
            data = token;
        }
};
class LinkedBinTree
{
    private: char priorities[2][4] = {{'*', '/', '+', '-'}, {'2', '2', '1', '1'}};
    public:
        Node *root;
        LinkedBinTree(string exp);
        void DestructLinkedBinTree(Node *a);
        void insertNode(char data);
        void infixTraverse(Node *a);
        void postfixTraverse(Node *a);
        void prefixTraverse(Node *a);
        void drawTree(Node *a, int level=1);
        int eval(Node *a);
};
LinkedBinTree::LinkedBinTree(string expression) : root(0)
{
    for (int i=0; i<expression.length(); i++)
    {
        if (expression[i] == ' ') continue;
        else insertNode(expression[i]);
    }
}
void LinkedBinTree::DestructLinkedBinTree(Node *a)
{
    if (a == 0) return;
    DestructLinkedBinTree(a->left_link);
    DestructLinkedBinTree(a->right_link);
    delete a;
}
void LinkedBinTree::insertNode(char data)
{
    Node *new_node = new Node(data);
    int i;
    for (i=0; i<4; i++)
    {
        if (new_node->data == priorities[0][i])
        {
            new_node->prior = priorities[1][i] - '0';
            break;
        }
    }

    if (i == 4)
    {
        if (root == 0) root = new_node;
        else
        {
            Node *p = root;
            while (p->right_link != 0)
                p = p->right_link;
            p->right_link = new_node;
        }
    }
    else
    {
        if (root->prior >= new_node->prior)
        {
            new_node->left_link = root;
            root = new_node;
        }
        else
        {
            new_node->left_link = root->right_link;
            root->right_link = new_node;
        }
    }
}
void LinkedBinTree::infixTraverse(Node *a)
{
    if (a)
    {
        infixTraverse(a->left_link);
        cout << a->data << " ";
        infixTraverse(a->right_link);
    }

    if (a == root) cout << endl;
}
void LinkedBinTree::postfixTraverse(Node *a)
{
    if (a)
    {
        postfixTraverse(a->left_link);
        postfixTraverse(a->right_link);
        cout << a->data << " ";
    }
    if (a == root) cout << endl;
}
void LinkedBinTree::prefixTraverse(Node *a)
{
    if (a)
    {
        cout << a->data << " ";
        prefixTraverse(a->left_link);
        prefixTraverse(a->right_link);
    }
    if (a == root) cout << endl;
}
void LinkedBinTree::drawTree(Node *a, int level)
{
    if (a == root) cout << "Tree Structure" << endl;
    if (a != 0)
    {
        if (!((a->data - '0') >= 0 && (a->data - '0') <= 9)) cout << "( ";
        drawTree(a->left_link);
        cout << a->data;
        drawTree(a->right_link);
        if (!((a->data - '0') >= 0 && (a->data - '0') <= 9)) cout << " )";
    }

    if (a == root) cout << endl;
}

int main()
{
    const unsigned int BUFFER_SIZE = 80;
    ifstream reader;
    reader.open("Lab7.txt");
    char expression[BUFFER_SIZE];

    while (!reader.eof())
    {
        reader.getline(expression, BUFFER_SIZE);
        if (reader.eof()) break;

        LinkedBinTree tree(expression);

        cout << "InOrder : ";
        tree.infixTraverse(tree.root);
        cout << "PostOrder : ";
        tree.postfixTraverse(tree.root);
        cout << "PreOrder : ";
        tree.prefixTraverse(tree.root);
        tree.drawTree(tree.root);

        tree.DestructLinkedBinTree(tree.root);
    }
}