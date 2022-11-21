#include <iostream>
using namespace std;

int numberOfZero(const int array[], int n);

int main(void)
{
    int t;
    int n;

    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> n;

        int num_array[n];
        for(int j=0; j<n; j++)
        {
            cin >> num_array[j];
        }
        cout << numberOfZero(num_array, n) << endl;
    }
}

int numberOfZero(const int array[], int n)
{
    int two_cnt = 0;
    int five_cnt = 0;

    int divided;
    for (int i=0; i<n; i++)
    {
        divided = array[i];
        for (int j=2; j*j<=divided; j++)
        {
            if (divided % j == 0)
            {
                divided /= j;
                if (j == 2)
                {
                    two_cnt++;
                }
                else if (j == 5)
                {
                    five_cnt++;
                }

                j = 1;
            }
        }
        if (divided == 2)
        {
            two_cnt++;
        }
        else if (divided == 5)
        {
            five_cnt++;
        }
    }

    if (two_cnt * five_cnt == 0)
    {
        return 0;
    }
    if (two_cnt <= five_cnt)
    {
        return two_cnt;
    }
    else
    {
        return five_cnt;
    }
}
