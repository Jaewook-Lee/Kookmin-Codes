#include <iostream>
#include <string>
using namespace std;

int match(string, string);

int main()
{
    int numCases; cin >> numCases;
    for (int i = 0; i < numCases; i++)
    {
        int realPWLen, inputPWLen;
        cin >> realPWLen >> inputPWLen;
        cin.ignore();

        string real, input;
        cin >> real; cin >> input;
        int result = match(real, input);
        cout << result << endl;
    }
    return 0;
}

int match(string groundTruth, string usrInput)
{
    int matchCnt = 0; int truthIdx = 0; int inputIdx = 0;
    while (inputIdx < usrInput.length())
    {
        if (matchCnt == groundTruth.length()) { return 1; }
        else if (usrInput[inputIdx] != groundTruth[truthIdx]) { truthIdx = -1; matchCnt = 0; }
        else { matchCnt++; }

        inputIdx++; truthIdx++;
    }
    if (matchCnt == groundTruth.length()) { return 1; }
    else { return 0; }
}