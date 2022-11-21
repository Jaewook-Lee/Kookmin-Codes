#include <iostream>
//#include <ctime>
using namespace std;

void outputZigZag(int n, int k);

int main(void)
{
    int t;
    int n, k;

    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> n >> k;
        //clock_t start = clock();
        outputZigZag(n, k);
        //cout << clock() - start << endl;
    }

    return 0;
}

void outputZigZag(int n, int k)
{
    int sum = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            sum++;
            if(i == k - 1)
            {
                if(i % 2 == 0)
                {
                    cout << sum;
                }
                else
                {
                    cout << sum + (i - 2 * j);
                }

                if(j < i)
                {
                    cout << "*";
                }
            }
        }
    }
    cout << "\n";
}