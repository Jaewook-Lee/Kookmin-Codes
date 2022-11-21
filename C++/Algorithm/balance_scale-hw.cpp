#include <iostream>
using namespace std;

int numWeightScales[10000001];

void setScale(int[], int, int);
int minBalancing(int*, int);

int main()
{
    int testCases;
    cin >> testCases;

    int scale[2] = {0, 0};
    for (int i = 0; i < testCases; i++)
    {
        int numGravel;
        cin >> numGravel;
        for (int j = 0; j < numGravel; j++)
        {
            int weight;
            cin >> weight;
            setScale(scale, weight, j);
        }
        
        int weightDiff = scale[0] > scale[1] ? scale[0] - scale[1] : scale[1] - scale[0];
        numWeightScales[0] = 0; numWeightScales[1] = 1;
        for (int k = 2; k <= 10000001; k++) { numWeightScales[k] = 10000000; }
        
        int weightScaleCnt = minBalancing(numWeightScales, weightDiff);
        cout << weightScaleCnt << endl;

        scale[0] = 0; scale[1] = 0;
    }
    return 0;
}

void setScale(int pScale[], int w, int n)
{
    if (n == 0) { pScale[0] += w; }
    else if (n == 1) { pScale[1] += w; }
    else if (pScale[0] <= pScale[1]) { pScale[0] += w; }
    else { pScale[1] += w; }
}

int minBalancing(int* arr, int target)
{
    int weightScales[7] = {1, 2, 5, 10, 20, 50, 100};
    for (int i = 2; i <= target; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i - weightScales[j] < 0) { break; }
            else
            {
                int idx = i - weightScales[j];
                if (*(arr + idx) + 1 < *(arr + i)) { *(arr + i) = *(arr + idx) + 1; }
            }
        }
    }

    return *(arr + target);
}