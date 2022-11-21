/*****************************************************************************************
 * 이름 : 이재욱
 * 학번 : 20181670
 * 숙제 번호 : HW #2
 * 설명 : 이 프로그램은 과제 수행을 위해 작성됐습니다.
 *        이 프로그램은 목적은 데이터 파일을 읽어서 얻은 수식을 출력하고
 *        수식을 postfix형태로 변환해 그 수식을 출력한 후
 *        계산의 결과를 출력하는 것입니다.
 * 알고리즘 : 'infix-to-postfix algorithm' & 'postfix evaluation algorithm'을 사용합니다.
 *           'char3-Stack and Queue.pdf'의 7~9번 슬라이드에 적혀 있습니다.
 * 함수들 :
 *     main() : 데이터 한 줄 씩 읽어 출력한 후, postfix형태로 바뀐 수식을 출력하고
 *              계산 결과도 출력합니다.
 *     postfix() : 한 줄의 식을 인자로 받아 postfix 형태로 바꿉니다.
 *     priority_compare() : 연산자 두 개를 인자로 받아 두 연산자 사이의 우선순위를 비교합니다.
 *                          첫 번째 인자의 우선순위가 작으면 true, 아니면 false를 반환합니다.
 *     eval() : postfix 형태의 식을 인자로 받아 식의 연산을 통해 결과를 얻어냅니다.
 *              이 함수는 결과 값을 반환합나다.
 * **************************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;

void postfix(string &expression);
bool priority_compare(char c1, char c2);
double eval(string pf_expression);

/**********************************************************************************
 * 함수 : main
 * 설명 : 수식들이 담긴 "echo.txt" 파일을 읽어 세 가지를 출력합니다.
 *     1. 원래 수식 (infix 형태)
 *     2. 변형된 수식 (postfix 형태)
 *     3. 수식의 연산 결과
 * 변수들 :
 *     reader : 파일의 식들을 읽기 위해 사용되는 변수
 *     buffer : reader를 통해 얻어온 식을 저장하기 위해 사용되는 변수
 *     expression : buffer의 내용을 바탕으로 만든 문자열이 저장되는 변수
 *                  처음은 원래의 식이 담겨 있고 나중에는 변형된 식이 담겨 있습니다.
 *     result : 식의 연산 결과를 저장하기 위해 사용되는 변수
 * ********************************************************************************/
int main()
{
    ifstream reader;
    reader.open("echo.txt"); // echo.txt 파일에 infix 식들이 있습니다.
    char buffer[80];
    while (reader.getline(buffer, 80))
    {
        cout << "1) Echo data (infix form) : " << buffer << endl;
        string expression(buffer);
        string *exp = &expression;
        postfix(*exp);
        cout << "2) Conversion (postfix form) : " << expression << endl;
        double result = eval(expression);
        cout << "3) Result : " << result << endl;
        cout << "---------------------------------------------------" << endl;
    }
    reader.close();
}

/*****************************************************************************
 * 함수 : postfix
 * 설명 : infix 형태의 식 한 줄을 인자로 받아 postfix 형태의 식으로 변환합니다.
 * 변수들 :
 *        brackets : 연산자들을 담아 놓을 스택입니다.
 *        postfix_expression : postfix 형태로 바뀌는 식을 저장할 변수입니다.
 * ***************************************************************************/
void postfix(string &exp)
{
    stack<char> brackets;
    string postfix_expression;
    for (int i=0; i<exp.length(); i++)
    {
        if (exp[i] == ' ') // 빈 칸을 무시합니다.
        {
            continue;
        }

        if (48 <= (int)exp[i] && (int)exp[i] <= 57) // (int)'0' = 48, (int)'1' = 49, ...
        {
            postfix_expression += exp[i];
        }
        else if (exp[i] == '(')
        {
            brackets.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (brackets.top() != '(')
            {
                postfix_expression += brackets.top();
                brackets.pop();
            }
            brackets.pop();
        }
        else
        {
            // 스택이 빈 경우, 비교 과정 없이 바로 스택에 올리기 위해 조건문을 추가했습니다.
            if (brackets.empty())
            {
                brackets.push(exp[i]);
                continue;
            }
            if (!priority_compare(brackets.top(), exp[i]))
            {
                postfix_expression += brackets.top();
                brackets.pop();
            }
            brackets.push(exp[i]);
        }
    }
    while (!brackets.empty())
    {
        postfix_expression += brackets.top();
        brackets.pop();
    }
    exp = postfix_expression;
}

/*****************************************************************************
 * 함수 : priority_compare
 * 설명 : 두 연산자 사이의 우선 순위를 비교합니다.
 *        첫 번째 인자의 우선 순위가 두 번째 인자보다 작거나 같으면 true,
 *        아니면 false를 반환합니다.
 * 변수들 :
 *        operators : 나올 수 있는 모든 연산자를 담아 놓은 배열입니다.
 *        priority : operators 안에 담긴 연산자들의 순서에 맞춰
 *                   우선 순위를 저장한 배열입니다.
 *        lprior, rprior : 우선 순위를 저장할 정수형 변수입니다.
 *                         lprior는 첫 번째 연산자의 우선순위를
 *                         rprior는 두 번째 연산자의 우선순위를 저장합니다.
 * ***************************************************************************/
bool priority_compare(char c1, char c2)
{
    char operators[6] = {'(', '+', '-', '*', '/', ')'};
    int priority[6] = {0, 1, 1, 2, 2, 3};
    int lprior, rprior;
    for (int i=0; i<6; i++)
    {
        if (operators[i] == c1)
        {
            lprior = priority[i];
        }
        if (operators[i] == c2)
        {
            rprior = priority[i];
        }
    }
    if (lprior < rprior)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*****************************************************************************
 * 함수 : eval
 * 설명 : postfix 형태의 식 한 줄을 인자로 받아 식의 연산을 통해 결과를 구합니다.
 *        결과 값을 반환합니다.
 * 변수들 :
 *        operands : 숫자들을 쌓아 올릴 스택입니다.
 *        sub_result : 두 피연산자 사이의 연산을 수행한 결과를 담는 변수입니다.
 *        operand1, operand2 : 스택의 탑 포인터가 가리키는 피연산자를 저장하는
 *                             변수입니다.
 * ***************************************************************************/
double eval(string pf_exp)
{
    stack<double> operands;
    for (int i=0; i<pf_exp.length(); i++)
    {
        double sub_result;
        if (48 <= (int)pf_exp[i] && (int)pf_exp[i] <= 57)
        {
            operands.push((int)pf_exp[i] - 48); // (int)'0' = 48, (int)'1' = 49, ...
        }
        else
        {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();
            if (pf_exp[i] == '+')
            {
                sub_result = operand1 + operand2;
            }
            else if (pf_exp[i] == '-')
            {
                sub_result = operand1 - operand2;
            }
            else if (pf_exp[i] == '*')
            {
                sub_result = operand1 * operand2;
            }
            else if (pf_exp[i] == '/')
            {
                sub_result = operand1 / operand2;
            }
            operands.push(sub_result);
        }
    }
    return operands.top();
}
