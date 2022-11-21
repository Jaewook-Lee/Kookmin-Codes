#include <iostream>
using namespace std;

void decToBin(const unsigned int, int *);
unsigned int binToDec(int *);
unsigned int parityBit(const unsigned int);
int main()
{
    unsigned int t, n;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> n;
        cout << parityBit(n) << endl;
    }
}

void decToBin(const unsigned int n, int *binary_array)
{
    unsigned int divided = n;
    unsigned int index = 31;
    while (divided != 0)
    {
        int ret = divided % 2;
        *(binary_array + index) = ret;
        index--;
        divided /= 2;
    }
}
unsigned int binToDec(int *binary_array)
{
    const unsigned int MAX_INT_SIZE = 2147483648;
    unsigned int sum = 0;
    int multiplier = 1;
    for (int i=31; i>0; i--)
    {
        if (*(binary_array + i) == 1) sum += *(binary_array + i) * multiplier;
        multiplier *= 2;
    }

    if (*binary_array == 1) sum += MAX_INT_SIZE;

    return sum;
}
unsigned int parityBit(const unsigned int n)
{
    int bin[32] = {0};
    decToBin(n, bin);

    unsigned short sum = 0;
    for (int i=0; i<32; i++) sum += bin[i];
    if (sum % 2 == 0) bin[0] = 0;
    else bin[0] = 1;

    return binToDec(bin);
}