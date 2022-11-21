#include <iostream>
using namespace std;

int kindOfTriangle(int, int, int);
int main()
{
    int t, a, b, c;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> a >> b >> c;
        cout << kindOfTriangle(a, b, c) << endl;
    }
}

int kindOfTriangle(const int a, const int b, const int c)
{
    if (a + b <= c) return 0;
    else
    {
        if (a * a + b * b == c * c) return 2;
        else if ((a != c && a == b) || (a != b && b == c)) return 3;
        else if (a == c) return 1;
        else return 4;
    }
}