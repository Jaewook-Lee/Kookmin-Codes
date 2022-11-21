#include <iostream>
using namespace std;

#define _MAX_LENGTH_ 100

int getLength(const char*);
void flipString(char*, int, int);

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        char input[_MAX_LENGTH_ + 1];
        cin >> input;
        int inputLen = getLength(input);
        
        flipString(input, 0, inputLen - 1);
        cout << input << endl;
    }
    return 0;
}

int getLength(const char* str)
{
    int idx = 0;
    while (*(str + idx++)) {}
    return idx - 1;
}

void flipString(char* str, int front, int end)
{
    if (front < end)
    {
        char tmp = str[front];
        str[front] = str[end];
        str[end] = tmp;
        
        flipString(str, front + 1, end - 1);
    }
}