#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define _MAP_SIZE_ 20
int map[_MAP_SIZE_][_MAP_SIZE_] = {0,};
vector<pair<int, int>> corpseVector, wardVector;

void showAfterTime(int, int);
void autoFillEffect(int, int, int);
void fillCorpseEffect(int, int);
void fillWardEffect(int, int);
void clearMap(int);
int findMaxTimeToFillSquare(int, int, int);
int findMaxTimeToFillDiamond(int, int, int);

int main()
{
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++)
    {
        int safeZoneSize, time;
        cin >> safeZoneSize >> time;
        clearMap(safeZoneSize);
        
        int numCorpses, numWards;
        cin >> numCorpses >> numWards;
        for (int j = 0; j < numCorpses; j++)
        {
            int corpseRow, corpseCol;
            cin >> corpseRow >> corpseCol;
            corpseVector.push_back(make_pair(corpseRow, corpseCol));
        }

        for (int k = 0; k < numWards; k++)
        {
            int wardRow, wardCol;
            cin >> wardRow >> wardCol;
            wardVector.push_back(make_pair(wardRow, wardCol));
        }

        showAfterTime(time, safeZoneSize);
        corpseVector.clear(); wardVector.clear();
    }
    return 0;
}

void clearMap(int size)
{ for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { map[i][j] = 0; } } }

void showAfterTime(int timer, int zoneSize)
{
    /* Print safe-zone after time passed. */
    fillCorpseEffect(zoneSize, timer);
    fillWardEffect(zoneSize, timer);

    for (int i = 0; i < zoneSize; i++)
    {
        for (int j = 0; j < zoneSize; j++)
        {
            cout << map[i][j];
            if (j != zoneSize - 1) { cout << " "; }
        }
        cout << endl;
    }
}

void autoFillEffect(int pZoneSize, int restTime, int value)
{
    /* Fill effect to all map in once. */
    for (int i = 0; i < pZoneSize; i++)
    {
        for (int j = 0; j < pZoneSize; j++)
        { map[i][j] += restTime * value; }
    }
}

void fillCorpseEffect(int mapSize, int pTime)
{
    /* Filling corpse effect in given time. */
    for (int i = 0; i < corpseVector.size(); i++)
    {
        pair<int, int> corpseInfo = corpseVector[i];
        int corpseRow = corpseInfo.first; int corpseCol = corpseInfo.second;
        int maxFillTime = findMaxTimeToFillSquare(corpseRow, corpseCol, mapSize);
        int restTime = pTime - maxFillTime;
        int timer = restTime > 0 ? maxFillTime : pTime;

        for (int t = 1; t <= timer; t++)
        {
            int startRow = corpseRow - t >= 0 ? corpseRow - t : 0;
            int endRow = corpseRow + t < mapSize ? corpseRow + t : mapSize - 1;
            for (int a = startRow; a <= endRow; a++)
            {
                int startCol = corpseCol - t >= 0 ? corpseCol - t : 0;
                int endCol = corpseCol + t < mapSize ? corpseCol + t : mapSize - 1;
                for (int b = startCol; b <= endCol; b++)
                { map[a][b] -= 1; }
            }
        }
        
        if (restTime > 0)
        { autoFillEffect(mapSize, restTime, -1); }
    }
}

void fillWardEffect(int mapSize, int pTime)
{
    /* Filling ward effect in given time. */
    for (int i = 0; i < wardVector.size(); i++)
    {
        pair<int, int> wardInfo = wardVector[i];
        int wardRow = wardInfo.first; int wardCol = wardInfo.second;
        int maxFillTime = findMaxTimeToFillDiamond(wardRow, wardCol, mapSize);
        int restTime = pTime - maxFillTime;
        int timer = restTime > 0 ? maxFillTime : pTime;

        for (int t = 1; t <= timer; t++)
        {
            int startRow = wardRow - t >= 0 ? wardRow - t : 0;
            int endRow = wardRow + t < mapSize ? wardRow + t : mapSize - 1;
            for (int a = startRow; a <= endRow; a++)
            {
                int startCol = wardCol - t >= 0 ? wardCol - t : 0;
                int endCol = wardCol + t < mapSize ? wardCol + t : mapSize - 1;
                for (int b = startCol; b <= endCol; b++)
                {
                    if (abs(wardRow - a) + abs(wardCol - b) <= t)
                    { map[a][b] += 1; }
                }
            }
        }
        
        if (restTime > 0)
        { autoFillEffect(mapSize, restTime, 1); }
    }
}

int findMaxTimeToFillSquare(int pRow, int pCol, int pSize)
{
    /*
    Find maximum time to filling corpse effect to all area of safe-zone.
    Return: max time to fill
    */

    int times[4] = {0,};
    times[0] = pRow; times[1] = pSize - pRow - 1;
    times[2] = pCol; times[3] = pSize - pCol - 1;

    sort(times, times + 4);
    return times[3];
}

int findMaxTimeToFillDiamond(int pRow, int pCol, int pSize)
{
    /*
    Find maximum time to filling ward effect to all area of safe-zone.
    Return: max time to fill
    */

    int times[4] = {0,};
    times[0] = pRow + pCol; times[1] = (pSize - pRow - 1) + pCol;
    times[2] = pRow + (pSize - pCol - 1); times[3] = (pSize - pRow - 1) + (pSize - pCol - 1);

    sort(times, times + 4);
    return times[3];
}