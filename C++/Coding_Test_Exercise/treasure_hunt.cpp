#include <iostream>
#include <string>
#include <map>
using namespace std;

#define _MAX_SIZE_ 50
string treasureMap[_MAX_SIZE_][_MAX_SIZE_];
bool visited[_MAX_SIZE_][_MAX_SIZE_][4];

void findTreasure(int, int*, int*);
void clearMap(int size)
{
    for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { treasureMap[i][j] = ""; } }
}
void clearVisited(int size)
{
    for (int i = 0; i < size; i++)
    { for (int j = 0; j < size; j++) { for (int k = 0; k < 4; k++) { visited[i][j][k] = false; } } }
}

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int mapSize;
        cin >> mapSize;
        cin.ignore();

        clearMap(mapSize); clearVisited(mapSize);
        for (int j = 0; j < mapSize; j++)
        {
            for (int k = 0; k < mapSize; k++) { cin >> treasureMap[j][k]; }
        }

        int treasureRow = -1; int treasureCol = -1;
        findTreasure(mapSize, &treasureRow, &treasureCol);
        printf("%d %d\n", treasureRow, treasureCol);
        clearMap(mapSize);
    }
    return 0;
}

void findTreasure(int pSize, int* tRow, int* tCol)
{
    // let F = 0, R = 1, B = 2, L = 3
    map<char, int> directions;
    directions.insert({'F', 0});
    directions.insert({'R', 1});
    directions.insert({'B', 2});
    directions.insert({'L', 3});

    int sRow, sCol, sDir;
    sRow = sCol = 0; sDir = 2;

    while (true)
    {
        string gridInfo = treasureMap[sRow][sCol];
        int nextDir = (sDir + directions.at(gridInfo[0])) % 4;
        int nextStep = gridInfo[1] - '0';

        // If I already went to nextDir at treasureMap[sRow][sCol] -> Treasure!
        if (visited[sRow][sCol][nextDir])
        {
            *tRow = sRow; *tCol = sCol;
            break;
        }

        visited[sRow][sCol][nextDir] = true;
        if (nextDir == 0) { sRow += nextStep; }
        else if (nextDir == 1) { sCol += nextStep; }
        else if (nextDir == 2) { sRow -= nextStep; }
        else { sCol -= nextStep; }

        sDir = nextDir;
    }
}