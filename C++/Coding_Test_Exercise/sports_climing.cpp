#include <iostream>
#include <queue>
using namespace std;

#define _WALL_SIZE_ 500
char wall[_WALL_SIZE_][_WALL_SIZE_];
int moves[_WALL_SIZE_][_WALL_SIZE_];
bool visited[_WALL_SIZE_][_WALL_SIZE_];

void calcMinMoves(int);
void printWall(int);

template <typename T>
void resetTable(T(*table)[_WALL_SIZE_], int size, T value)
{ for (int i= 0; i < size; i++) { for (int j = 0; j < size; j++) { table[i][j] = value; } } }

int main()
{
    int numCases; cin >> numCases;
    for (int i = 0; i < numCases; i++)
    {
        int wallSize; cin >> wallSize;
        resetTable(moves, wallSize, __INT32_MAX__); resetTable(wall, wallSize, '!');
        for (int j = 0; j < wallSize; j++) { for (int k = 0; k < wallSize; k++) { cin >> wall[j][k]; } }

        calcMinMoves(wallSize);
        printWall(wallSize);
    }
    return 0;
}

void printWall(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (moves[i][j] != __INT32_MAX__) { cout << moves[i][j]; }
            else { cout << 0; }
            cout << " ";            
        }
        cout << endl;
    }
}

void calcMinMoves(int size)
{
    // BFS!!
    resetTable(visited, size, false);

    moves[size - 1][0] = 1;
    queue<pair<pair<int, int>, int>> bfsQ; bfsQ.push(make_pair(make_pair(size - 1, 0), 1));
    visited[size - 1][0] = true;

    while (!bfsQ.empty())
    {
        pair<pair<int, int>, int> currInfo = bfsQ.front(); bfsQ.pop();
        pair<int, int> currLoc = currInfo.first; int currStep = currInfo.second;
        int currR = currLoc.first; int currC = currLoc.second;

        if (wall[currR][currC] == 'H' && currStep < moves[currR][currC]) { moves[currR][currC] = currStep; }

        // check conditions again!
        if (currR - 1 >= 0 && wall[currR - 1][currC] != 'X' && !visited[currR - 1][currC])
        {
            if (currR - 2 >= 0 && wall[currR - 1][currC] == '.' && wall[currR - 2][currC] == 'H' && !visited[currR - 2][currC])
            {
                visited[currR - 2][currC] = true;
                bfsQ.push(make_pair(make_pair(currR - 2, currC), currStep + 1));
            }
            else if (wall[currR - 1][currC] == 'H')
            {
                visited[currR - 1][currC] = true;
                bfsQ.push(make_pair(make_pair(currR - 1, currC), currStep + 1));
            }
        }
        if (currC - 1 >= 0 && wall[currR][currC - 1] != 'X' && !visited[currR][currC - 1])
        {
            if (wall[currR - 1][currC - 1] == 'H')
            { bfsQ.push(make_pair(make_pair(currR, currC - 1), currStep + 1)); }
            else
            { bfsQ.push(make_pair(make_pair(currR, currC - 1), currStep)); }
            visited[currR][currC - 1] = true;
        }
        if (currC + 1 < size && wall[currR][currC + 1] != 'X' && !visited[currR][currC + 1])
        {
            if (wall[currR - 1][currC + 1] == 'H')
            { bfsQ.push(make_pair(make_pair(currR, currC + 1), currStep + 1)); }
            else
            { bfsQ.push(make_pair(make_pair(currR, currC + 1), currStep)); }
            visited[currR][currC + 1] = true;
        }
        if (currR + 1 < size && wall[currR + 1][currC] != 'X' && !visited[currR + 1][currC])
        {
            if (currR + 2 < size && wall[currR + 2][currC] == 'H')
            {
                visited[currR + 2][currC] = true;
                bfsQ.push(make_pair(make_pair(currR + 2, currC), currStep + 1));
            }
            else
            {
                visited[currR + 1][currC] = true;
                bfsQ.push(make_pair(make_pair(currR + 1, currC), currStep + 1));
            }
        }
    }
}