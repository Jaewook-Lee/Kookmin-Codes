#include <iostream>
using namespace std;

int findMaxDiff(int n);

int main()
{
    int t, n;

    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> n;
        cout << findMaxDiff(n) << endl;
    }
}

int findMaxDiff(int n)
{
    int first_max = 0;
    int second_max = 0;
    int input;
    for (int i=0; i<n; i++)
    {
        cin >> input;
        if (input > first_max)
        {
            int temp = first_max;
            first_max = input;
            second_max = temp;
        }
        else if (input > second_max)
        {
            second_max = input;
        }
    }
    return first_max - second_max;
}