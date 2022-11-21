def iteration(data, target):
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


def recursive(data, target, left, right):
    if len(data) == 0:
        return -1

    status = False

    if left <= right:
        mid_idx = (left + right) // 2

        if data[mid_idx] == target:
            status = True
            return mid_idx
        elif data[mid_idx] > target:
            return recursive(data, target, left, mid_idx - 1)
        else:
            return recursive(data, target, mid_idx + 1, right)

    if not status:
        return -1


if __name__ == '__main__':
    import time

    num_data = [i for i in range(1, 10000001)]
    iteration_start = time.time()
    location1 = iteration(num_data, 999)
    print(time.time() - iteration_start, location1)

    recursive_start = time.time()
    location2 = recursive(num_data, 999, 0, len(num_data)-1)
    print(time.time() - recursive_start, location2)

