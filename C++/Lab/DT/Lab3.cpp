/***********************
Name : 이재욱
Student ID : 20181670
Lab #3
************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_STACK_SIZE = 100;

class Stack
{
    private: char stack[MAX_STACK_SIZE];
    private: int top;
    public: Stack()
    {
        top = -1;
    }
    public: void push(char exp)
    {
        stack[++top] = exp;
    }
    public: char pop()
    {
        return stack[top--];
    }
    public: bool is_full()
    {
        if (top == MAX_STACK_SIZE - 1)
        {
            return true;
        }
        else
        {
            return false;
        }   
    }
    public: bool is_empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public: void display()
    {
        for (int i=0; i<=top; i++)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

bool check_parathesis(char expression[80]);
bool match(char c1, char c2);

int main()
{
    ifstream reader;
    reader.open("lab3.txt");
    char buffer[80];
    while (reader.getline(buffer, 80))
    {
        cout << buffer << endl;
        bool validity = check_parathesis(buffer);
        if (validity)
        {
            cout << "Valid" << endl;
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }
    reader.close();
}

bool check_parathesis(char exp[80])
{
    Stack char_stack;
    for (int i=0; i<strlen(exp); i++)
    {
       // cout << "count : " << exp[i] << endl;
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            char_stack.push(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (char_stack.is_empty())
            {
                cout << "(Unbalanced paraentheses)" << endl;
                return false;
            }
            else
            {
                char temp = char_stack.pop();
                if (!match(temp, exp[i]))
                {
                    cout << "(Mismatched parentheses)" << endl;
                    return false;
                }
            }
        }
    }

    if (char_stack.is_empty())
    {
        return true;
    }
    else
    {
        cout << "(Unbalanced parantheses)" << "\n";
        return false;
    }
    char_stack.display();
}

bool match(char c1, char c2)
{
    if (c1 == '[' && c2 == ']')
    {
        return true;
    }
    else if (c1 == '{' && c2 == '}')
    {
        return true;
    }
    else if (c1 == '(' && c2 == ')')
    {
        return true;
    }
    else
    {
        return false;
    }    
}