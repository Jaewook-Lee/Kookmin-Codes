t = int(input())

for i in range(t):
    d = int(input())
    day = list(map(int, input().split()))
    benefit = 0
    day_max = day[-1]
    for j in range(d-1, -1, -1):
        if day[j] > day_max:
            day_max = day[j]
        else:
            benefit += day_max - day[j]

    print(benefit)