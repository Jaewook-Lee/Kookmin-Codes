/******************************************************************************************************************************************************************************************
* 이름 : 이재욱
* 학번 : 20181670
* 숙제 번호 : HW #4
* 설명 : 이 프로그램은 과제를 수행하기 위해 작성됐습니다. 이 프로그램의 목적은 수식을 콘솔 창에서부터 입력 받고, infix, postfix, prefix 형태의 식과 식의 결과 그리고 트리의 모습까지 출력하는 것입니다.
* 함수들 :
* Node() : 구조체의 생성자입니다.
* LinkedBinTree(string) : 이진 트리 클래스의 생성자입니다.
* DestructLinkedBinTree(Node*) : 이진 트리 클래스의 소멸자입니다.
* insertNode(char) : 이진 트리에 노드를 삽입하는 함수입니다.
* infixTraverse(Node*) : 식의 infix notation을 출력합니다.
* postTraverse(Node*) : 식의 postfix notation을 출력합니다.
* preTraverse(Node*) : 식의 prefix notation을 출력합니다.
* drawTree(Node*, int) : 이진 트리의 형태를 출력합니다.
* eval(Node*) : 식의 결과를 계산해 결과를 리턴하는 함수입니다.
* main() : 수식을 받아오고, 세 가지의 수식의 형태, 계산 결과, 트리의 모습을 출력합니다.
* 전체적인 알고리즘:
* 0. 프로그램 시작
* 1. 콘솔 입력을 통해 사용자에게서 수식을 입력 받습니다.
* 2. 입력 받은 수식을 바탕으로 이진 트리를 생성합니다.
* 2-1. 수식의 각 항을 이진 트리에 삽입할 데이터로 선택합니다.
* 2-2. 선택된 데이터를 넣을 새 Node를 선언합니다.
* 2-3. 데이터의 우선 순위를 결정해 Node 안에 저장합니다.
* 2-3-1. 만약 데이터가 피연산자라면,
* 2-3-1-1. 만약 이진 트리가 비어 있다면 생성한 Node를 root노드로 설정합니다.
* 2-3-1-2. 만약 이진 트리가 비어 있지 않으면,
* 2-3-1-2-1. root 노드의 주소를 담을 새로운 Node 포인터 변수를 선언합니다.
* 2-3-1-2-2. 새로 선언한 Node 포인터 변수의 오른쪽 링크가 가리키는 주소가 null이 아닐 때까지 Node 포인터 변수에 오른쪽 링크가 가리키는 주소를 저장합니다.
* 2-3-1-2-3. Node 포인터 변수의 오른쪽 링크가 새 Node를 가리키도록 설정합니다.
* 2-3-2. 만약 데이터가 연산자라면,
* 2-3-2-1. root노드에 있는 우선 순위가 새로 생성한 Node의 우선순위 보다 크거나 같으면, 새 노드를 root 노드로 설정하고, 전의 root 노드는 새 노드의 왼 쪽의 sub tree로 설정합니다.
* 2-3-2-2. 새 Node의 왼 쪽 링크가 root 노드의 오른쪽 링크가 가리키는 곳으로 설정하고, root의 오른쪽 링크는 새 Node를 가리키도록 설정합니다.
* 3. 이진 트리의 내용을 infix 형태로 출력합니다.
* 3-1. 첫 번째 인자는 이진 트리의 root 노드로 받습니다.
* 3-2. 현재 Node의 왼 쪽 링크가 가리키는 Node가 null이 아닐 때가지 그 노드의 왼 쪽 링크가 가리키는 Node를 인자로 해서 자신의 함수를 다시 호출합니다.
* 3-3. 현재 Node가 갖고 있는 데이터를 출력합니다.
* 3-4. 현재 Node의 오른쪽 링크가 가리키는 Node가 null이 아닐 때까지 그 노드의 왼 쪽 링크가 가리키는 Node를 인자로 해서 자신의 함수를 다시 호출합니다.
* (3-2 ~ 3-4 과정은 재귀적 표현으로 구현합니다.)
* 4. 이진 트리의 내용을 postfix 형태로 출력합니다.
* 4-1. 첫 번째 인자는 이진 트리의 root 노드로 받습니다.
* 4-2. 현재 Node의 왼 쪽 링크가 가리키는 Node가 null이 아닐 때까지 그 노드의 왼 쪽 링크가 가리키는 Node를 인자로 해서 자신의 함수를 다시 호출합니다.
* 4-3. 현재 Node의 오른쪽 링크가 가리키는 Node가 null이 아닐 때까지 그 노드의 왼 쪽 링크가 가리키는 Node를 인자로 해서 자신의 함수를 다시 호출합니다.
* 4-4. 현재 Node가 갖고 있는 데이터를 출력합니다.
* (4-2 ~ 4-4 과정은 재귀적 표현으로 구현합니다.)
* 5. 이진 트리의 내용을 prefix 형태로 출력합니다.
* 5-1. 첫 번째 인자는 이진 트리의 root 노드로 받습니다.
* 5-2. 현재 Node가 갖고 있는 데이터를 출력합니다.
* 5-3. 현재 Node의 왼 쪽 링크가 가리키는 Node가 null이 아닐 때까지 그 Node의 왼 쪽 링크가 가리키는 Node를 인자로 해서 자신의 함수를 다시 호출합니다.
* 5-4. 현재 Node의 오른쪽 링크가 가리키는 Node가 null이 아닐 때까지 그 Node의 왼 쪽 링크가 가리키는 Node를 인자로 해서 자신의 함수를 다시 호출합니다.
* (5-2 ~ 5-4 과정은 재귀적 표현으로 구현합니다.)
* 6. 수식의 결과를 계산합니다.
* 6-1. 이진 트리의 root 노드를 인자로 받습니다.
* 6-2. 연산 결과를 담을 변수를 선언합니다.
* 6-3. 만약 현재 Node의 데이터가 피연산자면, 데이터의 값을 계산 결과를 담을 변수에 저장합니다.
* 6-4. 만약 현재 Node의 데이터가 연산자면,
* 6-4-1. 왼 쪽 값을 저장할 변수를 선언합니다.
* 6-4-2. 현재 Node의 왼 쪽 링크가 피연산자일 때까지 가리키는 Node를 인자로 해서 자신의 함수를 다시 호출합니다.
* 6-4-3. 6-4-2의 결과를 6-4-1에서 선언한 변수에 저장합니다.
* 6-4-4. 오른쪽 값을 저장할 변수를 선언합니다.
* 6-4-5. 현재 Node의 오른쪽 링크가 피연산자일 때까지 가리키는 Node를 인자로 해서 자신의 함수를 다시 호출합니다.
* 6-4-6. 6-4-5의 결과를 6-4-4에서 선언한 변수에 저장합니다.
* 6-4-7. 연산자의 종류에 따라 6-4-1의 값과 6-4-4의 값 사이의 연산을 수행한 결과를 6-2에서 선언한 변수에 저장합니다.
* (6-3, 6-4 과정은 재귀적 표현으로 구현됩니다.)
* 7. 이진 트리의 그림을 출력합니다.
* 7-1. 첫 번째 인자로 이진 트리의 root 노드를, 두 번째 인자는 이진 트리의 level을 받습니다. 단, 두 번째 인자의 입력이 따로 오지 않을 시 값은 1로 가정합니다.
* 7-2. 현재 Node의 오른쪽 링크가 가리키는 Node가 null이 아닐 때까지 현재 Node의 오른쪽 링크가 가리키는 Node와 현재의 이진 트리 level에 1을 더한 값을 각각 인자로 보내 자신의 함수를 다시 호출합니다.
* 7-3. level - 2 만큼 반복하여 공백을 출력한 후 현재 Node의 데이터를 출력합니다.
* 7-4. 만약 현재 Node의 왼쪽 링크와 오른쪽 링크가 가리키는 Node들이 모두 null이 아니면 '<' 을 출력합니다.
* 7-5. 만약 오른쪽 링크가 가리키는 Node만 null이 아니면 '/' 를 출력합니다.
* 7-6. 만약 왼쪽 링크가 가리키는 Node만 null이 아니면 '\' 을 출력합니다.
* 7-7. 현재 Node의 왼쪽 링크가 가리키는 Node가 null이 아닐 때까지 현재 Node의 왼쪽 링크가 가리키는 Node와 현재의 이진 트리 level에 1을 더한 값을 각각 인자로 보내 자신의 함수를 다시 호출합니다.
* (7-2 ~ 7-7 과정은 재귀적 표현으로 구현합니다.)
* 8. 프로그램 종료
* ******************************************************************************************************************************************************************************************/
#include <iostream>
#include <string>
using namespace std;

