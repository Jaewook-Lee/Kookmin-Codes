/************************************************************************************************************************************************************
* 이름 : 이재욱
* 학번 : 20181670
* 숙제 번호 : HW #5
* 설명 :
*     이 프로그램은 과제를 수행하기 위해 작성됐습니다.
*     이 프로그램의 목적은 임의의 다섯 숫자들로 이뤄진 이진 트리를 출력하고, 콘솔 창에서 사용자에게 숫자 입력을 받아 MIN HEAP을 만들어 heap 연산을 하는 것입니다.
* 함수 :
* Node (structure : Node) : 구조체의 생성자입니다.
* LinkedBinTree (class : LinkedBinTree) : 이진 트리 클래스의 생성자입니다.
* DestructLinkedBinTree (class : LinkedBinTree) : 이진 트리 클래스의 소멸자입니다.
* printElement (class : LinkedBinTree) : 이진 트리 안의 값들을 순서대로 출력하는 함수입니다.
* insertValue (class : MinHeap) : MIN HEAP 안에 값을 삽입하는 함수입니다.
* deleteRoot (class : MinHeap) : MIN HEAP의 root를 지우고 MIN HEAP을 재구성하는 함수입니다.
* printHeap (class : MinHeap) : MIN HEAP 안의 값들을 순서대로 출력하는 함수입니다.
* isEmpty (class : MinHeap) : MIN HEAP이 비어있는지 판단하는 함수입니다.
* isFull (class : MinHeap) : MIN HEAP이 가득 찼는지 판단하는 함수입니다.
* level (class : MinHeap) : MIN HEAP의 레벨을 계산하는 함수입니다.
* main():
*     임의의 다섯 개의 숫자를 LinkedBinTree 클래스의 인스턴스(tree)에 삽입합니다.
*     그 후 사용자가 선택한 메뉴에 따라 MinHeap 클래스의 인스턴스(m_heap)의 연산(삽입, 삭제, 출력, 비어있는지 판단, 가득 찼는지 판단)을 실행합니다.
* 알고리즘:
*     이진 트리에 값을 넣는 알고리즘은 아래와 같습니다.
*     1. new_node 라는 새 Node 포인터 타입의 변수를 생성하고, 이 노드안의 값은 사용자가 임의로 설정한 숫자로 설정합니다.
*     2. 만약 이진 트리가 비어있다면 new_node를 root로 지정합니다.
*     3. 비어있지 않다면 p 라는 새 Node 포인터 타입의 변수를 생성하고, root 노드의 내용을 가리키도록 설정합니다.
*     3-1. p에게 양쪽 자식이 모두 존재하는 동안 p는 p의 왼쪽 자식으로 설정합니다.
*     3-2. 만약 p에게 왼쪽 자식이 없다면 new_node의 위치는 p의 왼쪽 자식의 위치로 설정합니다.
*     3-3. 만약 p에게 오른쪽 자식만 없다면 new_node의 위치는 p의 오른쪽 자식의 위치로 설정합니다.
*     
*     이진 트리의 모든 노드 값들을 출력하는 알고리즘은 아래와 같습니다.
*     1. 만약 이진 트리가 비어있다면 비어있다고 알립니다.
*     2. 아니면, 출력에 사용할 Queue를 q라는 이름으로 선언합니다. q에는 Node들이 담깁니다.
*     3. q에 root 노드를 push합니다.
*     4. q가 비어있지 않은 동안 아래의 반복문을 실행합니다.
*     4-1. printed 라는 새 Node 포인터 타입의 변수를 생성하고, 이 노드에 q의 front가 가리키는 노드 주소를 할당합니다.
*     4-2. printed의 값을 출력합니다.
*     4-3. q의 front가 가리키는 노드를 pop 합니다.
*     4-4. printed에게 왼쪽 자식이 있다면 왼쪽 자식을 q에 push합니다.
*     4-5. printed에게 오른쪽 자식이 있다면 오른쪽 자식을 q에 push합니다.
*
*     min heap에 값을 삽입하는 알고리즘은 아래와 같습니다.
*     1. 만약 min heap이 가득 찼다면 삽입을 하지 않습니다.
*     2. min heap의 멤버 변수인 counter(삽입 횟수를 세는 변수) 값을 1 증가시킵니다.
*     3. 삽입할 인덱스를 가리킬 변수 index를 선언하고 counter - 1 값으로 초기화합니다.
*     4. index가 0이 아니고 삽입할 값이 parent의 값보다 작을 동안 아래의 반복문을 실행합니다.
*     4-1. parent의 값을 min heap의 index 위치에 작성합니다.
*     4-2. index 값에서 1을 빼고 2로 나눈 값을 다시 index로 지정합니다.
*     5. min heap의 index 위치에 삽입합니다.
*
*     min heap에서 루트 노드를 제거하고 min heap을 재구축하는 알고리즘은 아래와 같습니다.
*     1. 만약 min heap이 비어있다면 제거를 하지 않습니다.
*     2. min heap의 가장 깊은 레벨의 가장 오른쪽 자식의 값을 저장할 변수 temp 를 선언합니다.
*     3. parent의 위치를 나타내는 변수인 parent_idx를 선언하고 0으로 초기화합니다.
*     4. parent의 직계 왼쪽 자식의 위치를 나타내는 변수인 child_idx를 선언하고 1로 초기화합니다.
*     5. child_idx가 min heap안의 값들의 갯수(counter)보다 작거나 같은 동안 아래의 반복문을 실행합니다.
*     5-1. 만약 child_idx가 counter보다 작으면서 child_idx 위치의 값이 child_idx + 1 위치의 값보다 크면 child_idx 값을 1 증가시킵니다.
*     5-2. 만약 temp 값이 min heap의 child_idx 위치의 값보다 작다면 반복문을 강제 중지시킵니다.
*     5-3. min heap의 parent_idx 위치의 값을 min_heap의 child_idx 위치의 값으로 바꿉니다.
*     5-4. parent_idx값을 child_idx값으로 바꿉니다.
*     5-5. child_idx 값은 child_idx의 두 배에 1을 더한 값으로 변경합니다.
*     6. min heap의 parent_idx 위치에 temp 값을 작성합니다.
* **********************************************************************************************************************************************************/
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    Node *left_link;
    Node *right_link;

    /****************************************************************************************************
     *함수 : Node
     *설명 : left_link와 right_link 모두 null로 초기화하고, data는 사용자가 임의로 선택한 값으로 설정합니다.
     *변수들:
     *    value : 사용자가 임의로 설정한 숫자를 받아들일 int형 인자입니다.
     *    data : Node 구조체의 멤버 변수로 int형 값을 저장합니다.
     *    left_link, right_link : Node 구조체의 멤버 변수로 Node의 주소를 저장하는 Node pointer형입니다.
     *****************************************************************************************************/
    public:
        Node(int value) : left_link(0), right_link(0)
        {
            data = value;
        }
};

