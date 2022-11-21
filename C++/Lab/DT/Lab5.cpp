#include <iostream>
#include "new_single_linked_list.h"
using namespace std;

int main()
{
    int choose;
    SingleLinkedList list = SingleLinkedList();
    cout << "Menu\n1. insert\t2. delete\t3. list\t4. search\n5. PrintLast\t6. PrintNth\t7. InvertList\t8. Quit\n";

    while(choose != 8){
        cout << "Enter a number to do -> ";
        cin >> choose;

        switch (choose)
        {
            case 1:
                int value;
                cout << "Enter number to insert.\n";
                cin >> value;
                list.insertNode(value);
                break;

            case 2:
                int target;
                cout << "Enter number to delete.\n";
                cin >> target;
                list.deleteNode(target);
                break;
            
            case 3:
                list.traverse();
                break;

            case 4:
                int find;
                cout << "Enter number to find.\n";
                cin >> find;
                list.search(find);
                break;

            case 5:
                list.printLast();
                break;
            
            case 6:
                int position;
                cout << "Enter a position number to find.\n";
                cin >> position;
                list.printNth(position);
                break;

            case 7:
                list.inverse(list.head);
                break;

            case 8:
                list.~SingleLinkedList();
                return 0;
        }
    }
    
}