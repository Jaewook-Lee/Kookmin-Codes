#include <iostream>
using namespace std;

struct Node
{
    int key = -1;
    int data;
    Node* link = 0;
    public:
        Node();
        Node(int data) { this->data = data; }
        Node(int key, int data)
        {
            this->data = data;
            this->key = key;
        }
};

class SingleLinkedList
{
    private:
        Node *head;
    public:
        SingleLinkedList() { head = 0; }
        ~SingleLinkedList()
        {
            Node *p;
            while(head != 0)
            {
                p = head;
                head = head->link;
                delete p;
            }
        }
        void insertNode(int data, int key)
        {
            Node *temp = new Node(key, data);

            if (head == 0) head = temp;
            else
            {
                Node *p = head;
                while(p->link != 0) p = p->link;
                p->link = temp;
            }    
        }
        void deleteNode(int data)
        {
            Node *p, *q;

            if (head->data == data)
            {
                p = head;
                head = head->link;
                delete p;
            }
            else
            {
                p = head;
                while(p != 0 && p->data != data)
                {
                    q = p;
                    p = p->link;
                }
                if (p != 0)
                {
                    q->link = p->link;
                    delete p;
                }
                else cout << data << " is not in Hash.\n";
            }
        }
        bool isEmpty() {return (head == 0); }
        void traverse()
        {
            Node *p;
            if (!isEmpty())
            {
                p = head;
                while(p->link != 0)
                {
                    cout << p->data << "->";
                    p = p->link;
                }
                cout << p->data;
            }
            cout << endl;
        }
        bool search(int data)
        {
            Node *p;
            if (head != 0)
            {
                p = head;
                while(p != 0 && p->data != data) p = p->link;
                if (p) return true;
                else return false;
            }
        }
};

const int HASH_SIZE = 7;
class HTable
{
    SingleLinkedList* hash_table;
    int hashFunction(int key) const { return (key % HASH_SIZE); }
    int item_num = 0;
    public:
        HTable() { hash_table = new SingleLinkedList[HASH_SIZE]; }
        bool isEmpty();
        bool findData(int) const;
        void insertData(int);
        void deleteData(int);
        void printHash() const;
        friend class SingleLinkedList;
};
bool HTable::isEmpty() { return (item_num == 0); }
void HTable::insertData(int data)
{
    int key = hashFunction(data);
    (hash_table + key)->insertNode(data, key);
    item_num++;
}
void HTable::deleteData(int data)
{
    if (findData(data))
    {
        int key = hashFunction(data);
        (hash_table + key)->deleteNode(data);
        item_num--;
    }
    else cout << data << " is not here!\n";
}
bool HTable::findData(int data) const
{
    int key = hashFunction(data);
    if ((hash_table + key)->isEmpty()) return false;
    else
    {
        if ((hash_table + key)->search(data)) return true;
        else return false;
    }
}
void HTable::printHash() const
{
    for (int i=0; i<HASH_SIZE; i++)
    {
        cout << "HTable[" << i << "]: ";
        (hash_table + i)->traverse();
    }
}

int main()
{
    HTable hash;
    bool exit = false;
    char command;
    while (!exit)
    {
        cout << "Enter command(i, f, d, q) : ";
        cin >> command;
        if (command == 'q') break;

        int key;
        bool found;
        cout << "Enter key: ";
        cin >> key;
        switch(command)
        {
            case 'i':
                hash.insertData(key);
                break;
            case 'f':
                found = hash.findData(key);
                if (!found) cout << "\"Key Not Found\"\n";
                else cout << "\"Hash value: " << key % HASH_SIZE << ", Key is Found.\"\n";   
                break;
            case 'd':
                hash.deleteData(key);
                break;
            default:
                cout << "Bad Command!\n";
                break;
        }
        hash.printHash();
    }
    return 0;
}