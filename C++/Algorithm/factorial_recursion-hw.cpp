#include <iostream>
using namespace std;

int factorial(int);

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        cout << factorial(num) % 1000 << endl;
    }
    return 0;
}

int factorial(int n)
{
    if (n <= 1) { return 1; }
    else
    {
        int answer = n * factorial(n - 1);
        while (answer % 10 == 0) { answer /= 10; }
        return answer % 10000;
    }
}