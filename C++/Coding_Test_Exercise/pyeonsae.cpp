#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int bestPyeonSae(const vector<pair<int, int>>, int, int, int*, int*);
int getL1Norm(int, int, int, int);

int main()
{
    int testCases;
    cin >> testCases;

    int size, conviCnt;
    vector<pair<int, int>> conviArray;
    for (int i = 0; i < testCases; i++)
    {
        cin >> size >> conviCnt;
        int r, c;
        for (int j = 0; j < conviCnt; j++)
        {
            cin >> r >> c;
            conviArray.push_back(make_pair(r, c));
        }

        int bestRow = -1; int bestCol = -1;
        int bestScore = bestPyeonSae(conviArray, conviCnt, size, &bestRow, &bestCol);
        printf("%d %d %d\n", bestRow, bestCol, bestScore);

        conviArray.clear();
    }
    return 0;
}

int getL1Norm(int a, int b, int c, int d)
{
    int xDistance = abs(a - c);
    int yDistance = abs(b - d);
    return xDistance + yDistance;
}

int bestPyeonSae(const vector<pair<int, int>> pConviArray, int pConviCnt, int pSize, int* row, int* col)
{
    int maxScore = 0;
    for (int i = 0; i < pSize; i++)
    {
        for (int j = 0; j < pSize; j++)
        {
            int score = 0;
            for (int k = 0; k < pConviCnt; k++)
            {
                int conviRow = pConviArray[k].first;
                int conviCol = pConviArray[k].second;

                if (i == conviRow && j == conviCol) { continue; }
                else
                {
                    int distance = getL1Norm(i, j, conviRow, conviCol);
                    if (distance <= 3) { score += 2; }
                    if (distance <= 10) { score += 1; }
                }
            }
            printf("Row: %d, Col: %d, Score: %d\n", i, j, score);

            if (score > maxScore)
            {
                maxScore = score;
                *row = i;
                *col = j;
            }
        }
    }

    return maxScore;
}