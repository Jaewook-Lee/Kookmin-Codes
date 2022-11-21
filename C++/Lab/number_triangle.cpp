#include<iostream>
using namespace std;

void numberTriangle(int);

int main()
{
    unsigned int t, k;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> k;
        numberTriangle(k);
    }
}
void numberTriangle(const int k)
{
    for (int i=0; i<k; i++)
    {
        cout << i+1 << " ";
        int next_number = i+1;
        for (int j=0; j<i; j++)
        {
            next_number = next_number + k - j - 1;
            cout << next_number << " ";
        }
        cout << endl;
    }
}