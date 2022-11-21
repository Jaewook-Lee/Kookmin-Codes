#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = 0;
    }
};

class SingleLinkedQueue
{
    private:
        Node *front;
        Node *rear;

    public:
        SingleLinkedQueue() {front = 0; rear = 0;}
        ~SingleLinkedQueue();
        void enqueue(int);
        int dequeue();
        bool isEmpty();
        void traverse();
        void search(int);

};

SingleLinkedQueue::~SingleLinkedQueue()
{
    Node *p;

    while (front != 0)
    {
        p = front;
        front = front ->next;
        delete p;
    }
}

void SingleLinkedQueue::enqueue(int value)
{
    Node *temp = new Node(value);

    if (front == 0) front = temp;
    else rear->next = temp;

    rear = temp;   
}

int SingleLinkedQueue::dequeue()
{
    Node *p;
    int num;

    if (front != 0)
    {
        num = front->data;
        p = front;

        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        else front = front->next;
    
        delete p;
        return num;
    }
    else cout << "Queue is empty.\n";
}

bool SingleLinkedQueue::isEmpty()
{
    if (front == 0) return true;
    else return false;
}

void SingleLinkedQueue::traverse()
{
    Node *p;

    if (front != 0)
    {
        p = front;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else cout << "Queue is empty!\n";
}

void SingleLinkedQueue::search(int target)
{
   Node *p;

   if (front != 0)
   {
       p = front;
       while (p != 0 && p->data != target){
           p = p->next;
       }

       if (p) cout << p->data << " is found." << endl;
       else cout << target << " is not in the queue." << endl;
   }
   else cout << "Queue is empty.\n";
}