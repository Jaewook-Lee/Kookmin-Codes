/****************************************************************************************************************
* 이름 : 이재욱
* 학번 : 20181670
* 숙제 번호 : HW #3
* 설명 : 이 프로그램은 과제를 수행하기 위해 작성됐습니다.
*        이 프로그램의 목적은 두 데이터 파일을 읽어와 그 정보들을 담는
*        연결 리스트를 만들어 조건에 만족하는 내용만 출력하게 하는 것입니다.
* 함수들 :
* makeSLL()
* Node() : 구조체의 생성자입니다.
* SinglyLinkedList() : 클래스 생성자입니다.
* insertNode() : SinglyLinkedList에 새 노드를 삽입하는 함수입니다.
* traverse() : SinglyLinkedList 안에 있는 모든 노드들의 내용을 보여줍니다.
* filterGrade() : 찾고 싶은 등급을 char형의 parameter로 받아 해당 등급만 보여줍니다.
* filterMajor() : 찾고 싶은 전공을 string형의 parameter로 받아 해당 등급만 보여줍니다.
* 전체적인 프로그램 흐름(상세한 알고리즘은 함수별 documentation에 작성했습니다.)
* 0. 프로그램 시작
* 1. 연결 리스트 하나를 선언합니다.
* 2. 선언한 연결 리스트의 주소를 담는 포인터 변수를 하나 생성합니다.
* 3. 연결 리스트의 주소와 첫 번째 파일을 갖고 연결 리스트 하나를 생성합니다.(makeSLL 함수 documentation 참고)
* 4. 연결 리스트의 내용을 출력합니다.(SinglyLinkedList 클래스의 traverse 함수 documentation 참고)
* 5. 특정 등급을 가진 학생들 관련 내용을 출력합니다.(SinglyLinkedList 클래스의 filterGrade 함수 documentation 참고)
* 6. 선언한 연결 리스트에 두 번째 파일의 내용을 추가합니다.
* 7. 특정 전공인 학생들 관련 내용을 출력합니다.(SinglyLinkedList 클래스의 filterMajor 함수 documentation 참고)
* 8. 프로그램 종료
* ***************************************************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

/***********************************************************************
 * Structure : Node
 * 설명 : SinglyLinkedList를 구성하는 node에 대한 구조체를 정의합니다.
 * 변수, 함수:
 * grade : 학생의 등급을 char형으로 저장합니다.
 * name : 학생의 이름을 char형으로 저장합니다.
 * id : 학생의 아이디를 int형으로 저장합니다.
 * major : 학생의 전공을 string형으로 저장합니다.
 * *next : 다음 Node의 주소를 저장합니다.
 * Node() : 구조체의 생성자입니다.
 *          parameter로 이름, 아이디, 전공, 등급을 받습니다.
 * *********************************************************************/
struct Node
{
    char grade;
    char name;
    int id;
    string major;
    Node *next;

    public:
        Node(char s_name, int s_id, string s_major, char s_grade)
        {
            name = s_name;
            id = s_id;
            major = s_major;
            grade = s_grade;
        }
};

/**************************************************************************
 * Class : SinglyLinkedList
 * 설명 : node들이 서로 논리적으로, 선형으로 연결되는 연결 리스트를 정의합니다.
 * 변수, 함수:
 * head : 헤더 노드를 Node pointer 타입으로 정의합니다.
 * SinglyLinkedList() : 클래스 생성자입니다.
 *                      head를 NULL로 초기화합니다.
 * insertNode() : SinglyLinkedList에 새 노드를 삽입하는 함수입니다.
 *                학생 이름과 등급은 char형, 학생의 id는 int형,
 *                학생의 전공은 string형인 parameter들을 받습니다.
 *                반환하는 값이 없습니다.
 * traverse() : SinglyLinkedList 안에 있는 모든 노드들의 내용을 보여줍니다.
 *              반환하는 값 없이 출력만 합니다.
 * filterGrade() : 찾고 싶은 등급을 char형의 parameter로 받아 해당 등급만
 *                  보여줍니다.
 *                  반환하는 값 없이 출력만 합니다.
 * filterMajor() : 찾고 싶은 전공을 string형의 parameter로 받아 해당 등급만
 *                  보여줍니다.
 *                  반환하는 값 없이 출력만 합니다.
 * ************************************************************************/
