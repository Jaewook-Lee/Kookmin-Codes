import numpy as np

def bisection(function, x_low, x_up):
    MAX_ITER = 100
    ES = 1.0e-4

    test = function(x_low) * function(x_up)
    if test > 0:
        print("No sign changed.")
        return [], [], [], []

    iter = 0
    x_root = x_low
    ea = 100

    while True:
        old_root = x_root
        x_root = np.float((x_low + x_up) / 2)
        iter += 1

        if x_root != 0:
            ea = np.float(np.abs(np.float(x_root) - np.float(old_root)) / np.float(x_root)) * 100
            test = function(x_low) * function(x_root)

            if test > 0:
                x_low = x_root
            elif test < 0:
                x_up = x_root
            else:
                ea = 0

            if np.int(ea < ES) | np.int(iter > MAX_ITER):
                break

    root = x_root
    fx = function(x_root)

    return root, fx, ea, iter


if __name__ == "__main__":
    f = lambda m: np.sqrt(9.81*m/0.25)*np.tanh(np.sqrt(9.81*0.25/m)*4)-36
    root, fx, ea, iter = bisection(f, 40, 200)

    print("Root :", root)
    print("f(root) :", fx)
    print("Estimated error :", ea , "(must be zero Error)")
    print("Iterated number to find root :", iter)