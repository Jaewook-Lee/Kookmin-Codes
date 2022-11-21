def iteration(string):
    for i in range(len(string)-1, -1, -1):
        print(string[i], end='')

def recursive(string, size):
    if size == 0:
        return

    print(string[size-1], end='')
    recursive(string, size-1)

if __name__ == "__main__":
    iteration("wonderful")
    print()
    recursive('fantastic', 9)