class SinglyLinkedList
{
    public:
        Node *head;
    public:
        SinglyLinkedList() {head = 0;}
        void insertNode(char, int, string, char);
        void traverse();
        void filterGrade(char);
        void filterMajor(string);
};

/********************************************************************************
 * 함수 : SinglyLinkedList::insertNode()
 * 설명 : Node 생성에 필요한 데이터들을 parameter들로 입력 받아 새 노드를
 *        만든 후 SinglyLinkedList에 삽입합니다.
 * 변수 :
 *      s_name : 학생의 이름이 담긴 char형 변수입니다.
 *      s_id : 학생의 ID가 담긴 int형 변수입니다.
 *      s_major : 학생의 전공이 담긴 string형 변수입니다.
 *      s_grade : 학생의 등급이 담긴 char형 변수입니다.
 *      *temp : Node pointer 타입으로 새로 만들어진 Node의 주소값을 저장합니다.
 *      *p, *q : 둘 다 Node pointer 타입으로 삽입의 과정에서 사용될 변수들입니다.
 * 알고리즘:
 * 0. 함수 시작
 * 1. s_name, s_id, s_major, s_grade를 argument로 보내 새로운 Node를 생성합니다.
 * 2. 생성한 Node의 주소를 담을 포인터 변수를 선언합니다.
 * 3. 삽입에 사용할 두 포인터들을 선언합니다.
 * 4. 새 Node를 조건에 따라 적절히 연결 리스트에 삽입합니다.
 * 4-1. 연결 리스트가 빈 리스트
 * 4-1-1. head의 주소에 새 Node의 주소로 할당합니다.
 * 4-2. 새 Node의 이름 값이 head Node의 이름 값보다 작은 경우
 * 4-2-1. 새 노드의 next에 head의 주소를 할당합니다.
 * 4-2-2. head의 주소에 새 Node의 주소를 할당합니다.
 * 4-3. 새 Node의 이름 값이 head Node의 이름 값보다 큰 경우
 * 4-3-1. p의 주소에 head 주소를 할당합니다.
 * 4-3-2. p의 주소가 NULL값이 아닐 동안 아래의 반복문을 실행합니다.
 * 4-3-2-1. q의 주소에 p의 주소를 할당합니다.
 * 4-3-2-2. p의 주소에 다음 Node의 주소를 할당합니다.
 * 4-3-3. p의 주소가 NULL이 아니면 새 Node의 next에 p 주소를 할당합니다.
 * 4-3-4. q의 next에 새 Node의 주소를 할당합니다.
 * 5. 함수 종료
 * ******************************************************************************/
void SinglyLinkedList::insertNode(char s_name, int s_id, string s_major, char s_grade)
{
    Node *temp = new Node(s_name, s_id, s_major, s_grade);
    Node *p, *q;

    if (head == 0)
    {
        head = temp;
    }
    else if (temp->name < head->name)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        p = head;
        while (p != 0 && p->name < temp->name)
        {
            q = p;
            p = p->next;
        }
        if (p != 0)
        {
            temp->next = p;
        }
        q->next = temp;
    }
    
}

