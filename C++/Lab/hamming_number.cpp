#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

unsigned int hammingNum(int);
int main()
{
    int t, k;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> k;
        cout << hammingNum(k) << endl;
    }
    return 0;
}

unsigned int hammingNum(int k)
{
    vector<unsigned int> hamming_numbers; // Spaces to push hamming numbers.
    int max_range = INT_MAX; // A number to checking overflow.
    for (int i=1; ; i*=2)
    {
        if (i > (max_range / 2) - 1) break;
        for (int j=i; ; j*=3)
        {
            if (j > (max_range / 3) - 1) break;
            for (int k=j; ; k*=5)
            {
                if (k > (max_range / 5) - 1) break;
                hamming_numbers.push_back(k);
            }
        }
    }
    sort(hamming_numbers.begin(), hamming_numbers.end());

    return hamming_numbers[k - 1];
}