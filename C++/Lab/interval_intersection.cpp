#include <iostream>
using namespace std;

int lengthOfIntervalIntersection(int a, int b, int c, int d);

int main(void)
{
    int t;
    int a, b, c, d;

    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> a >> b >> c >> d;
        cout << lengthOfIntervalIntersection( a, b, c, d ) << endl;
    }

    return 0;
}

int lengthOfIntervalIntersection(int a, int b, int c, int d)
{
    int start, end;
    if (a <= c)
    {
        start = c;
    }
    else
    {
        start = a;
    }

    if (b <= d)
    {
        end = b;
    }
    else
    {
        end = d;
    }
    
    if (end - start < 0)
    {
        return -1;
    }
    else
    {
        return end - start;
    }
}