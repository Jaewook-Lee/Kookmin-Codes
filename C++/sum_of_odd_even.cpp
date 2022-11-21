#include <iostream>
using namespace std;

short sumCompareOddEven(long n);

int main()
{
    int t;
    long n;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> n;
        cout << sumCompareOddEven(n) << endl;
    }
}

short sumCompareOddEven(const long num)
{
    long divisor = 1;
    while (divisor <= num)
    {
        divisor *= 10;
    }
    divisor /= 10;

    long copy_num = num;
    int odd_sum = 0;
    int even_sum = 0;
    int count = 0;

    while (copy_num != 0)
    {
        count++;
        int mok = copy_num / divisor;
        if (count % 2 != 0)
        {
            odd_sum += mok;
        }
        else
        {
            even_sum += mok;
        }
        copy_num %= divisor;
        divisor /= 10;
    }

    if (odd_sum > even_sum)
    {
        return 1;
    }
    else if (odd_sum == even_sum)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}