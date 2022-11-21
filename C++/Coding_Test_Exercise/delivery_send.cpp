#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

#define _MAX_CITY_NUM_ 1000
#define _MAX_ROAD_NUM_ 10000
#define _MAX_WEIGHT_LIMIT_ 10000

int weightLimits[_MAX_CITY_NUM_ + 1][_MAX_CITY_NUM_ + 1] = {0};
set<int> cities[_MAX_CITY_NUM_ + 1];
bool visited[_MAX_CITY_NUM_ + 1] = {false};

bool bfs(int startPoint, int endPoint, int weight)
{
    queue<int> bfsQ;
    bfsQ.push(startPoint);
    visited[startPoint] = true;

    while (!bfsQ.empty())
    {
        int currNode = bfsQ.front();
        bfsQ.pop();

        for (auto it = cities[currNode].begin(); it != cities[currNode].end(); it++)
        {
            int nextNode = *it;
            if (!visited[nextNode] && weightLimits[currNode][nextNode] >= weight)
            {
                bfsQ.push(nextNode);
                visited[nextNode] = true;
            }
        }
    }

    if (visited[endPoint]) { return true; }
    else { return false; }
}

template <typename T>
void reset(T* arr, int size, T value)
{
    for (int i = 0; i <= size; i++) { *(arr + i) = value; }
}

void resetCities(set<int> pCities[], int size)
{
    for (int i = 0; i <= size; i++) { pCities[i].clear(); }
}

int main()
{
    int testNum;
    cin >> testNum;
    for (int i = 0; i < testNum; i++)
    {
        int cityNum;
        int roadCnt;
        int garageA;
        int garageB;
        cin >> cityNum >> roadCnt >> garageA >> garageB;

        for (int j = 0; j < roadCnt; j++)
        {
            int cityA;
            int cityB;
            int weightLimit;
            cin >> cityA >> cityB >> weightLimit;

            if (weightLimits[cityA][cityB] < weightLimit)
            {
                cities[cityA].insert(cityB);
                cities[cityB].insert(cityA);

                weightLimits[cityA][cityB] = weightLimit;
                weightLimits[cityB][cityA] = weightLimit;
            }

        }
        
        int minWeight = 1;
        int maxWeight = _MAX_WEIGHT_LIMIT_;
        int result = 0;
        while (minWeight <= maxWeight)
        {
            int midWeight = (minWeight + maxWeight) / 2;
            if (bfs(garageA, garageB, midWeight))
            {
                result = midWeight;
                minWeight = midWeight + 1;
            }
            else { maxWeight = midWeight - 1; }
            reset(visited, cityNum, false);
        }
        cout << result << endl;

        resetCities(cities, cityNum);
        for (int i = 0; i < cityNum; i++) { reset(weightLimits[i], cityNum, 0); }
    }
    return 0;
}