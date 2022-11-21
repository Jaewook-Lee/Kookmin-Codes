/* 학부 : 소프트웨어학부
   학번 : 20181670
   이름 : 이재욱
   작성 날짜 : 2019년 11월 26일 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int INT_MAX = __INT_MAX__;

struct Node
{
    int keyNum;
    int* keyAray;
    Node** ptrAray;

    static Node* getNode(int);
};

/* tempNode의 구조와 통일시키기 위해 2m 개의 branch를 가지는 구조로 구현했습니다.
   하지만 노드의 병합, 분할을 위해 사용할 때 빼고는 node는 m개의 branch를 가지는 노드처럼 다뤄집니다. */
Node* Node::getNode(int m)
{
    Node* newNode = new Node();
    newNode->keyNum = 0;

    /* key값의 최댓값은 0x7fffffff 를 초과하지 않는다고 가정했습니다.
       0x7fffffff로 노드의 빈 공간을 표기합니다. */
    newNode->keyAray = new int[2 * m - 1];
    for (int i = 0; i < m; i++) {*(newNode->keyAray+i) = INT_MAX;}    // INT_MAX = 0x7fffffff

    newNode->ptrAray = new Node*[2 * m];
    for (int j = 0; j <= m; j++) {newNode->ptrAray[j] = NULL;}

    return newNode;
}

class BTree
{
    public:
        Node* root;

        BTree(int m) : root(NULL) { MID_IDX = (int)ceil(m / (double)2) - 1; }
        void insertBTree(BTree&, int, int);
        void deleteBTree(BTree&, int, int);
        void inorderBTree(Node*, int);
    private:
        int MID_IDX;
        vector<Node*> parentStack;

        void insertKey(int, Node*, int);
        bool existAvailSibling(Node*, Node*, Node*&, int&, int&, string&, int);
        int insertion_sort(Node*&, int);
        void sortKeyAray(int[], int);
};
void BTree::insertBTree(BTree& tree, int m, int newKey)
{
    parentStack.clear();

    if (tree.root == NULL)
    {
        Node* newRoot = Node::getNode(m);
        newRoot->keyAray[0] = newKey;
        newRoot->keyNum += 1;

        tree.root = newRoot;
    }
    else
    {
        Node* p = tree.root; Node* q = NULL;
        while (p != NULL)
        {
            int i = 0;
            bool notMoved = true;
            for (; i < m - 1; i++)
            {
                if (p->keyAray[i] == newKey) return;

                if (p->keyAray[i] > newKey)
                {
                    q = p; parentStack.push_back(q);
                    p = p->ptrAray[i];
                    notMoved = false;
                    break;
                }
            }
            if (notMoved)    // if newKey is maximum compare to all of p->keyAray's elements.
            {
                q = p; parentStack.push_back(q);
                p = p->ptrAray[i];
            }
        }

        insertKey(m, p, newKey);    // p must be NULL!
    }
}

