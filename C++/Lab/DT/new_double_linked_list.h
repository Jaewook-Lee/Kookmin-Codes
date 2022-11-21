#include <iostream>
#include <string>
using namespace std;

struct Node
{
    public:
        string name;
        int weight;
        int height;
        Node *prev;
        Node *next;

        Node(string s_name, int s_weight, int s_height)
        {
            name = s_name;
            weight = s_weight;
            height = s_height;
            prev = 0;
            next = 0;
        }
};

class DoubleLinkedList
{
    private:
        Node *head;
    public:
        DoubleLinkedList() {head = 0;}
        ~DoubleLinkedList();
        int isEmpty();
        void insertNode(string, int, int);
        void insertNth(int, string, int, int);
        void deleteNode(string);
        void search(string);
        int searchNth(int);
        void showForward();
        void showBackward();
};
DoubleLinkedList::~DoubleLinkedList()
{
    Node *p;
    while (head != 0)
    {
        p = head;
        head = head->next;
        delete p;
    }
    
}
int DoubleLinkedList::isEmpty()
{
    if (head == 0)
        return 1;
    else
        return 0;
}
void DoubleLinkedList::insertNode(string name, int weight, int height)
{
    Node *temp = new Node(name, weight, height);

    if (head == 0)
        head = temp;
    else if (temp->name < head->name)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        Node *p = head;
        Node *q = head;

        while (p != 0 && p->name < temp->name)
        {
            q = p;
            p = p->next;
        }
        if (p != 0)
        {
            temp->next = p;
            temp->prev = q;
            q->next = temp;
            p->prev = temp;
        }
        else
        {
            q->next = temp;
            temp->prev = q;
        }
    }
}
void DoubleLinkedList::insertNth(int position, string name, int weight, int height)
{
    Node *temp = new Node(name, weight, height);

    if (head == 0)
        std::cout << "List is empty.\n";
    else if (temp->name < head->name)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        Node *p = head;
        Node *q = head;
        int idx = 1;

        while (p != 0 && idx <= position)
        {
            q = p;
            p = p->next;
            idx++;
        }
        if (p != 0)
        {
            p->prev = temp;
            q->next = temp;
            temp->prev = q;
            temp->next = p;
        }
        else
        {
            q->next = temp;
            temp->prev = q;
        }
        
    }
}
void DoubleLinkedList::deleteNode(string name)
{
    Node *p, *q;

    if (head == 0)
        cout << "List Empty\n";
    else
    {
        if (head->name == name)
        {
            if (head->next != 0)
            {
                p = head;
                head = head->next;
                head->prev = 0;
                delete p;
            }
            else
                head = 0;
        }
        else
        {
            p = head;
            q = head;

            while (p != 0 && p->name != name)
            {
                q = p;
                p = p->next;
            }
            if (p == 0)
                cout << name << " is not in the list\n";
            else if (p->next != 0 && p->name == name)
            {
                q->next = p->next;
                p->next->prev = q;
                delete p;
            }
            else if (p->next == 0 && p->name == name)
            {
                q->next = 0;
                delete p;
            }
        }
    }
}
void DoubleLinkedList::search(string target)
{
    Node *p;

    if (head == 0)
        cout << "List empty\n";
    else
    {
        p = head;
        while (p != 0 && p->name != target)
        {
            p = p->next;
        }
        if (p != 0)
            cout << "Found\n" << "\n";
        else
            cout << "Not Found\n" << "\n";
    }   
}
int DoubleLinkedList::searchNth(int position)
{
    Node *p;

    if (head == 0)
        cout << "List Empty!\n";
    else
    {
        p = head;
        int idx = 1;
        while (idx != position)
        {
            if (p == 0)
                break;
            
            p = p->next;
            idx++;
        }
        if (p == 0)
            cout << "No such a line\n";
        else
        {
            cout << p->name << "\t" << p->weight << "\t" << p->height << endl;
            cout << "\n";
        }
    }
    
}
void DoubleLinkedList::showForward()
{
    Node *p;

    if (head == 0)
        cout << "list Empty\n";
    else
    {
        p = head;
        while (p != 0)
        {
            cout << p->name << "\t" << p->weight << "\t" << p->height << " ";
            p = p->next;
            cout << "\n";
        }
        cout << endl;
    }
}
void DoubleLinkedList::showBackward()
{
    Node *p;

    if (head == 0)
        cout << "list empty\n";
    else
    {
        p = head;

        while (p->next != 0)
        {
            p = p->next;
        }
        while (p != 0)
        {
            cout << p->name << "\t" << p->weight << "\t" << p->height << "\n";
            p = p->prev;
        }
        cout << endl;
    }
}