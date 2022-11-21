#include <iostream>
using namespace std;

#define _MAX_DAYS_ 100000
int maxProfit(int[], int);

int main()
{
    int testCases;
    cin >> testCases;

    int days;
    for (int i = 0; i < testCases; i++)
    {
        cin >> days;
        int dayStocks[_MAX_DAYS_];
        for (int j = 0; j < days; j++) { cin >> dayStocks[j]; }
        int result = maxProfit(dayStocks, days);
        cout << result << endl;
    }
    return 0;
}

int maxProfit(int stockArray[], int size)
{
    int highestPrice = stockArray[size - 1];
    int profit = 0;
    for (int i = size - 1; i > -1; i--)
    {
        if (stockArray[i] > highestPrice) { highestPrice = stockArray[i]; }
        else { profit += (highestPrice - stockArray[i]); }
    }
    return profit;
}