# 이재욱, 20181670, Lab0


# Lab 0-1
def lineWordCnt(file_name):
    try:
        fileA = open(file_name, "r")
    except:
        return "I/O Error!"

    lines = fileA.readlines()
    word_sum = 0
    for line in lines:
        print(line)
        word_cnt = 1 # Because of "\n" in line.
        for ch in line:
            word_true = True # Checking if ch in word or not.
            if ch == " ":
                if word_true:
                    word_cnt += 1
                    word_true = False

        print("The number of words : %d" %word_cnt)
        word_sum += word_cnt

    print("Total Number of Words : %d" %word_sum)
    fileA.close()

# Lab 0-2
def findMinMax(int_arr):
    min_val, max_val = int_arr[0], int_arr[0]
    min_idx, max_idx = 1, 1

    for i in range(1, len(int_arr) - 1):
        if int_arr[i] < min_val:
            min_val = int_arr[i]
            min_idx = i+1
        elif int_arr[i] > max_val:
            max_val = int_arr[i]
            max_idx = i+1

    print("Minimum number is %d at %d\nMaximum number is %d at %d" %(min_val, min_idx, max_val, max_idx))


if __name__ == "__main__":
    print("[Lab 0-1]")
    lineWordCnt("lab0-1.dat")
    example_array = [10, 20, 30, 40, 70, 50, 60]
    empty_array = []
    print("[Lab 0-2]")
    findMinMax(example_array)