/**********************************************************************************
 * 함수 : SinglyLinkedList::traverse()
 * 설명 : 연결 리스트 안에 있는 모든 Node들의 내용을 출력합니다.
 * 변수 :
 *      *p : 출력에 과정에서 사용될 포인터 변수입니다.
 * 알고리즘 :
 * 0. 함수 시작
 * 1. 출력에 사용될 포인터 변수를 선언합니다.
 * 2. 상황에 따라 적절한 내용을 출력합니다.
 * 2-1. 연결 리스트가 빈 리스트
 * 2-1-1. 연결 리스트가 비어있다고 출력합니다.
 * 2-2. 연결 리스트가 비어 있지 않은 리스트
 * 2-2-1. p의 주소에 head의 주소를 할당합니다.
 * 2-2-2. p의 주소가 NULL이 아닐 동안 아래의 반복문을 실행합니다.
 * 2-2-2-1. 이름, 아이디, 전공, 등급을 출력
 * 2-2-2-2. p의 주소에 p의 next에 담긴 주소를 할당합니다.
 * ********************************************************************************/
void SinglyLinkedList::traverse()
{
    Node *p;
    if (head == 0)
    {
        cout << "This list is empty.\n";
    }
    else
    {
        cout << "Name\tID\tMajor\tGrade\n";

        p = head;
        while (p != 0)
        {
            cout << p->name << "\t" << p->id << "\t" << p->major << "\t" << p->grade << endl;
            p = p->next;
        }
        cout << "\n";
    }
}

/**********************************************************************************
 * 함수 : SinglyLinkedList::filterGrade()
 * 설명 : 연결 리스트 안에 있는 Node들 중 특정 등급을 가진 Node들의 내용을 출력합니다.
 * 변수 :
 *      s_grade : 찾으려 하는 등급이 담긴 char형 변수입니다.
 *      *p : 출력에 과정에서 사용될 포인터 변수입니다.
 * 알고리즘 :
 * 0. 함수 시작
 * 1. 출력에 사용될 포인터 변수를 선언합니다.
 * 2. 상황에 따라 적절한 내용을 출력합니다.
 * 2-1. 연결 리스트가 빈 리스트
 * 2-1-1. 연결 리스트가 비어있다고 출력합니다.
 * 2-2. 연결 리스트가 비어 있지 않은 리스트
 * 2-2-1. p의 주소에 head의 주소를 할당합니다.
 * 2-2-2. p의 주소가 NULL이 아닐 동안 아래의 반복문을 실행합니다.
 * 2-2-2-1. p 안에 담긴 등급이 찾는 등급과 같다면 p의 내용을 출력합니다.
 * 2-2-2-2. p의 주소에 p의 next에 담긴 주소를 할당합니다.
 * ********************************************************************************/
void SinglyLinkedList::filterGrade(char s_grade)
{
    Node *p;
    if (head == 0)
    {
        cout << "This list is empty.\n";
    }
    else
    {
        cout << "Name\tID\tMajor\tGrade\n";

        p = head;
        while (p != 0)
        {
            if (p->grade == s_grade)
            {
                cout << p->name << "\t" << p->id << "\t" << p->major << "\t" << p->grade << endl;
            }
            p = p->next;
        }
        cout << "\n";
    }
}

/**********************************************************************************
 * 함수 : SinglyLinkedList::filterMajor()
 * 설명 : 연결 리스트 안에 있는 Node들 중 특정 전공을 가진 Node들의 내용을 출력합니다.
 * 변수 :
 *      s_major : 찾으려는 전공 이름이 담긴 string형 변수입니다.
 *      *p : 출력에 과정에서 사용될 포인터 변수입니다.
 * 알고리즘 :
 * 0. 함수 시작
 * 1. 출력에 사용될 포인터 변수를 선언합니다.
 * 2. 상황에 따라 적절한 내용을 출력합니다.
 * 2-1. 연결 리스트가 빈 리스트
 * 2-1-1. 연결 리스트가 비어있다고 출력합니다.
 * 2-2. 연결 리스트가 비어 있지 않은 리스트
 * 2-2-1. p의 주소에 head의 주소를 할당합니다.
 * 2-2-2. p의 주소가 NULL이 아닐 동안 아래의 반복문을 실행합니다.
 * 2-2-2-1. p 안에 담긴 전공 이름이 찾는 전공 이름과 같다면 p의 내용을 출력합니다.
 * 2-2-2-2. p의 주소에 p의 next에 담긴 주소를 할당합니다.
 * ********************************************************************************/
