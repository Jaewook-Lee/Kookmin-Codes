import time


# Main Function
def solution(inputs):

    # Get result by using "Quine-Mccluskey Method"
    quine_result = quineMcCluskey(inputs)
    epi_dict = {"EPI": quine_result[0], "NEPI": quine_result[1]}

    # Append epi_dict's values to a list for return answer.
    result = []
    for key in sorted(epi_dict):
        result.append(key)
        for prime_implicant in epi_dict[key]:
            result.append(prime_implicant)

    return result


# A function implementing "Quine-Mccluskey Method"
def quineMcCluskey(minterms):
    bin_numbers = ["{0:b}".format(n).zfill(minterms[0]) for n in
                   minterms[2: len(minterms)]]  # Change minterms to binary format.
    prime_implicants = getPrimeImplic(bin_numbers, minterms[0])  # Return: List
    result = divideEPI(minterms[2:len(minterms)], prime_implicants)  # Return: 2-dimension list

    return result

# Compare each of elements and change one different part to "-"
def getPrimeImplic(implicant, repeat_cnt):
    prime_implicant = implicant

    loop_trigger = True
    while(loop_trigger):
        save_list = []
        loop_trigger = False
        for i in range(len(prime_implicant) - 1):
            for j in range(i + 1, len(prime_implicant)):
                diff_cnt = 0
                diff_idx = 0
                for k in range(repeat_cnt):
                    if prime_implicant[i][k] != prime_implicant[j][k]:
                        diff_cnt += 1
                        diff_idx = k
                if diff_cnt == 1:
                    save_list.append(changeStr(prime_implicant[j], diff_idx))
                    loop_trigger = True
        if loop_trigger:
            prime_implicant = save_list

    return_list = [pi for pi in set(prime_implicant)]

    return return_list


# Find EPI and NEPI
def divideEPI(minterms_dec, prime_implic):
    chart = drawChart(minterms_dec, prime_implic)
    epi = []
    result = []
    checker_cnt = 0
    epi_idx = 0
    for i in range(len(chart[0])):
        for j in range(len(chart)):
            if chart[j][i]:
                epi_idx = j
                checker_cnt += 1
        if checker_cnt == 1:
            epi.append(prime_implic[epi_idx])
            prime_implic.remove(prime_implic[epi_idx])  # Remain NEPI.

    sorted_epi = primeImplicSort(epi)
    sorted_nepi = primeImplicSort(prime_implic)
    result.append(sorted_epi)
    result.append(sorted_nepi)
    return result


# Change different part to "-"
def changeStr(origin_str, index):
    new_str = ""
    for i in range(len(origin_str)):
        if i == index:
            new_str += "-"
        else:
            new_str += origin_str[i]

    return new_str


# Draw prime implicant chart
def drawChart(row_items, col_items):
    chart = []  # This will be a "Prime Implicant Chart"
    for i in range(len(col_items)):
        cover = [False] * len(row_items)
        all_decimals = []
        calc(col_items[i], all_decimals)  # Change minterm to number.
        for j in range(len(row_items)):
            if row_items[j] in all_decimals:
                cover[j] = True  # Check things that can cover
            else:
                cover[j] = False
        chart.append(cover)

    return chart


# Change minterm representation to decimal numbers
def calc(minterm, decimal_list):
    if minterm.count("-") == 1:
        decimal = 0
        dash_idx = -1
        for i in range(len(minterm)):
            if minterm[i] == "-":
                dash_idx = i
                continue
            else:
                decimal += 2**(len(minterm) - 1 - i) * int(minterm[i])
        decimal_list.extend([decimal, decimal + 2**(len(minterm) - 1 - dash_idx)])
    else:
        calc(minterm.replace("-", "0", 1), decimal_list)

    if minterm.count("-") == 1:
        decimal = 0
        dash_idx = -1
        for i in range(len(minterm)):
            if minterm[i] == "-":
                dash_idx = i
                continue
            else:
                decimal += 2**i * int(minterm[i])
        decimal_list.extend([decimal, decimal + 2**(len(minterm) - 1 - dash_idx)])
    else:
        calc(minterm.replace("-", "1", 1), decimal_list)

    list(set(decimal_list))

# Sort prime implicants
def primeImplicSort(prime_implicants):
    for i in range(len(prime_implicants) - 1):
        for j in range(len(prime_implicants) - 1 - i):
            cmp_1 = int(prime_implicants[j].replace("-", "2"))
            cmp_2 = int(prime_implicants[j+1].replace("-", "2"))
            if cmp_1 > cmp_2:
                tmp = prime_implicants[j]
                prime_implicants[j] = prime_implicants[j+1]
                prime_implicants[j+1] = tmp

    return prime_implicants


if __name__ == "__main__":
    start_time = time.time()
    answer = solution([3, 6, 0, 1, 2, 5, 6, 7])
    print(time.time() - start_time) # Checking running time
    print(answer)