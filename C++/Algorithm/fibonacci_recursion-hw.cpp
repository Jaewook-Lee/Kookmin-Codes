#include <iostream>
using namespace std;

int fibonacci(int);

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        cout << fibonacci(num) << endl;
    }
    return 0;
}

int fibonacci(int n)
{
    if (n <= 1) { return n; }
    else { return fibonacci(n - 1) + fibonacci(n - 2); }
}