#include <iostream>
#include <cmath>
using namespace std;

int kindOfTriangle(int, int, int, int, int, int);
int main()
{
    unsigned int t;
    int ax, ay, bx, by, cx, cy;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        cout << kindOfTriangle(ax, ay, bx, by, cx, cy) << endl;
    }
    
    return 0;
}

int kindOfTriangle(const int ax, const int ay, const int bx, const int by, const int cx, const int cy)
{
    unsigned int a_square, b_square, c_square; // a_square, b_square, c_square는 세 변의 길이의 제곱을 한 수를 담을 변수.
    a_square = pow(ax - bx, 2) + pow(ay - by, 2);
    b_square = pow(bx - cx, 2) + pow(by - cy, 2);
    c_square = pow(ax - cx, 2) + pow(ay - cy, 2);

    float a = sqrt(a_square), b = sqrt(b_square), c = sqrt(c_square); // a, b, c는 삼각형 세 변의 길이. a, b < c
    
    /*c를 가장 긴 변으로 설정*/
    if (a >= b && a >= c)
    {
        float temp_1 = c;
        c = a;
        a = temp_1;

        float temp_2 = c_square;
        c_square = a_square;
        a_square = temp_2;
    }
    else if (b >= a && b >= c)
    {
        float temp_1 = c;
        c = b;
        b = temp_1;

        float temp_2 = c_square;
        c_square = b_square;
        b_square = temp_2;
    }

    /*삼각형 판별*/
    if (a + b <= c) return 0;
    else
    {
        if (a_square + b_square == c_square) return 1;
        else if (a_square + b_square < c_square) return 2;
        else return 3;
    }
}