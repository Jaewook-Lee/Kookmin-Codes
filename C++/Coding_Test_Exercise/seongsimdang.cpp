// This get 80 points! Think more test cases!
// Setting unable after all people moved.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define _GRID_SIZE_ 15
int map[_GRID_SIZE_ + 1][_GRID_SIZE_ + 1];
bool visited[_GRID_SIZE_ + 1][_GRID_SIZE_ + 1];

void findNearest(vector<pair<int, int>>, pair<int, int>, int*, int*);
int bfs(pair<int, int>, pair<int, int>, int);
int goToStore(vector<pair<int, int>>, vector<pair<int, int>>, int, int);

template <typename T>
void resetMatrix(T(*table)[_GRID_SIZE_ + 1], int size, T value)
{ for (int e = 0; e <= size; e++) { for (int f = 0; f <= size; f++) { table[e][f] = value; } } }


int main()
{
    int numCases; cin >> numCases;
    for (int a = 0; a < numCases; a++)
    {
        int gridSize, numPeople; cin >> gridSize >> numPeople;
        vector<pair<int, int>> dormitoryLoc;
        for (int b = 1; b <= gridSize; b++)
        {
            for (int c = 1; c <= gridSize; c++)
            {
                cin >> map[b][c];
                if (map[b][c] == 1) { dormitoryLoc.push_back(make_pair(b, c)); }
            }
        }

        vector<pair<int, int>> seongLoc;
        for (int d = 0; d < numPeople; d++)
        {
            int seongRow, seongCol; cin >> seongRow >> seongCol;
            seongLoc.push_back(make_pair(seongRow, seongCol));
        }

        int result = goToStore(seongLoc, dormitoryLoc, gridSize, numPeople);
        cout << result << endl;
        resetMatrix(map, gridSize, 0);
    }
    return 0;
}

void findNearest(pair<int, int> store, vector<pair<int, int>> houses, int* r, int* c)
{
    int storeRow = store.first; int storeCol = store.second;
    int minDist = __INT32_MAX__;
    int minRow, minCol; minRow = minCol = _GRID_SIZE_ + 1;
    for (int i = 0; i < houses.size(); i++)
    {
        int houseRow = houses[i].first; int houseCol = houses[i].second;
        if (map[houseRow][houseCol] == 2) { continue; }
        else
        {
            int distance = abs(storeRow - houseRow) + abs(storeCol - houseCol);
            if (distance < minDist)
            {
                minRow = houseRow; minCol = houseCol;
                minDist = distance;
            }
            else if (distance == minDist)
            {
                if (houseRow < minRow || (houseRow == minRow && houseCol < minCol))
                { minRow = houseRow; minCol = houseCol; }
            }
        }
    }
    *r = minRow; *c = minCol;
}

int bfs(pair<int, int> pStoreLoc, pair<int, int> pPersonLoc, int mapSize)
{
    resetMatrix(visited, mapSize + 1, false);

    int directions[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
    queue<pair<pair<int, int>, int>> bfsQ; bfsQ.push(make_pair(pStoreLoc, 0));
    visited[pStoreLoc.first][pStoreLoc.second] = true;

    while (!bfsQ.empty())
    {
        pair<pair<int, int>, int> currInfo = bfsQ.front(); bfsQ.pop();
        pair<int, int> currPos = currInfo.first; int currStep = currInfo.second;

        for (int j = 0; j < 4; j++)
        {
            int nextRow = currPos.first + directions[0][j];
            int nextCol = currPos.second + directions[1][j];

            if (nextRow == 0 || nextRow > mapSize || nextCol == 0 || nextCol > mapSize) { continue; }
            else if (nextRow == pPersonLoc.first && nextCol == pPersonLoc.second)
            { return currStep + 1; }
            else if (!visited[nextRow][nextCol] && map[nextRow][nextCol] != 2)
            {
                visited[nextRow][nextCol] = true;
                bfsQ.push(make_pair(make_pair(nextRow, nextCol), currStep + 1));
            }
        }
    }
    return __INT32_MAX__;
}

int goToStore(vector<pair<int, int>> storeLocs, vector<pair<int, int>> houseLocs, int pSize, int people)
{      
    queue<pair<pair<int, int>, int>> inGrid, outGrid;
    for (int g = 0; g < people; g++) { outGrid.push(make_pair(make_pair(-1, -1), g)); }

    int time = 1;
    int directions[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
    do
    {
        pair<pair<int, int>, int> personInfo; pair<int, int> storeLoc;
        int inGridSize = inGrid.size();
        for (int k = 0; k < inGridSize; k++)
        {
            personInfo = inGrid.front(); inGrid.pop();
            pair<int, int> personLoc = personInfo.first; int storeIdx = personInfo.second;
            storeLoc = storeLocs[storeIdx];

            int minMoveDirection = 4;    //0: up, 1: left, 2: right, 3: down
            int minDistance = __INT32_MAX__;
            for (int h = 0; h < 4; h++)
            {
                int nextRow = personLoc.first + directions[0][h];
                int nextCol = personLoc.second + directions[1][h];

                if ((nextRow == 0 || nextRow > pSize) || (nextCol == 0 || nextCol > pSize) || map[nextRow][nextCol] == 2)
                { continue; }
                else if (nextRow == storeLoc.first && nextCol == storeLoc.second)
                {
                    map[storeLoc.first][storeLoc.second] = 2;    //2: Unable to move here.
                    minMoveDirection = h;
                    break;
                }
                else
                {
                    int distance = bfs(storeLoc, make_pair(nextRow, nextCol), pSize);
                    if (distance < minDistance)
                    {
                        minMoveDirection = h;
                        minDistance = distance;
                    }
                }
            }

            personLoc.first += directions[0][minMoveDirection];
            personLoc.second += directions[1][minMoveDirection];

            if (personLoc.first != storeLoc.first || personLoc.second != storeLoc.second)
            { inGrid.push(make_pair(personLoc, storeIdx)); }
        }
        
        if (!outGrid.empty())
        {
            personInfo = outGrid.front(); outGrid.pop();
            pair<int, int> personLoc = personInfo.first; int storeIdx = personInfo.second;

            storeLoc = storeLocs[storeIdx];
            int livingRow, livingCol; livingRow = livingCol = -1;
            findNearest(storeLoc, houseLocs, &livingRow, &livingCol);

            inGrid.push(make_pair(make_pair(livingRow, livingCol), storeIdx));
            map[livingRow][livingCol] = 2;
        }

        time++;
    } while (!inGrid.empty());
    
    return --time;
}