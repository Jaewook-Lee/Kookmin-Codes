struct Node
{
    char data;
    int priority;
    Node* left;
    Node* right;

    Node(const char, const char);
};
class BinaryTree
{
    private:
        const char priority_table[4][2] = {{'+', '1'}, {'-', '1'}, {'*', '2'}, {'/', '2'}};
    public:
        Node* root;
        BinaryTree();
        void InsertNode(const char);
        void Traverse(Node*, const int order=0);
        double Evaluate(Node*);
};