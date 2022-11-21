/* Author : Jaewook-Lee */
/* Linked Method */
#include <iostream>
using namespace std;

struct Node
{
    int key;
    char data;
    public:
        Node() : key(-1), data('\0') {}
        Node(char data) : key(-1) { this->data = data; }
        Node(char data, int key)
        {
            this->data = data;
            this->key = key;
        }
};

const int HASH_SIZE = 100;
class Hash
{
    Node* hash_table;
    int item_cnt = 0;
    int hashFunction(char) const;

    public:
        Hash() { hash_table = new Node[HASH_SIZE]; } // Make also overflow area
        bool isFull() { return (item_cnt == HASH_SIZE); }
        bool isEmpty() { return (item_cnt == 0); }
        int findData(char);
        void insertData(char);
        void deleteData(char);
        void printHash();
};
int Hash::hashFunction(char data) const
{
    int key = (int)data;
    if (key >= 65 && key <= 90) key += 32;
    return (key - 97);
}
int Hash::findData(char data)
{
    int key = hashFunction(data);

    if (hash_table[key].data == data) return key;
    else if (hash_table[key].data == '\0') return -1;
    else
    {
        int idx = key + 1;
        while(hash_table[idx].data != data && idx != key) { idx = (idx + 1) % HASH_SIZE; }
        if (hash_table[idx].data == data) return idx;
        if (idx == key) return -1;
    }    
}
void Hash::insertData(char data)
{
    if (isFull()) cout << "Hash is Full\n";
    else
    {
        if (findData(data) != -1) cout << "Not allow to add duplicating data.\n";
        else
        {
            int key = hashFunction(data);
            Node input_node(data, key);
            if (hash_table[key].data == '\0') hash_table[key] = input_node;
            else
            {
                int idx = 26;
                while (hash_table[idx].data != '\0')
                {
                    if (idx == HASH_SIZE) idx = 26;
                    else idx = (idx + 1) % HASH_SIZE;
                }
                hash_table[idx] = input_node;
            }
            item_cnt++;
        }
    }
}
void Hash::deleteData(char data)
{
    if (isEmpty()) cout << "Hash is Empty\n";
    else
    {
        int idx = findData(data);
        if (idx == -1) cout << data << " is not in hash\n";
        else
        {
            hash_table[idx] = Node('\0');
            item_cnt--;
            if (idx < 26)
            {
                int i;
                for (i=26; i<HASH_SIZE; i++)
                {
                    if (hash_table[i].key == idx)
                    {
                        hash_table[idx] = hash_table[i];
                        break;
                    }
                }
                hash_table[i] = Node('\0');
            }
        }
    }
}
void Hash::printHash()
{
    cout << "-----Prime Area--------" << endl;
    for (int i=0; i<HASH_SIZE; i++)
    {
        if (i == 26) cout << "-----Overflow Area--------" << endl;

        if ((hash_table + i)->data == '\0') continue;
        else cout << (hash_table + i)->data << endl;
    }
    cout << "-------------------------" << endl;
}

int main()
{
    Hash hash;
    
    if (hash.isEmpty()) cout << "Hash is Empty now\n";
    else cout << "Something is in hash!\n";

    hash.insertData('A');
    hash.insertData('C');
    hash.insertData('H');
    hash.insertData('a');
    hash.insertData('h');
    hash.insertData('g');
    hash.insertData('G');
    hash.printHash();

    if (hash.findData('Z') != -1) cout << "Found Z!\n";
    else cout << "Z is not here.\n";
    if (hash.findData('g') != -1) cout << "Found g!\n";
    else cout << "g is not here.\n";

    hash.deleteData('H');
    hash.deleteData('C');
    if (hash.findData('H')) cout << "Found H!\n";
    else cout << "H is not here.\n";
    hash.printHash();

    hash.deleteData('G');
    hash.printHash();

    return 0;
}