void BTree::insertKey(int m, Node* p, int key)
{
    vector<Node*> tempNodeStack;

    while (!parentStack.empty())
    {
        p = parentStack.back(); parentStack.pop_back();
        if (p->keyNum != m - 1)
        {
            p->keyAray[p->keyNum] = key;
            p->keyNum += 1;
            int insertIdx = insertion_sort(p, p->keyNum - 1);    // giving inserted index
            if (!tempNodeStack.empty())
            {
                Node* copyNode = tempNodeStack.back(); tempNodeStack.pop_back();
                p->ptrAray[insertIdx] = copyNode->ptrAray[MID_IDX];
                p->ptrAray[insertIdx + 1] = copyNode->ptrAray[MID_IDX + 1];
            }

            break;
        }
        else
        {
            Node* tempNode = Node::getNode(m); Node* splitedNode = Node::getNode(m);
            for (int i = 0; i < m; i++)
            {
                if (i < m - 1)
                {
                    tempNode->keyAray[i] = p->keyAray[i]; p->keyAray[i] = INT_MAX;
                    p->keyNum -= 1;
                }
                if (i == m - 1) tempNode->keyAray[i] = key;

                tempNode->ptrAray[i] = p->ptrAray[i]; p->ptrAray[i] = NULL; 
            }
            int insertIdx = insertion_sort(tempNode, m - 1);    // In tempNode, newKey's index is always end of keyAray

            if (!tempNodeStack.empty())
            {
                Node* copyNode = tempNodeStack.back(); tempNodeStack.pop_back();
                tempNode->ptrAray[insertIdx] = copyNode->ptrAray[MID_IDX];
                tempNode->ptrAray[insertIdx + 1] = copyNode->ptrAray[MID_IDX + 1];
            }

            key = tempNode->keyAray[MID_IDX];
            for (int j = 0; j <= MID_IDX; j++)
            {
                if (j < MID_IDX)
                {
                    p->keyAray[j] = tempNode->keyAray[j]; tempNode->keyAray[j] = INT_MAX;
                    p->keyNum += 1;
                }
                p->ptrAray[j] = tempNode->ptrAray[j]; tempNode->ptrAray[j] = NULL;
            }

            for (int j = MID_IDX + 1; j <= m; j++)
            {
                if (j < m)
                {
                    splitedNode->keyAray[j - MID_IDX - 1] = tempNode->keyAray[j]; tempNode->keyAray[j] = INT_MAX;
                    splitedNode->keyNum += 1;
                }
                splitedNode->ptrAray[j - MID_IDX - 1] = tempNode->ptrAray[j]; tempNode->ptrAray[j] = NULL;
            }

            if (parentStack.empty())
            {
                Node* newRoot = Node::getNode(m);
                newRoot->keyAray[0] = key;
                newRoot->ptrAray[0] = p;
                newRoot->ptrAray[1] = splitedNode;
                newRoot->keyNum += 1;

                root = newRoot;
                break;
            }
            else
            {
                tempNode->ptrAray[MID_IDX] = p;
                tempNode->ptrAray[MID_IDX + 1] = splitedNode;
                tempNodeStack.push_back(tempNode);
            }
        }
    }
}

