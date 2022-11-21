#include <iostream>
using namespace std;

int power(int, int);

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int a, n;
        cin >> a >> n;
        cout << power(a, n) % 1000 << endl;
    }
    return 0;
}

int power(int number, int cnt)
{
    if (cnt == 0) { return 1; }
    else if (cnt % 2 == 0)
    {
        int x = power(number, cnt / 2);
        return x * x % 1000;
    }
    else
    {
        int x = power(number, (cnt - 1) / 2);
        return number * x * x % 1000;
    }
}