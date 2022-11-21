struct Node
{
    Node* link;
    int data;
    Node(int);
};
class MyCircularLinkedList
{
    private:
        Node* head;
        Node* tail;
        int item_cnt;
    public:
        MyCircularLinkedList();
        ~MyCircularLinkedList();
        void AppendNode(int);
        void InsertNode(int, int);
        void DeleteNode(int);
        bool Empty();
        int length();
        void PrintList();
        int FindAt(int);
};