class LinkedBinTree
{
    public:
        Node *root;
        LinkedBinTree() : root(0) {};
        void DestructLinkedBinTree(Node*);
        void insertNode(int);
        void printElements();
};

/****************************************************************************************
 * 함수 : DestructLinkedBinTree
 * 설명 : 재귀적 방법을 통해 이진 트리 안의 모든 노드를 지웁니다.
 * 변수:
 *     a : 이진 트리의 root 노드의 주소를 인자로 받기 위해 선언된 Node pointer형 변수입니다.
 * **************************************************************************************/
void LinkedBinTree::DestructLinkedBinTree(Node *a)
{
    if (a == 0) return;
    DestructLinkedBinTree(a->left_link);
    DestructLinkedBinTree(a->right_link);
    delete a;
}

/******************************************************************************************
 * 함수 : insertNode
 * 설명 : 사용자에게 입력 받은 값을 바탕으로 해서 새 Node를 생성 후 이진 트리에 삽입합니다.
 * 변수들:
 *     value : 사용자가 입력한 값을 인자로 받아올 int형 변수입니다.
 *     new_node : value 값을 바탕으로 만든 새 Node의 주소를 저장할 Node pointer형 변수입니다.
 * ****************************************************************************************/
void LinkedBinTree::insertNode(int value)
{
    Node *new_node = new Node(value);
    
    if (root == 0) root = new_node;
    else
    {
        Node *p = root;
        while (p->left_link != 0 && p->right_link != 0) p = p->left_link;
        if (p->left_link == 0) p->left_link = new_node;
        else p->right_link = new_node;
    }
}

/******************************************************************************
 * 함수 : printElements
 * 설명 : 이진 트리 안에 있는 모든 노드들의 값을 순서대로 출력합니다.
 * 변수들:
 *     q : Node pointer형 변수들을 담을 queue입니다.
 *     printed : 출력될 값을 가진 Node의 주소를 저장할 Node pointer형 변수입니다.
 * ****************************************************************************/
void LinkedBinTree::printElements()
{
    if (root == 0) cout << "Tree is empty." << endl;
    else
    {
        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node *printed = q.front();
            cout << printed->data << " ";
            q.pop();

            if (printed->left_link != 0) q.push(printed->left_link);
            if (printed->right_link != 0) q.push(printed->right_link);
        }
        cout << endl;
    }
}

class MinHeap
{
    const static int HEAP_SIZE = 7; // min heap의 최대 크기를 설정합니다.
    int heap[HEAP_SIZE];
    int counter = 0; // min heap안에 저장된 값들의 갯수를 세는 변수입니다.
    public:
        void insertValue(int);
        void deleteRoot();
        void printHeap();
        bool isEmpty();
        bool isFull();
        int level();
};

/***********************************************************************
 * 함수 : insertValue
 * 설명 : 사용자가 입력한 값을 min heap에 삽입합니다.
 * 변수들:
 *     value : 사용자가 입력한 값을 인자로 받아오기 위한 int형 변수입니다.
 *     index : value를 삽입할 위치를 지정할 int형 변수입니다.
 * *********************************************************************/
