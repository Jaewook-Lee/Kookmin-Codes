#include <iostream>
using namespace std;

int triangleArea(const int, const int, const int, const int, const int, const int, int&);
int main()
{
    int t, ax, ay, bx, by, cx, cy, status;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        cout << triangleArea(ax, ay, bx, by, cx, cy, status); 
        cout << " " << status << endl;
        /*cout << triangleArea(ax, ay, bx, by, cx, cy, status) << " " << status << endl;
          위 처럼 하는 경우 함수 인자로 전달한 status값은 변하지만 그 후로 출력될 status는 변한 값일수도 있고
          옛날 값 그대로일 수도 있다. 주의 하자.*/
    }

    return 0;
}

int triangleArea(const int ax, const int ay, const int bx, const int by, const int cx, const int cy, int &stat)
{
    int area = ((bx - ax) * (cy - ay) - (cx - ax) * (by - ay));

    if (area == 0) stat = 0;
    else if (area > 0) stat = 1;
    else stat = -1;

    if (area < 0) area *= -1;
    
    return area;
}