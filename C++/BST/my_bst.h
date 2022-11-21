struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(const int);
};
class MyBST
{
    private:
        Node* root;
    public:
        MyBST();
        ~MyBST();
        bool Empty();
        void Insert(const int);
        Node* Delete(Node*, const int);
        Node PopRoot();
        Node* GetRoot();
        void Traverse(Node*);
        bool Find(const int, Node*);
        int FindMin();
        int FindMax();
};