void BTree::deleteBTree(BTree& tree, int m, int oldKey)
{
    parentStack.clear();

    /* Searching key */
    Node* p = tree.root;
    int foundIdx = -1;
    while (p != NULL)
    {
        int i = 0;
        while (i < p->keyNum && oldKey > p->keyAray[i]) i++;

        if (i < p->keyNum && oldKey == p->keyAray[i])
        {
            foundIdx = i;
            break;
        }

        parentStack.push_back(p);
        p = p->ptrAray[i];
    }
    if (foundIdx == -1) return;

    int i = 0;
    for (; i < m && p->ptrAray[i] != NULL; i++)

    if (i != m)    // p is internal node.
    {
        Node* internalNode = p;
        parentStack.push_back(internalNode);
        p = p->ptrAray[foundIdx + 1];

        while (p != NULL)
        {
            parentStack.push_back(p);
            p = p->ptrAray[0];
        }
        if (p == NULL)    // Switching oldKey with 후행 키
        {
            p = parentStack.back(); parentStack.pop_back();
            int temp = internalNode->keyAray[foundIdx];
            internalNode->keyAray[foundIdx] = p->keyAray[0];
            p->keyAray[0] = temp;
        }
    }

    /* Now p is terminal node. */
    for (int j = 0; j < p->keyNum; j++)
    {
        if (p->keyAray[j] == oldKey)
        {
            p->keyAray[j] = INT_MAX;
            p->keyNum--;
            break;
        }
    }
    sortKeyAray(p->keyAray, m);

    Node* parent = NULL;
    if (!parentStack.empty())
    {
        parent = parentStack.back();
        parentStack.pop_back();
    }

    bool finish = false;
    do
    {
        int parentMidkeyIdx = -1; int siblingDelkeyIdx = -1;
        Node* sibling = NULL;
        string relation = "None";

        if (p == root || p->keyNum >= MID_IDX) finish = true;

        /* Find available sibling node. 
           If all sibling nodes will be underflow,
           sibling node will be leftmost sibling. */
        else if (existAvailSibling(parent, p, sibling, parentMidkeyIdx, siblingDelkeyIdx, relation, m))    // 키의 재분배가 가능할 경우.
        {
            p->keyAray[p->keyNum] = parent->keyAray[parentMidkeyIdx];
            p->keyNum++;
            parent->keyAray[parentMidkeyIdx] = sibling->keyAray[siblingDelkeyIdx];
            sibling->keyAray[siblingDelkeyIdx] = INT_MAX;

            /* Rearrange pointers of p and sibling. */
            if (relation.compare("R") == 0)
            {
                for (int i = 0; i < m; i++)
                {
                    if (p->ptrAray[i] == NULL)
                    {
                        p->ptrAray[i] = sibling->ptrAray[0]; sibling->ptrAray[0] = NULL;
                        break;
                    }
                }
            }
            else if (relation.compare("L") == 0)
            {
                int ptrLastIdx = m - 1;
                for (int i = ptrLastIdx - 1; i >= 0; i--) p->ptrAray[i] = p->ptrAray[i + 1];
                p->ptrAray[0] = sibling->ptrAray[ptrLastIdx]; sibling->ptrAray[ptrLastIdx] = NULL;
            }

            sibling->keyNum--;

            /* sorting sibling node. */
            Node* tempNode = Node::getNode(m);
            for (int i = 0; i < m; i++)
            {
                if (i < m - 1)
                {
                    tempNode->keyAray[i] = sibling->keyAray[i]; sibling->keyAray[i] = INT_MAX;
                }
                tempNode->ptrAray[i] = sibling->ptrAray[i]; sibling->ptrAray[i] = NULL;
            }

            int insertIdx = 0;
            for (int j = 0; j < m; j++)
            {
                if (tempNode->ptrAray[j] != NULL)
                {
                    sibling->ptrAray[insertIdx] = tempNode->ptrAray[j];
                    insertIdx++;
                }
            }

            insertIdx = 0;
            for (int k = 0; k < m - 1; k++)
            {
                if (tempNode->keyAray[k] != INT_MAX)
                {
                    sibling->keyAray[insertIdx] = tempNode->keyAray[k];
                    insertIdx++;
                }
            }
        
            finish = true;
        }
        else    // 키의 재분배가 불가능하여 노드들을 합쳐야 하는 경우.
        {
            /* Copy contents of p, parent and sibling node to tempNode. */
            Node* tempNode = Node::getNode(m);
            int i = 0; int j = 0;
            for (; i < p->keyNum; i++)
            {
                tempNode->keyAray[i] = p->keyAray[i];
                p->keyAray[i] = INT_MAX;
                tempNode->keyNum++;
            }
            p->keyNum = 0;
            for (; j < sibling->keyNum; j++)
            {
                tempNode->keyAray[i + j] = sibling->keyAray[j];
                sibling->keyAray[j] = INT_MAX;
                tempNode->keyNum++;
            }
            sibling->keyNum = 0;
            tempNode->keyAray[i + j] = parent->keyAray[parentMidkeyIdx];
            parent->keyAray[parentMidkeyIdx] = INT_MAX;
            parent->keyNum--; tempNode->keyNum++;
            sortKeyAray(parent->keyAray, m); sortKeyAray(tempNode->keyAray, m);

            for (int k = 0; k < m; k++)
            {
                tempNode->ptrAray[k] = parent->ptrAray[k];
                parent->ptrAray[k] = NULL;
            }

            /* Merge blank node and sibling node. */
            int insertPtrIdx = 0;
            for (int l = 0; l < m; l++)
            {
                if (tempNode->ptrAray[l] != p)
                {
                    parent->ptrAray[insertPtrIdx] = tempNode->ptrAray[l];
                    insertPtrIdx++;
                }
            }

            if (relation.compare("L") == 0)
            {
                for (int i = 0; i < m; i++)
                {
                    if (sibling->ptrAray[i] == NULL)
                    {
                        sibling->ptrAray[i] = p->ptrAray[0]; p->ptrAray[0] = NULL;
                        break;
                    }
                }
            }
            else if (relation.compare("R") == 0)
            {
                int ptrLastIdx = m - 1;
                for (int i = ptrLastIdx - 1; i >= 0; i--) sibling->ptrAray[i + 1] = sibling->ptrAray[i];
                for (int j = 0; j < m; j++)
                {
                    if (p->ptrAray[j] != NULL)
                    {
                        sibling->ptrAray[0] = p->ptrAray[j]; p->ptrAray[j] = NULL;
                        break;
                    }
                }
            }

            for (int n = 0; n < tempNode->keyNum; n++)
            {
                sibling->keyAray[n] = tempNode->keyAray[n];
                sibling->keyNum++;
            }

            Node* delNode = p;
            p = parent;
            if (!parentStack.empty())
            {
                parent = parentStack.back();
                parentStack.pop_back();
            }
            else finish = true;

            delete delNode; delete tempNode;
        }
    } while (!finish);
        
    if (parent != NULL && parent->keyNum == 0)    // Tree level down.
    {
        for (int i = 0; i < m; i++)
        {
            if (parent->ptrAray[i] != NULL)
            {
                root = parent->ptrAray[i]; delete parent;
                break;
            }
        }
    }
}

