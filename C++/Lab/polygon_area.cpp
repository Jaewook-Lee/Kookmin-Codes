#include <iostream>
using namespace std;

int nPolyArea(int);
short areaStat(int*);
int main()
{
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> n;
        int area = nPolyArea(n);
        short stat = areaStat(&area);
        cout << area << " " << stat << endl;
    }
    return 0;
}
short areaStat(int *area)
{
    if(*area > 0) return 1;
    else if(*area < 0)
    {
        *area *= -1;
        return -1;
    }
    else return 0;
}
int nPolyArea(int n)
{
    int points[2 * n], point, x_val, y_val;
    int area = 0;

    for (int i=0; i<2*n; i++)
    {
        cin >> point;
        *(points + i) = point;
    }

    int index = 0;
    for (int i=0; i<n; i++)
    {
        x_val = *(points + (index % (2 * n))) + *(points + (index + 2) % (2 * n));
        y_val = *(points + (index + 3) % (2 * n)) - *(points + (index + 1) % (2 * n));
        area += (x_val * y_val);
        index += 2;
    }

    return area;
}