/***************************************************************************************************************************************************************************************************************************************************************************************
 * Structure : Node
 * 설명 : 이진 트리를 구성하는 노드에 대한 구조체를 정의합니다.
 * 변수, 함수:
 * data : char형의 변수로, 수식의 각 토큰들(연산자 또는 피연산자)을 가집니다.
 * prior : int형의 변수로, data의 우선순위를 가집니다. 기본 값은 4입니다.
 * left_link : Node* 형의 변수로, 한 노드의 left child를 가리키는 주소를 가집니다. 기본 값은 null 입니다.
 * right_link : Node* 형의 변수로, 한 노드의 right child를 가리키는 주소를 가집니다.
 *             기본 값은 null 입니다.
 * Node() : 구조체의 생성자입니다. parameter들은 char형 데이터(data), int형 우선순위(prior), Node*형 왼쪽 링크(left_link), Node*형 오른쪽 링크(right_link) 입니다. prior는 기본적으로 4로 저장되고, left_link와 right_link 모두 null로 정의합니다. 사용자로부터 받은 token을 data에 저장합니다.
 * *************************************************************************************************************************************************************************************************************************************************************************************/
struct Node
{
    char data;
    int prior;
    Node *left_link;
    Node *right_link;

    public:
        Node(char token) : prior(4), left_link(0), right_link(0)
        {
            data = token;
        }
};

