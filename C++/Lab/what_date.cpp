#include <iostream>
using namespace std;

int what_date(int date_number);
int main()
{
    int t, d;
    cin >> t;

    for (int i=0; i<t; i++)
    {
        cin >> d;
        cout << what_date(d) << endl;
    }
}

int what_date(int date_number)
{
    const int GREGORIAN = 1582;
    int total_date = 0;
    for (int i=GREGORIAN; i<date_number; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
        {
            total_date += 366;
        }
        else
        {
            total_date += 365;
        }
    }

    switch (total_date % 7)
    {
        case 0:
            return 5;
            break;
        case 1:
            return 6;
            break;
        case 2:
            return 0;
            break;
        case 3:
            return 1;
            break;
        case 4:
            return 2;
            break;
        case 5:
            return 3;
            break;
        case 6:
            return 4;
            break;
    }
}