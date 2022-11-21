from collections import deque


def evaluate(expr: list):
    operation_stack = []
    operation_prior = {'(': 0, ')': 0, '*': 1, '+': 2, '-': 2}
    postfix = deque()
    for item in expr:
        if item.isdecimal():
            postfix.append(item)
        elif item == '(':
            operation_stack.append(item)
        elif item == ')':
            while (top := operation_stack.pop()) != '(':
                postfix.append(top)
        else:
            while len(operation_stack) != 0:
                top = operation_stack[-1]
                if top != '(' and operation_prior[top] <= operation_prior[item]:
                    operation_stack.pop()
                    postfix.append(top)
                else:
                    break
            operation_stack.append(item)

    while len(operation_stack) != 0:
        item = operation_stack.pop()
        postfix.append(item)

    eval_stack = []
    while len(postfix) != 0:
        value = postfix.popleft()
        if value.isdecimal():
            eval_stack.append(int(value))
        else:
            right = eval_stack.pop()
            left = eval_stack.pop()

            if value == '+':
                eval_stack.append(left + right)
            elif value == '-':
                eval_stack.append(left - right)
            else:
                eval_stack.append(left * right)

    return eval_stack[0]


test_case = int(input())
for _ in range(test_case):
    _ = int(input())
    expressions = list(input().strip().split(" "))
    print(evaluate(expressions))
