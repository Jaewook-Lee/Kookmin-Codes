#include <iostream>
#include <cmath>
using namespace std;

#define _MAX_ARRAY_NUM_ 100

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int inputCnt;
        cin >> inputCnt;
        
        int arrayMaxLenStatus[_MAX_ARRAY_NUM_ + 1] = {0,};
        int arrayLenStatus[_MAX_ARRAY_NUM_ + 1] = {0,};
        int copyCnt = 0;
        for (int j = 0; j < inputCnt; j++)
        {
            int arrayNo, numData;
            cin >> arrayNo >> numData;
            int arrayLen = arrayLenStatus[arrayNo];

            if (arrayMaxLenStatus[arrayNo] < arrayLen + numData)
            {
                copyCnt += arrayLen;
                arrayMaxLenStatus[arrayNo] = pow(2, int(floor(log2(arrayLen + numData)) + 1));
            }
            arrayLenStatus[arrayNo] = arrayLen + numData;
        }
        cout << copyCnt << endl;
    }
    return 0;
}