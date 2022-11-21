def iteration(n):
    a, b = 1, 1 # assign 1st & 2nd values.
    sum = 0 # save value of ((n-1)th value + (n-2)th value)

    for i in range(n-2):
        sum = a + b
        a = b
        b = sum

    return sum


def recursive(n):
    if n == 1 or n == 2:
        return 1

    return recursive(n-2) + recursive(n-1)


if __name__ == '__main__':
    import time

    iteration_start = time.time()
    number1 = iteration(15)
    print(number1, time.time()-iteration_start)

    recursive_start = time.time()
    number2 = recursive(15)
    print(number2, time.time() - recursive_start)

# 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610