void MinHeap::insertValue(int value)
{
    if (isFull()) return;

    counter++;
    int index = counter - 1;

    while (index != 0 && value < heap[(index - 1) / 2])
    {
        heap[index] = heap[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    heap[index] = value;
}

/*****************************************************************************************
 * 함수 : deleteRoot
 * 설명 : min heap의 root값을 제거하고 min heap을 다시 구축합니다.
 * 변수들:
 *     temp : min heap의 가장 깊은 레벨의 가장 오른쪽 자식의 값을 저장하는 int형 변수입니다.
 *     parent_idx : parent의 인덱스를 가리키는 int형 변수입니다.
 *     child_idx : parent의 직계 왼쪽 child의 인덱스를 가리키는 int형 변수입니다.
 * ***************************************************************************************/
void MinHeap::deleteRoot()
{
    if (isEmpty()) return;

    int temp = heap[--counter];
    int parent_idx = 0, child_idx = 1;

    while (child_idx <= counter)
    {
        if (child_idx < counter && heap[child_idx] > heap[child_idx + 1]) child_idx++;
        if (temp <= heap[child_idx]) break;
        heap[parent_idx] = heap[child_idx];
        parent_idx = child_idx;
        child_idx = 2 * child_idx + 1;
    }
    heap[parent_idx] = temp;
}

/*************************************************************
 * 함수 : printHeap
 * 설명 : min heap 안에 있는 모든 값들을 순서대로 출력합니다.
 * 변수:
 *     i : min heap 안의 값들에 접근하기 위한 int형 변수입니다.
 * **********************************************************/
void MinHeap::printHeap()
{
    if (counter == 0) cout << "Heap is Empty!" << endl;
    else
    {
        for (int i=0; i<counter; i++) cout << heap[i] << " ";
        cout << endl;
    }
}

/***********************************************************************************
 * 함수 : isEmpty
 * 설명 : min heap이 비어있는지 판단합니다. 비어있으면 true, 아니면 false를 반환합니다.
 * *********************************************************************************/
bool MinHeap::isEmpty() { return counter == 0 ? true : false; }

/*********************************************************************************
 * 함수 : isFull
 * 설명 : min heap이 다 찼는지 판단합니다. 다 찼다면 true, 아니면 false를 반환합니다.
 * *******************************************************************************/
bool MinHeap::isFull() { return counter == HEAP_SIZE ? true : false; }

/***********************************************
 * 함수 : level
 * 설명 : min heap의 레벨을 계산하고 반환합니다.
 * *********************************************/
int MinHeap::level()
{
    if (counter == 0) return 0;
    else if (counter == 1) return 1;
    else return (int)sqrt(counter) + 1;
}

/*************************************************************************************************************************
 * 함수 : main
 * 설명 :
 *     이진 트리에 사용자가 사전에 임의로 지정한 다섯 숫자들을 삽입 후 이진 트리를 출력합니다.
 *     그 후 사용자의 선택에 따라 min heap의 연산들(삽입, 삭제, 출력, 가득 찼는지 또는 비어있는지 판단, 레벨 출력)을 수행합니다.
 * 변수들:
 *     tree : LinkedBinTree 클래스의 인스턴스입니다.
 *     m_heap : MinHeap 클래스의 인스턴스입니다.
 *     exit : 반복문을 탈출하기 위해 사용된는 bool형 변수입니다.
 *     selector : 사용자의 메뉴 선택 결과를 저장할 int형 변수입니다.
 *     empty : m_heap의 isEmpty 함수의 반환 값을 저장하는 bool형 변수입니다.
 *     full : m_heap의 isFull 함수의 반환 값을 저장하는 bool형 변수입니다.
 *     insert_value : min heap에 삽입할 숫자를 저장할 int형 변수입니다.
 * **********************************************************************************************************************/
int main()
{
    LinkedBinTree tree;
    tree.insertNode(9);
    tree.insertNode(2);
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(8);
    tree.printElements();
    tree.DestructLinkedBinTree(tree.root);

    MinHeap m_heap;
    bool exit = false;
    while(!exit)
    {
        int selector;
        cout << "1. Insert\t2.Delete\t3.Empty\t4.Full\t5.Print\t6.Level\t7.Quit\n";
        cin >> selector;
        
        switch (selector)
        {
            bool empty, full;
            case 1:
                int insert_value;
                cout << "Enter number to insert : ";
                cin >> insert_value;
                m_heap.insertValue(insert_value);
                break;
            case 2:
                m_heap.deleteRoot();
                break;
            case 3:
                empty = m_heap.isEmpty();
                if (empty) cout << "Heap is Empty" << endl;
                else cout << "Heap is not Empty" << endl;
                break;
            case 4:
                full = m_heap.isFull();
                if (full) cout << "Heap is Full" << endl;
                else cout << "Heap is not Full" << endl;
                break;
            case 5:
                m_heap.printHeap();
                break;
            case 6:
                cout << m_heap.level() << endl;
                break;
            case 7:
                exit = true;
                break;
        }
    }

    return 0;
}