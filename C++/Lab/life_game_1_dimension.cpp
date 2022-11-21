#include <iostream>
using namespace std;

void makeArray(int cell[], int n);
void printArray(int bacterias[], int n);
void lifeGame(int bacterias[], int n, int k);
int main()
{
    int t, n, k;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> n >> k;

        int bacteria_cell[n];
        makeArray(bacteria_cell, n);
        lifeGame(bacteria_cell, n, k);
        printArray(bacteria_cell, n);
    }
    return 0;
}

void makeArray(int cell[], int n)
{
    int bacteria_number;
    for (int i=0; i<n; i++)
    {
        cin >> bacteria_number;
        cell[i] = bacteria_number;
    }
}
void printArray(int bacterias[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << bacterias[i] << " ";
    }
    cout << endl;    
}
void lifeGame(int bacterias[], int n, int k)
{
    for (int i=0; i<k; i++)
    {
        int *new_bacterias = new int[n];
        int j = 0;

        if (bacterias[j+1] < 3 || bacterias[j+1] > 7)
            if (bacterias[j] > 0) *(new_bacterias + j) = bacterias[j] - 1;
            else *(new_bacterias + j) = bacterias[j];
        else if (bacterias[j+1] == 3)
            *(new_bacterias + j) = bacterias[j];
        else if (bacterias[j+1] > 3 && bacterias[j+1] <= 7)
            if (bacterias[j] < 9) *(new_bacterias + j) = bacterias[j] + 1;
            else *(new_bacterias + j) = bacterias[j];
        
        j++;
        for (; j<n-1 ; j++)
        {
            int bacterias_sum = bacterias[j-1] + bacterias[j+1];

            if (bacterias_sum == 3)
            {
                *(new_bacterias + j) = bacterias[j];
                continue;
            }
            else if (bacterias_sum < 3 || bacterias_sum > 7)
                if (bacterias[j] > 0) *(new_bacterias + j) = bacterias[j] - 1;
                else *(new_bacterias + j) = bacterias[j];
            else if (bacterias_sum > 3 && bacterias_sum <= 7)
                if (bacterias[j] < 9) *(new_bacterias + j) = bacterias[j] + 1;
                else *(new_bacterias + j) = bacterias[j];
        }

        if (bacterias[j-1] < 3 || bacterias[j-1] > 7)
            if (bacterias[j] > 0) *(new_bacterias + j) = bacterias[j] - 1;
            else *(new_bacterias + j) = bacterias[j];
        else if (bacterias[j-1] == 3) *(new_bacterias + j) = bacterias[j];
        else if (bacterias[j-1] > 3 && bacterias[j-1] <= 7)
            if (bacterias[j] < 9) *(new_bacterias + j) = bacterias[j] + 1;
            else *(new_bacterias + j) = bacterias[j];

        for (int k=0; k<n; k++)
            bacterias[k] = new_bacterias[k];
        
        delete[] new_bacterias;
    }
}