/**********************************************************************************************************************************************************
 * Class : LinkedBinTree
 * 설명 : node들이 이진 트리의 형태로 연결되는 이진 트리를 정의합니다.
 * 변수, 함수:
 * root : Node* 타입의 변수로, 이진 트리의 최상위 노드입니다. 외부에서 접근 가능합니다.
 * priorities : char 타입들을 담은 array입니다. 연산자들의 우선순위가 정의돼있습니다. 곱셈과 나눗셈의 우선 순위가 덧셈, 뺄셈보다 큽니다. 외부에서 접근할 수 없습니다.
 * LinkedBinTree() : 클래스 생성자입니다. root를 NULL로 초기화하고, insertNode 함수를 통해 노드들을 생성, 삽입합니다. parameter는 string형의 수식(exp)입니다.
 * DestructLinkedBinTree() : 클래스 소멸자입니다. 이진 트리 안의 모든 노드들을 삭제합니다. parameter는 LinkedBinTree 클래스의 root 노드입니다.
 * insertNode() : LinkedBinTree에 노드들을 삽입하는 함수입니다. parameter는 char형의 토큰(연산자 또는 피연산자)입니다.
 * infixTraverse() : 이진 트리 형태로 저장된 수식을 infix notation 형태로 출력해주는 함수입니다. parameter는 LinkedBinTree 클래스의 root 노드입니다.
 * postfixTraverse() : 이진 트리 형태로 저장된 수식을 postfix notation 형태로 출력해주는 함수입니다. parameter는 LinkedBinTree 클래스의 root 노드입니다.
 * prefixTraverse() : 이진 트리 형태로 저장된 수식을 prefix notation 형태로 출력해주는 함수입니다. parameter는 LinkedBinTree 클래스의 root 노드입니다.
 * drawTree() : 이진 트리의 형태를 출력해주는 함수입니다. parameter들은 LinkedBinTree 클래스의 root 노드와 int형의 레벨(level)입니다. 레벨의 기본 값은 1 입니다.
 * eval() : 수식을 계산하는 함수입니다. parameter는 LinkedBinTree 클래스의 root 노드입니다. 수식의 결과를 int형으로 반환합니다.
 * ********************************************************************************************************************************************************/
