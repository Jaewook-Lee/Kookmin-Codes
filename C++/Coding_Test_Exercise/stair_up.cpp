#include <iostream>
#include <cmath>
using namespace std;

int solution(int, int);

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        int p;
        cin >> n >> p;

        if (p == 1) { cout << ceil(n / 2.0) << endl; }
        else { cout << ceil((p - 1) / 2.0) + 1 + ceil((n - (p + 1)) / 2.0) << endl; }
    }
    return 0;
}