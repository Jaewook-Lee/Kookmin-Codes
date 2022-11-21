#include <iostream>
using namespace std;

struct Line
{
    int x1, x2, y1, y2;
    string status = "";
    public:
        Line(int a, int b, int c, int d) : x1(a), x2(c), y1(b), y2(d) // Making x1 < x2 and y1 < y2
        {
            if (b < d || a < c)
            {
                x1 = a;
                y1 = b;
                x2 = c;
                y2 = d;
            }
            else
            {
                x1 = c;
                y1 = d;
                x2 = a;
                y2 = b;
            }
        }
};

void verticalOrHorizontal(Line &a, Line &b);
int findIntersection (const Line &c, const Line &d);
int main()
{
    int t, x1, y1, x2, y2, a1, b1, a2, b2;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        Line line_1(x1, y1, x2, y2);

        cin >> a1 >> b1 >> a2 >> b2;
        Line line_2(a1, b1, a2, b2);

        verticalOrHorizontal(line_1, line_2);
        cout << findIntersection(line_1, line_2) << endl;
    }
}

void verticalOrHorizontal(Line &a, Line &b)
{
    if ((a.x1 == a.x2) && (a.y1 != a.y2)) a.status = "vertical";
    else if ((a.x1 != a.x2) && (a.y1 == a.y2)) a.status = "horizontal";

    if ((b.x1 == b.x2) && (b.y1 != b.y2)) b.status = "vertical";
    else if ((b.x1 != b.x2) && (b.y1 == b.y2)) b.status = "horizontal";
}
int findIntersection(const Line &c, const Line &d)
{
    if (c.status == "vertical")
    {
        if (((d.x1 == c.x1 || d.x2 == c.x1) && (d.y1 >= c.y1 && d.y1 <= c.y2)) || (c.x1 >= d.x1 && c.x1 <= d.x2) && (c.y1 == d.y1 || c.y2 == d.y1)) return 2;
        else if ((d.y1 > c.y1 && d.y1 < c.y2) && (d.x1 < c.x1 && d.x2 > c.x1)) return 1;
        else return 0;
    }
    else if (c.status == "horizontal")
    {
        if (((d.y1 == c.y1 || d.y2 == c.y1) && (d.x1 >= c.x1 && d.x1 <= c.x2)) || ((c.y1 >= d.y1 && c.y1 <= d.y2) && (c.x1 == d.x1 || c.x2 == d.x1))) return 2;
        else if ((d.x1 > c.x1 && d.x1 < c.x2) && (d.y1 < c.y1 && d.y2 > c.y1)) return 1;
        else return 0;
    }
}