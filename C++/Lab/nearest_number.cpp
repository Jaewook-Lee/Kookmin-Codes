#include <iostream>
using namespace std;

int closestNumber(int n, int m);

int main(void)
{
    int t;
    int n, m;

    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> n >> m;
        cout << closestNumber(n, m) << endl;
    }

    return 0;
}

int closestNumber(int n, int m)
{
    int quotient = n / m;
    int big_num, small_num, big_diff, small_diff, answer;

    if (n * m > 0)
    {
        big_num = (quotient + 1) * m;
    }
    else
    {
        big_num = (quotient - 1) * m;
    }
    small_num = quotient * m;
    
    big_diff = big_num - n;
    if (big_diff < 0)
    {
        big_diff = big_diff * -1;
    }
    small_diff = n - small_num;
    if (small_diff < 0)
    {
        small_diff = small_diff * -1;
    }

    if (small_diff < big_diff)
    {
        answer = small_num;
    }
    else
    {
        answer = big_num;
    }

    return answer; 
}