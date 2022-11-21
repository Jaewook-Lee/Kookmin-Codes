# 20181670, 이재욱, Lab2

def binarySearchIteration(data, target):
    if len(data) == 0:
        return -1

    left_idx = 0
    right_idx = len(data) - 1
    status = False

    while left_idx <= right_idx:
        mid_idx = (left_idx + right_idx) // 2

        if data[mid_idx] == target:
            status = True
            return mid_idx

        elif data[mid_idx] > target:
            right_idx = mid_idx - 1
        else:
            left_idx = mid_idx + 1

    if not status:
        return -1


def binarySearchRecursive(data, target, left, right):
    if len(data) == 0:
        return -1

    if left <= right:
        mid_idx = (left + right) // 2

        if data[mid_idx] == target:
            status = True
            return mid_idx
        elif data[mid_idx] > target:
            return binarySearchRecursive(data, target, left, mid_idx - 1)
        else:
            return binarySearchRecursive(data, target, mid_idx + 1, right)
    else:
        return -1


def recursiveSum(n, m):
    if n == 0:
        return n + m
    else:
        n -= 1
        m += 1
        return recursiveSum(n, m)


def recursiveDiff(n, m):
    if n == 0:
        return n - m
    else:
        n -= 1
        m -= 1
        return recursiveDiff(n, m)


def recursiveRangeSum(n):
    if n == 1:
        return 1
    else:
        return n + recursiveRangeSum(n-1)


if __name__ == '__main__':
    # Lab2 - 1
    list = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    while True:
        find_number = int(input("Enter an integer to search : "))
        method_choose = int(input("Enter method of search : (1. Binary Search   2. Recursive Search) : "))
        position = -1 # Initiate position '-1' to break the while statement

        if method_choose == 1:
            position = binarySearchIteration(list, find_number)

            if position == -1:
                print("%d is NOT FOUND" %find_number)
            else:
                print("%d is at position %d" %(find_number, position))

        elif method_choose == 2:
            position = binarySearchRecursive(list, find_number, 0, len(list)-1)

            if position == -1:
                print("%d is NOT FOUND" % find_number)
            else:
                print("%d is at position %d" % (find_number, position))
        else:
            print("Wrong order!")

        if position == -1:
            break

    # Lab2 - 2
    a = int(input("Enter number1 : "))
    b = int(input("Enter number2 : "))
    print("Addition Result is : %d" %recursiveSum(a, b))
    print("Difference Result : %d" %recursiveDiff(a, b))

    c = int(input("Enter a number : "))
    equation = ""
    for i in range(c, 0, -1):
        if i == 1:
            equation += "%d = " %i
        else:
            equation += "%d + " %i
    print("Result is : %s%d" %(equation, recursiveRangeSum(c)))