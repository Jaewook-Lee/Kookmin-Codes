#include <iostream>
using namespace std;

#define _MAP_ROW_ 100
#define _MAP_COL_ 5
int racingMap[_MAP_ROW_ + 1][_MAP_COL_] = {0};
int scoreMap[_MAP_ROW_ + 1][_MAP_COL_] = {0};

int maxResult(const int, const int);
void reset(int(*)[_MAP_COL_], int);

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int row;
        cin >> row;
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < _MAP_COL_; k++)
            {
                int info;
                cin >> racingMap[j][k];
                scoreMap[j][k] = racingMap[j][k] == 1 ? 0 : racingMap[j][k];
            }
            if (j == row - 1)
            {
                scoreMap[j][0] = 0;
                scoreMap[j][_MAP_COL_ - 1] = 0;
            }
        }
        cout << maxResult(row, _MAP_COL_) << endl;
        reset(racingMap, row);
        reset(scoreMap, row);
    }
    return 0;
}

void reset(int (*board)[_MAP_COL_], int rowSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < _MAP_COL_; j++) { board[i][j] = 0; }
    }
}

int maxResult(const int rowSize, const int colSize)
{
    for (int i = rowSize - 1; i >= 0; i--)
    {
        for (int j = 0; j < colSize; j++)
        {
            if ((i == rowSize - 1 && (j == 0 || j == colSize - 1)) || racingMap[i][j] == 1) { continue; }
            else
            {
                int leftDownScore = j - 1 >= 0 ? scoreMap[i + 1][j - 1] : 0;
                int straightDownScore = scoreMap[i + 1][j];
                int rightDownScore = j + 1 < colSize ? scoreMap[i + 1][j + 1] : 0;
                int maxScore = max(leftDownScore, max(straightDownScore, rightDownScore));
                scoreMap[i][j] += maxScore;

                if (j - 1 >= 0 && racingMap[i][j - 1] == 1) { scoreMap[i][j] += 1; }
                if (j + 1 < colSize && racingMap[i][j + 1] == 1) { scoreMap[i][j] += 1; }
            }
        }
    }
    
    int totalMaxScore = scoreMap[0][0];
    for (int j = 1; j < colSize; j++)
    {
        if (scoreMap[0][j] > totalMaxScore) { totalMaxScore = scoreMap[0][j]; }
    }
    return totalMaxScore;
}