class LinkedBinTree
{
    private: char priorities[2][4] = {{'*', '/', '+', '-'}, {'2', '2', '1', '1'}};
    public:
        Node *root;
        LinkedBinTree(string exp);
        void DestructLinkedBinTree(Node *a);
        void insertNode(char data);
        void infixTraverse(Node *a);
        void postfixTraverse(Node *a);
        void prefixTraverse(Node *a);
        void drawTree(Node *a, int level=1);
        int eval(Node *a);
};

/***************************************************************************
 * 함수 : LinkedBinTree::LinkedBinTree()
 * 설명 : 얻은 수식을 바탕으로 이진 트리를 생성하는 생성자입니다.
 * 변수: expression : 콘솔에서 입력 받은 수식을 저장하는 string형 변수입니다.
 * ************************************************************************/
LinkedBinTree::LinkedBinTree(string expression) : root(0)
{
    for (int i=0; i<expression.length(); i++)
    {
        if (expression[i] == ' ') continue;
        else insertNode(expression[i]);
    }
}

/********************************************************************************
 * 함수 : LinkedBinTree::DestructLinkedBinTree()
 * 설명 : 이진 트리의 전체 내용을 삭제하는 소멸자입니다. 재귀적 표현으로 구현했습니다.
 * 변수: a : LinkedBinTree 클래스의 root 노드의 주소를 가지는 Node* 형 변수입니다.
 * *****************************************************************************/
void LinkedBinTree::DestructLinkedBinTree(Node *a)
{
    if (a == NULL) return;
    DestructLinkedBinTree(a->left_link);
    DestructLinkedBinTree(a->right_link);
    delete a;
}

/********************************************************************
 * 함수 : LinkedBinTree::insertNode()
 * 설명 : 노드를 생성하고 이진 트리에 삽입하는 함수입니다.
 * 변수:
 * data : 생성자 함수에서 전달 받은 토큰이 저장되는 char형 변수입니다.
 * p : 노드 삽입에 사용되는 Node*형 변수입니다.
 * ******************************************************************/
void LinkedBinTree::insertNode(char data)
{
    Node *new_node = new Node(data);
    int i;
    for (i=0; i<4; i++)
    {
        if (new_node->data == priorities[0][i])
        {
            new_node->prior = priorities[1][i] - '0';
            break;
        }
    }

    if (i == 4)
    {
        if (root == 0) root = new_node;
        else
        {
            Node *p = root;
            while (p->right_link != 0)
                p = p->right_link;
            p->right_link = new_node;
        }
    }
    else
    {
        if (root->prior >= new_node->prior)
        {
            new_node->left_link = root;
            root = new_node;
        }
        else
        {
            new_node->left_link = root->right_link;
            root->right_link = new_node;
        }
    }
}

/*************************************************************************************************************
 * 함수 : LinkedBinTree::infixTraverse()
 * 설명 : 이진 트리의 형태로 저장된 수식을 infix notation 형태로 출력하는 함수입니다. 재귀적 표현으로 구현했습니다.
 * 변수:
 * a : root 노드의 주소를 담은 변수입니다.
 * ***********************************************************************************************************/
void LinkedBinTree::infixTraverse(Node *a)
{
    if (a)
    {
        infixTraverse(a->left_link);
        cout << a->data << " ";
        infixTraverse(a->right_link);
    }

    if (a == root) cout << endl;
}

/*************************************************************************************************************
 * 함수 : LinkedBinTree::postfixTraverse()
 * 설명 : 이진 트리의 형태로 저장된 수식을 postfix notation 형태로 출력하는 함수입니다. 재귀적 표현으로 구현했습니다.
 * 변수:
 * a : root 노드의 주소를 담은 변수입니다.
 * ***********************************************************************************************************/
