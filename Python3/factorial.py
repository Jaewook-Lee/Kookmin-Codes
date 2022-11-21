def iteration(n):
    if n == 0 or n == 1:
        return 1

    result = 1

    for i in range(2, n+1):
        result *= i

    return result


def recursive(n):
    if n == 0:
        return 1
    return n * recursive(n-1)


if __name__ == '__main__':
    import time

    iteration_start = time.time()
    result1 = iteration(30)
    print(time.time() - iteration_start, result1)

    recursive_start = time.time()
    result2 = recursive(30)
    print(time.time() - recursive_start, result2)

