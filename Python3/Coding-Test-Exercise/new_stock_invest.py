test_cases = int(input())
for _ in range(test_cases):
    days = int(input())
    day_stocks = list(map(int, input().split()))

    highest_price = day_stocks[-1]
    profit = 0
    for i in range(days - 1, -1, -1):
        if day_stocks[i] > highest_price:
            highest_price = day_stocks[i]
        else:
            profit += (highest_price - day_stocks[i])

    print(profit)