void SinglyLinkedList::filterMajor(string s_major)
{
    Node *p;
    if (head == 0)
    {
        cout << "This list is empty.\n";
    }
    else
    {
        cout << "Name\tID\tMajor\tGrade\n";

        p = head;
        while (p != 0)
        {
            if (p->major.compare(s_major) == 0)
            {
                cout << p->name << "\t" << p->id << "\t" << p->major << "\t" << p->grade << endl;
            }
            p = p->next;
        }
        cout << "\n";
    }
}


void makeSLL(const string file_name, SinglyLinkedList *list);

/******************************************************************************************************************
 * 함수 : main()
 * 설명 : "students_file.txt" 파일 안에 담긴 내용을 바탕으로 연결 리스트 하나를 생성합니다.
 *        두 가지 테스트를 한 후 "students_file2.txt" 내용을 연결 리스트에 추가합니다.
 * 변수 :
 *      students_list : SinglyLinkedList 타입의 연결 리스트입니다.
 *                      처음에는 "students_file.txt"내용만 담겨있고, 나중에는 "students_file2.txt" 내용도 추가됩니다.
 *      *list_ptr: students_list의 주소를 가지는 포인터 변수입니다.
 * ***************************************************************************************************************/
int main()
{
    SinglyLinkedList students_list = SinglyLinkedList();
    SinglyLinkedList *list_ptr = &students_list;
    makeSLL("students_file.txt", list_ptr);
    students_list.traverse();
    students_list.filterGrade('A');

    makeSLL("students_file2.txt", list_ptr);
    students_list.filterMajor("CS");
}

/*****************************************************************************************************************
 * 함수 : makeSLL()
 * 설명 : parameter로 받아온 파일 이름에 담긴 내용들을 가지는 연결 리스트를 또 다른 파라미터인 연결 리스트의 주소 안에서
 *        생성합니다.
 * 변수 :
 *      file_name : 읽어올 파일의 이름이 담긴 string 상수입니다.
 *      *list : 생성될 연결 리스트의 주소가 담긴 SinglyLinkedList pointer 입니다.
 *      reader : 파일 스트림 reader입니다. 파일의 내용을 읽어옵니다.
 *      s_name : 학생의 이름이 담길 char형 변수입니다.
 *      s_id : 학생의 ID가 담길 int형 변수입니다.
 *      s_major : 학생의 전공이 담길 string형 변수입니다.
 *      s_grade : 학생의 등급이 담길 char형 변수입니다.
 * 알고리즘 :
 * 0. 함수 시작
 * 1. 파일을 읽어올 reader를 선언합니다.
 * 2. reader가 파일의 끝을 읽을 때 까지 아래의 반복문을 수행합니다.
 * 2-1. 학생의 이름, 등급, 아이디, 전공이 담길 네 변수들을 선언합니다.
 * 2-2. reader가 이름, 아이디, 전공, 등급 순서대로 읽습니다.
 * 2-3. 해당 변수들에 할당합니다.
 * 2-4. reader가 파일의 끝을 읽었으면 반복문을 종료합니다.
 * 2-5. 학생의 이름과 등급, 아이디, 전공이 담긴 네 변수들을 argument로 해서 연결 리스트의 insertNode()함수로 보냅니다.
 * 3. reader기를 종료합니다.
 * 4. 함수 종료
 * ***************************************************************************************************************/
void makeSLL(const string file_name, SinglyLinkedList *list)
{
    ifstream reader;
    reader.open(file_name);

    while (!reader.eof())
    {
        char s_name, s_grade;
        int s_id;
        string s_major;

        reader >> s_name >> s_id >> s_major >> s_grade;
        if (reader.eof()) // reader가 마지막 줄을 두 번 읽는 문제의 해결을 위해 eof 체크를 두 번 실행합니다.
        {
            break;
        }
        list->insertNode(s_name, s_id, s_major, s_grade);
    }
    reader.close();
}