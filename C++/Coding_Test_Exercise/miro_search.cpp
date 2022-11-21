#include <iostream>
#include<string>
#include <queue>
using namespace std;

#define _MAX_ROW_NUM_ 100
#define _MAX_COL_NUM_ 100

void reset(bool[][_MAX_COL_NUM_], int, int, bool);
int bfs(const int[][_MAX_COL_NUM_], bool[][_MAX_COL_NUM_], int, int);

int main()
{
    int map[_MAX_ROW_NUM_][_MAX_COL_NUM_];
    bool visited[_MAX_ROW_NUM_][_MAX_COL_NUM_];

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        int m;
        cin >> n >> m;

        for (int j = 0; j < n; j++)
        {
            string rowInfo;
            cin >> rowInfo;

            for (int k = 0; k < m; k++) { map[j][k] = rowInfo[k] - '0'; }
        }
        reset(visited, n, m, false);
        cout << bfs(map, visited, n, m) << endl;
    }
    return 0;
}

void reset(bool check[][_MAX_COL_NUM_], int row, int col, bool value)
{
    for (int i = 0; i < row; i++) { for (int j = 0; j < col; j++) { check[i][j] = value; } }
}

int bfs(const int miro[][_MAX_COL_NUM_], bool check[][_MAX_COL_NUM_], int row, int col)
{
    queue<pair<pair<int, int>, int>> bfsQ;
    bfsQ.push(make_pair(make_pair(0, 0), 1));
    int finalMove;
    
    while (!bfsQ.empty())
    {
        pair<pair<int, int>, int> coordInfo = bfsQ.front();
        bfsQ.pop();
        int currRow  = coordInfo.first.first;
        int currCol = coordInfo.first.second;
        int currMove = coordInfo.second;
        check[currRow][currCol] = true;

        if (currRow == row - 1 && currCol == col - 1)
        {
            finalMove = currMove;
            break;
        }

        pair<pair<int, int>, int> newInfo;
        if (currRow - 1 >= 0 && miro[currRow - 1][currCol] == 1)
        {
            if (!check[currRow - 1][currCol])
            {
                newInfo = make_pair(make_pair(currRow - 1, currCol), currMove + 1);
                bfsQ.push(newInfo);
            }
        }
        if (currRow + 1 < row && miro[currRow + 1][currCol] == 1)
        {
            if (!check[currRow + 1][currCol])
            {
                newInfo = make_pair(make_pair(currRow + 1, currCol), currMove + 1);
                bfsQ.push(newInfo);
            }
        }
        if (currCol - 1 >= 0 && miro[currRow][currCol - 1] == 1)
        {
            if (!check[currRow][currCol - 1])
            {
                newInfo = make_pair(make_pair(currRow, currCol - 1), currMove + 1);
                bfsQ.push(newInfo);
            }
        }
        if (currCol + 1 < col && miro[currRow][currCol + 1] == 1)
        {
            if (!check[currRow][currCol + 1])
            {
                newInfo = make_pair(make_pair(currRow, currCol + 1), currMove + 1);
                bfsQ.push(newInfo);
            }
        }
    }
    return finalMove;
}