void BTree::inorderBTree(Node* tree, int m)
{
    if (tree != NULL)
    {
        for (int i = 0; i < m; i++)
        {
            inorderBTree(tree->ptrAray[i], m);
            if (tree->keyAray[i] == INT_MAX || i == m - 1) break;
            else cout << tree->keyAray[i] << " ";
        }
    }
    if (tree == root) cout << endl;
}

// p의 keyAray의 원소들은 마지막 원소를 제외하고 오름차순으로 정렬돼있어야합니다.
int BTree::insertion_sort(Node*& p, int idx)
{
    int newInsertedKey = p->keyAray[idx];
    Node* newInsertedPtr = p->ptrAray[idx + 1];

    int i = idx - 1;
    for (; i >= 0 && p->keyAray[i] > newInsertedKey; i--)
    {
        p->keyAray[i + 1] = p->keyAray[i];
        p->ptrAray[i + 2] = p->ptrAray[i + 1];
        p->ptrAray[i + 1] = p->ptrAray[i];
    }
    int insertionIdx = i + 1;
    p->keyAray[insertionIdx] = newInsertedKey;
    p->ptrAray[insertionIdx] = newInsertedPtr;

    return insertionIdx;
}

void BTree::sortKeyAray(int array[], int m)
{
    vector<int> sortedKeyAray(array, array + m - 1);
    sort(sortedKeyAray.begin(), sortedKeyAray.end());
    for (int i = 0; i < sortedKeyAray.size(); i++) array[i] = sortedKeyAray[i];
}

bool BTree::existAvailSibling(Node* parent, Node* p, Node*& sib, int& parentMidIdx, int& sibDelIdx, string& rel, int m)
{
    int i = 0; for (; i < m && parent->ptrAray[i] != p; i++);
    int targetIdx = i;

    if ((targetIdx == 0) || (targetIdx == m - 1))
    {
        if (targetIdx == 0)
        {
            sib = parent->ptrAray[1]; rel = "R";
            parentMidIdx = 0; sibDelIdx = 0;
            if (parent->ptrAray[1]->keyNum - 1 < MID_IDX) return false;
            else return true;
        }
        else
        {
            sib = parent->ptrAray[m - 2]; rel = "L";
            parentMidIdx = m - 2; sibDelIdx = sib->keyNum - 1;
            if (parent->ptrAray[m - 2]->keyNum - 1 < MID_IDX) return false;
            else return true;
        }
    }
    else
    {
        /*
        if ((parent->ptrAray[targetIdx - 1]->keyNum - 1 < MID_IDX) && (parent->ptrAray[targetIdx + 1]->keyNum - 1 >= MID_IDX))    // segmentation fault!
        {
            sib = parent->ptrAray[targetIdx + 1]; rel = "R";
            parentMidIdx = targetIdx; sibDelIdx = 0;
        }
        else
        {
            sib = parent->ptrAray[targetIdx - 1]; rel = "L";
            parentMidIdx = targetIdx - 1; sibDelIdx = sib->keyNum - 1;
        }

        if ((parent->ptrAray[targetIdx - 1]->keyNum - 1 < MID_IDX) && (parent->ptrAray[targetIdx + 1]->keyNum - 1 < MID_IDX)) return false;    // segmentation fault!
        else return true;
        */

        Node* leftSibling = parent->ptrAray[targetIdx - 1]; Node* rightSibling = parent->ptrAray[targetIdx + 1];
        if (leftSibling == NULL)
        {
            sib = rightSibling; rel = "R";
            parentMidIdx = targetIdx; sibDelIdx = 0;
            if (rightSibling->keyNum - 1 < MID_IDX) return false;
            else return true;
        }
        else if (rightSibling == NULL)
        {
            sib = leftSibling; rel = "L";
            parentMidIdx = targetIdx - 1; sibDelIdx = sib->keyNum - 1;
            if (leftSibling->keyNum - 1 < MID_IDX) return false;
            else return true;
        }
        else
        {
            if (leftSibling->keyNum - 1 >= MID_IDX)
            {
                sib = leftSibling; rel = "L";
                parentMidIdx = targetIdx - 1; sibDelIdx = sib->keyNum - 1;
            }
            else
            {
                sib = rightSibling; rel = "R";
                parentMidIdx = targetIdx; sibDelIdx = 0;
            }

            if (leftSibling->keyNum - 1 < MID_IDX && rightSibling->keyNum - 1 < MID_IDX) return false;
            else return true;
        }
    }
}

