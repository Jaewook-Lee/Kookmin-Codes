struct Node
{
    int value;
    Node *next;

    Node(int);
};

const int STACK_SIZE = 100;
class LinkedStack
{
    public:
        Node *head;
        int max_size;
        int idx;

        LinkedStack();
        ~LinkedStack();
        void push(int);
        int pop();
        bool empty();
        void display_stack();
        int length();
        
        int operator[](int); // Overloading
};