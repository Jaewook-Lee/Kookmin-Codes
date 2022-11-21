#include <iostream>
using namespace std;

void drawSandClock(const unsigned int);
int main()
{
    unsigned int t, k;
    cin >> t;
    for (unsigned int i=0; i<t; i++)
    {
        cin >> k;
        drawSandClock(k);
    }
}

void drawSandClock(const unsigned int k)
{
    for (unsigned int i=0; i<k; i++)
    {
        for (unsigned int j=0; j<k; j++)
        {
            if (i <= k / 2) // Printing half of sand clock.
            {
                if ( j < i || j >= k - i) cout << "-";
                else
                {
                    if ((j + i) % 2 == 0) cout << "*";
                    else cout << "+";    
                }
            }
            else // Printing rest of sand clock.
            {
                if (j > i || j < k - i - 1) cout << "-";
                else
                {
                    if ((j + i) % 2 == 0) cout << "*";
                    else cout << "+";    
                }
            }
        }
        cout << endl;
    }
}