void LinkedBinTree::postfixTraverse(Node *a)
{
    if (a)
    {
        postfixTraverse(a->left_link);
        postfixTraverse(a->right_link);
        cout << a->data << " ";
    }
    if (a == root) cout << endl;
}

/*************************************************************************************************************
 * 함수 : LinkedBinTree::prefixTraverse()
 * 설명 : 이진 트리의 형태로 저장된 수식을 prefix notation 형태로 출력하는 함수입니다. 재귀적 표현으로 구현했습니다.
 * 변수:
 * a : root 노드의 주소를 담은 변수입니다.
 * ***********************************************************************************************************/
void LinkedBinTree::prefixTraverse(Node *a)
{
    if (a)
    {
        cout << a->data << " ";
        prefixTraverse(a->left_link);
        prefixTraverse(a->right_link);
    }
    if (a == root) cout << endl;
}

/*************************************************************************
 * 함수 : LinkedBinTree::drawTree()
 * 설명 : 이진 트리의 형태를 출력하는 함수입니다. 재귀적 표현으로 구현했습니다.
 * 변수:
 * a : root 노드의 주소를 담은 변수입니다.
 * level : 이진 트리의 레벨을 담은 변수입니다.
 * ************************************************************************/
void LinkedBinTree::drawTree(Node *a, int level)
{
    if (a == root) cout << "Tree Structure" << endl;
    if (a != 0)
    {
        drawTree(a->right_link, level + 1);

        for (int i=0; i<level-1; i++) cout << "    ";
        cout << a->data << " ";

        if (a->left_link != 0 && a->right_link != 0) cout << "<" << endl;
        else if (a->right_link != 0) cout << "/" << endl;
        else if (a->left_link != 0) cout << "\\" << endl;
        else cout << endl;

        drawTree(a->left_link, level + 1);
    }
}

/*************************************************************************************************************
 * 함수 : LinkedBinTree::infixTraverse()
 * 설명 : 이진 트리의 형태로 저장된 수식의 결과 값을 반환하는 함수입니다. 재귀적 표현으로 구현했습니다.
 * 변수:
 * a : root 노드의 주소를 담은 변수입니다.
 * value : 수식의 결과를 담을 변수입니다.
 * left_value : 현재 실행되고 있는 함수의 인자를 기준으로 왼쪽의 결과 값을 저장할 변수입니다.
 * right_value : 현재 실행되고 있는 함수의 인자를 기준으로 오른쪽의 결과 값을 저장할 변수입니다.
 * ***********************************************************************************************************/
int LinkedBinTree::eval(Node *a)
{
    int value;
    if (a)
    {
        if (a->data - '0' >= 0 && a->data - '0' <= 9) value = a->data - '0';
        else
        {
            int left_value = eval(a->left_link);
            int right_value = eval(a->right_link);

            switch (a->data)
            {
                case '+':
                    value = left_value + right_value;
                    break;
                case '-':
                    value = left_value - right_value;
                    break;
                case '*':
                    value = left_value * right_value;
                    break;
                case '/':
                    value = left_value / right_value;
                    break;
            }
        }
        return value;
    }
}

/***************************************************************************************************************************************************
 * 함수 : main()
 * 설명 : 사용자에게로부터 수식을 입력 받아서 그 수식의 infix, postfix, prefix 형태와 수식의 결과를 출력한 후 이진 트리의 형태를 보여주는 함수입니다.
 * 변수:
 * expression : 사용자가 입력한 수식을 저장할 변수입니다.
 * tree : 사용자가 입력한 수식을 바탕으로 만들어질 이진 트리입니다.
 * *************************************************************************************************************************************************/
int main()
{
    string expression;
    cout << "Enter expression : ";
    getline(cin, expression );

    LinkedBinTree tree(expression);
    cout << "InOrder : ";
    tree.infixTraverse(tree.root);
    cout << "PostOrder : ";
    tree.postfixTraverse(tree.root);
    cout << "PreOrder : ";
    tree.prefixTraverse(tree.root);
    cout << "Evaluation: " << tree.eval(tree.root) << endl;
    tree.drawTree(tree.root);
}