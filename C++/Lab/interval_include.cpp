#include <iostream>
using namespace std;

int testInclusion(int a, int b, int m);

int main(void)
{
    int t;
    int a, b, m;

    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> a >> b >> m;
        cout << testInclusion( a, b, m ) << endl;
    }

    return 0;
}

int testInclusion(int a, int b, int m)
{
    int return_value = 0;
    for (;a<=b; a++)
    {
        if(m == a)
        {
            return_value = 1;
            break;
        }
    }
    
    return return_value;
}