#include <iostream>
using namespace std;

#define _BOARD_SIZE_ 8
struct Point { int x, y; };
Point directions[8] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

int chessBoard[_BOARD_SIZE_][_BOARD_SIZE_] = {0};
bool visited[_BOARD_SIZE_][_BOARD_SIZE_] = {false};

template <typename T>
void reset(T(*board)[_BOARD_SIZE_], int r, int c, T value)
{ for (int i = 0; i < r; i++) { for (int j = 0; j < c; j++) { board[i][j] = value; } } }

void printTour(int, int);
bool knightTour(Point, int, int, int);

int main()
{
    int testCases;
    cin >> testCases;
    int boardRow, boardCol, startRow, startCol;
    for (int i = 0; i < testCases; i++)
    {
        cin >> boardRow >> boardCol >> startRow >> startCol;
        startRow--; startCol--;    // 0 <= startRow < boardRow, 0 <= startCol < boardCol

        Point start = {startRow, startCol};
        chessBoard[startRow][startCol] = 1;
        visited[startRow][startCol] = true;

        int counter = 1;
        bool success = knightTour(start, boardRow, boardCol, counter);
        cout << success << endl;
        if (success) { printTour(boardRow, boardCol); }

        reset(chessBoard, boardRow, boardCol, 0);
        reset(visited, boardRow, boardCol, false);
    }
    return 0;
}

void printTour(int r, int c)
{
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << chessBoard[i][j] << " ";
            sum += chessBoard[i][j];
        }
        cout << endl;
    }
    cout << "Sum: " << sum << endl;
}

bool knightTour(Point startPoint, int row, int col, int counter)
{
    if (counter == row * col) { return true; }

    Point next;
    for (int i = 0; i < 8; i++)
    {
        next.x = startPoint.x + directions[i].x;
        next.y = startPoint.y + directions[i].y;
        if (next.x >= 0 && next.x < row && next.y >= 0 && next.y < col && !visited[next.x][next.y])
        {
            chessBoard[next.x][next.y] = counter + 1;
            visited[next.x][next.y] = true;

            if (knightTour(next, row, col, counter + 1)) { return true; }
            else { visited[next.x][next.y] = false; }
        }
    }
    return false;
}