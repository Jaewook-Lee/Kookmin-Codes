#include <iostream>
using namespace std;

const int STACK_SIZE = 2;
class StaticStack
{
    private:
        char stack[STACK_SIZE];
        int top;

    public:
        StaticStack()
        {
            top = -1;
        }

        void push(int value)
        {
            if (top == STACK_SIZE - 1)
            {
                cout << "StackFull!" << endl;
            }
            else
            {
                stack[++top] = value;
            }
        }
        char pop()
        {
            if (top == -1)
            {
                cout << "StackEmpty" << endl;
            }
            else
            {
                return stack[top--];
            }
        }
        int isEmpty()
        {
            if (top == -1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int isFull()
        {
            if (top == STACK_SIZE - 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        void displayStack()
        {
            int temp;

            if (top == -1)
            {
                cout << "StackEmpty!!" << endl;
            }
            else
            {
                temp = top;
                while (temp != -1)
                {
                    if (temp == 0)
                    {
                        cout << stack[temp--] << endl;
                    }
                    else
                    {
                        cout << stack[temp--] << ", ";
                    }
                }
            }
        }
};