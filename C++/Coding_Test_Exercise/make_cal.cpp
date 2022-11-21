// Why Rumtime Error?
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int getPrior(string);
int eval(string*, int);

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int length;
        cin >> length;
        cin.ignore();
        string expression;
        getline(cin, expression);
        string exprArray[length];
        int arrayPtr = 0;
        string item;
        for (int j = 0; j < expression.length(); j++)
        {
            if (expression[j] != ' ')
            {
                item += expression[j];
                if (j == expression.length() - 1)
                {
                    exprArray[arrayPtr++] = item;
                    item = "";
                }
            }
            else
            {
                exprArray[arrayPtr++] = item;
                item = "";
            }
        }
        cout << eval(exprArray, length) << endl;
    }
    return 0;
}

int getPrior(string item)
{
    if (item == "+" || item == "-") { return 2; }
    else if (item == "*") { return 1; }
    else { return 0; }
}

int eval(string* expr, int size)
{
    stack<string> operationStack;
    queue<string> postfix;
    for (int i = 0; i < size; i++)
    {
        if (atoi(expr[i].c_str()) != 0 || expr[i].compare("0") == 0) { postfix.push(expr[i]); }
        else if (expr[i] == "(") { operationStack.push(expr[i]); }
        else if (expr[i] == ")")
        {
            while (operationStack.top() != "(")
            {
                string operat = operationStack.top();
                operationStack.pop();
                postfix.push(operat);
            }
            operationStack.pop();
        }
        else
        {
            if (operationStack.empty() || operationStack.top() == "(") { operationStack.push(expr[i]); }
            else
            {
                while (!operationStack.empty())
                {
                    string operat = operationStack.top();
                    if (operat != "(" && getPrior(operat) <= getPrior(expr[i]))
                    {
                        operationStack.pop();
                        postfix.push(operat);
                    }
                    else { break; }
                }
                operationStack.push(expr[i]);
            }
        }
    }

    while (!operationStack.empty())
    {
        string operat = operationStack.top();
        operationStack.pop();
        postfix.push(operat);
    }

    stack<int> evalStack;
    while (!postfix.empty())
    {
        string value = postfix.front();
        postfix.pop();

        if (atoi(value.c_str()) != 0 || value.compare("0") == 0) { evalStack.push(atoi(value.c_str())); }
        else
        {
            int right = evalStack.top();
            evalStack.pop();
            int left = evalStack.top();
            evalStack.pop();

            if (value == "+") { evalStack.push(left + right); }
            else if (value == "-") { evalStack.push(left - right); }
            else { evalStack.push(left * right); }
        }
    }
    return evalStack.top();
}