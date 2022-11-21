#include <iostream>
#include <vector>
using namespace std;

void hanoi(int, int, int, int);

vector<int> stack;

int main()
{
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int numPlate;
        cin >> numPlate;
        hanoi(numPlate, 1, 2, 3);
        cout << endl;
        stack.clear();
    }
    return 0;
}

void hanoi(int n, int start, int mid, int end)
{
    if (n > 0)
    {
        hanoi(n - 1, start, end, mid);
        if (start == 3 || end == 3)
        {
            int topPlate = n;
            if (end == 3) { stack.push_back(topPlate); }
            else
            {
                stack.pop_back();
                topPlate = stack.size() == 0 ? 0 : stack.back();
            }
            cout << topPlate << " ";
        }
        hanoi(n - 1, mid, start, end);
    }
}