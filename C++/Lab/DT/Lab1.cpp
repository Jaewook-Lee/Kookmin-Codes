#include <iostream>
using namespace std;

void cmpBinIter(int *data);
int iterSearch(int *data, int size, int num);
int recSearch(int *data, int start_idx, int size, int num);
void recAdd(int n, int m);
void recDiff(int n, int m);
void recSum(int k);
int main()
{
    int raw_data[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    cmpBinIter(raw_data);
    cout << "\n";

    int num1, num2;
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number : ";
    cin >> num2;
    recAdd(num1, num2);
    recDiff(num1, num2);

    int num3;
    cout << "Enter a number : ";
    cin >> num3;
    cout << "Result is : ";
    recSum(num3);
}

void cmpBinIter(int *data)
{
    int target;
    int choice;
    while (true)
    {
        cout << "Enter an integer to search : ";
        cin >> target;
        cout << "Enter an method of search(1. Binary\t2. Recursive Binary) : ";
        cin >> choice;

        int position;
        switch (choice)
        {
            case 1:
                position = iterSearch(data, 10, target);
                break;
            case 2:
                position = recSearch(data, 0, 9, target);
                break;
            default:
                cout << "Wrong command." << endl;
                continue;
        }

        if (position == -1)
            {
                cout << target << " is NOT FOUND.\n";
                break;
            }
        else
            cout << target << " is at position " << position << endl;
    }
}
int iterSearch(int *data, int size, int target)
{
    int low_idx = 0, high_idx = size - 1;
    while (low_idx <= high_idx)
    {
        int mid_idx = (low_idx + high_idx) / 2;

        if (data[mid_idx] == target)
            return mid_idx;
        else if (data[mid_idx] > target)
            high_idx = mid_idx - 1;
        else
            low_idx = mid_idx + 1;
    }
    return -1;
}
int recSearch(int *data, int low_idx, int high_idx, int target)
{
    int mid_idx = (low_idx + high_idx) / 2;
    if (low_idx <= high_idx)
    {
        if (data[mid_idx] == target)
            return mid_idx;
        else if (data[mid_idx] > target)
            return recSearch(data, low_idx, mid_idx - 1, target);
        else
            return recSearch(data, mid_idx + 1, high_idx, target);
    }
    else
        return -1;
}

void recAdd(int n, int m)
{
    if (n == 0)
        cout << "Addition Result is : " << m << endl;
    else
        recAdd(n-1, m+1);
}
void recDiff(int n, int m)
{
    if (n == 0)
        cout << "Difference Result is : " << m << endl;
    else
        recDiff(n-1, m-1);
}
void recSum(int k)
{
    static int sum = 0;
    sum += k;

    if (k == 1)
        cout << k << " = " << sum << endl;
    else
    {
        cout << k << " + "; 
        recSum(k-1);
    }
}