#include <iostream>
using namespace std;

void drawDiamond(const unsigned int);
int main()
{
    unsigned int t, k; // 3 <= k <= 99 인 홀 수
    cin >> t;
    for (unsigned int i=0; i<t; i++)
    {
        cin >> k;
        drawDiamond(k);
    }
}

void drawDiamond(const unsigned int k)
{
    for (unsigned int i=0; i<k; i++)
    {
        for (unsigned int j=0; j<k; j++)
        {
            if (i <= k / 2)
            {
                if (j >= k / 2 - i && j <= k / 2 + i) cout << "+";
                else cout << "*";
            }
            else
            {
                if (j > k / 2 - (k - i) && j < k / 2 + (k - i)) cout << "+";
                else cout << "*";
            }
        }
        cout << endl;
    }
}