int main()
{
    // m=3일 때 삽입
    BTree T = BTree(3);
    T.insertBTree(T, 3, 40); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 11); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 77); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 33); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 20); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 90); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 99); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 70); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 88); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 80); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 66); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 10); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 22); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 30); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 44); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 55); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 50); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 60); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 100); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 28); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 18); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 9); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 5); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 17); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 6); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 3); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 1); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 4); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 2); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 7); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 8); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 73); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 12); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 13); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 14); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 16); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 15); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 25); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 24); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 28); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 45); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 49); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 42); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 43); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 41); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 47); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 48); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 46); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 63); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 68); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 61); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 62); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 64); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 69); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 67); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 65); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 54); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 59); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 58); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 51); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 53); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 57); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 52); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 56); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 83); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 81); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 82); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 84); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 75); T.inorderBTree(T.root, 3);
    T.insertBTree(T, 3, 89); T.inorderBTree(T.root, 3);

    // m=3일 때 삭제
    T.deleteBTree(T, 3, 66); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 10); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 22); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 30); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 44); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 55); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 50); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 60); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 100); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 28); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 18); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 9); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 5); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 17); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 6); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 3); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 1); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 4); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 2); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 7); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 8); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 73); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 12); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 13); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 14); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 16); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 15); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 25); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 24); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 28); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 40); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 11); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 77); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 33); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 20); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 90); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 99); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 70); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 88); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 80); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 45); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 49); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 42); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 43); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 41); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 47); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 48); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 46); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 63); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 68); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 53); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 57); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 52); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 56); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 83); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 81); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 82); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 84); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 75); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 89); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 61); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 62); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 64); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 69); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 67); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 65); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 54); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 59); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 58); T.inorderBTree(T.root, 3);
    T.deleteBTree(T, 3, 51); T.inorderBTree(T.root, 3);

    // m=4일 때 삽입
    BTree T1 = BTree(4);
    T1.insertBTree(T1, 4, 40); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 11); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 77); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 33); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 20); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 90); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 99); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 70); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 88); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 80); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 66); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 10); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 22); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 30); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 44); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 55); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 50); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 60); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 100); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 28); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 18); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 9); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 5); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 17); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 6); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 3); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 1); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 4); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 2); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 7); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 8); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 73); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 12); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 13); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 14); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 16); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 15); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 25); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 24); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 28); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 45); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 49); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 42); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 43); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 41); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 47); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 48); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 46); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 63); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 68); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 61); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 62); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 64); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 69); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 67); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 65); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 54); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 59); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 58); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 51); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 53); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 57); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 52); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 56); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 83); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 81); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 82); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 84); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 75); T1.inorderBTree(T1.root, 4);
    T1.insertBTree(T1, 4, 89); T1.inorderBTree(T1.root, 4);

    // m=4일 때 삭제
    T1.deleteBTree(T1, 4, 66); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 10); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 22); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 30); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 44); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 55); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 50); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 60); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 100); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 28); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 18); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 9); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 5); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 17); T1.inorderBTree(T1.root, 4);    // segmentation fault
    T1.deleteBTree(T1, 4, 6); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 3); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 1); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 4); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 2); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 7); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 8); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 73); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 12); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 13); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 14); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 16); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 15); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 25); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 24); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 28); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 40); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 11); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 77); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 33); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 20); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 90); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 99); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 70); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 88); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 80); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 45); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 49); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 42); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 43); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 41); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 47); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 48); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 46); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 63); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 68); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 53); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 57); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 52); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 56); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 83); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 81); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 82); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 84); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 75); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 89); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 61); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 62); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 64); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 69); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 67); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 65); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 54); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 59); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 58); T1.inorderBTree(T1.root, 4);
    T1.deleteBTree(T1, 4, 51); T1.inorderBTree(T1.root, 4);

    return 0;
}