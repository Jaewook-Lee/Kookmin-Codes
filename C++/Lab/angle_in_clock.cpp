#include <iostream>
using namespace std;

int angleClock(int h, int m);

int main(void)
{
    int t;
    int h, m;

    cin >> t;

    for (int i=0; i<t; i++)
    {
        cin >> h >> m;
        cout << angleClock( h, m ) << endl;
    }

    return 0;
}

int angleClock(int h, int m)
{
    double h_angle = 30 * h + 0.5 * m;
    double m_angle = 6 * m;
    double between_angle;
    
    if (h_angle >= m_angle)
    {
        between_angle = h_angle - m_angle;
    }
    else
    {
        between_angle = m_angle - h_angle;
    }

    if (between_angle > 180)
    {
        return 360 - between_angle;
    }
    else
    {
        return between_angle;
    }
}

