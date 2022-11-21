#include <iostream>
#include <fstream>
#include <string>
#include "new_double_linked_list.h"
using namespace std;

void makeSLL(const string file_name, DoubleLinkedList *list);
int main()
{
    DoubleLinkedList students_list = DoubleLinkedList();
    DoubleLinkedList *list_ptr = &students_list;
    makeSLL("lab6.txt", list_ptr);
    int selector;
    string data_name = "";
    int data_weight = 0;
    int data_height = 0;
    int index = 0;

    while (true)
    {
        cout << "Menu(1. Insert-after(nth)\t2. Delete\t3. Forward\t4.Backward\t5.Search\t6.Find-nth\t7.exit)\n";
        cin >> selector;
        switch (selector)
        {
            case 1:
                cout << "Which position to insert? ";
                cin >> index;
                cout << "Enter data to insert -> ";
                cin >> data_name >> data_weight >> data_height;
                students_list.insertNth(index, data_name, data_weight, data_height);
                break;
            case 2:
                cout << "Enter a name to delete : ";
                cin >> data_name;
                students_list.deleteNode(data_name);
                break;
            case 3:
                students_list.showForward();
                break;
            case 4:
                students_list.showBackward();
                break;
            case 5:
                cout << "Enter a name to find : ";
                cin >> data_name;
                students_list.search(data_name);
                break;
            case 6:
                cout << "Enter a position to find : ";
                cin >> index;
                students_list.searchNth(index);
                break;
        }
        if (selector == 7)
            break;
    }
}

void makeSLL(const string file_name, DoubleLinkedList *list)
{
    ifstream reader;
    reader.open(file_name);

    while (!reader.eof())
    {
        string s_name;
        int s_weight, s_height;

        reader >> s_name >> s_weight >> s_height;
        if (reader.eof()) // reader가 마지막 줄을 두 번 읽는 문제의 해결을 위해 eof 체크를 두 번 실행합니다.
        {
            break;
        }
        list->insertNode(s_name, s_weight, s_height);
    }
    reader.close();
}