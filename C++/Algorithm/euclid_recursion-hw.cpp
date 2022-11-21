#include <iostream>
using namespace std;

int gcd(int, int);

int main()
{
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a < b)
        {
            int tmp = b;
            b = a;
            a = tmp;
        }
        cout << gcd(a, b) << endl;
    }
    return 0;
}

int gcd(int n, int m)
{
    if (m == 0) { return n; }
    else { return gcd(m, n % m); }
}