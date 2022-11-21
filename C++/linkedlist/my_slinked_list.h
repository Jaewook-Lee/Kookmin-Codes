struct Node
{
    public:
        int data;
        Node* next;
        Node(const int);
};

class MySingleLinkedList
{
    private:
        Node* head;
    public:
        MySingleLinkedList();
        ~MySingleLinkedList();
        bool Empty();
        void AppendNode(const int);
        void InsertNode(const int, const int);
        void DeleteNode(const int);
        void PrintList();
        int FindAt(const int);
};