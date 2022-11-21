# https://github.com/SCKIMOSU/Numerical-Analysis/blob/master/incremental.py

import numpy as np


def incsearch(func, x_min, x_max):
    x = np.arange(x_min, x_max+1)
    f = func(x)
    bracket_num = 0
    x_brackets = []

    for k in np.arange(np.size(x)-1):
        if np.sign(f[k]) != np.sign(f[k+1]):
            bracket_num += 1
            x_brackets.extend([x[k], x[k+1]])

    return bracket_num, x_brackets


if __name__ == "__main__":
    g = 9.81
    m = 68.1
    cd = 0.25
    v = 36
    t = 4

    fp = lambda mp: np.sqrt(g * np.asarray(mp) / cd) * np.tanh(np.sqrt(g * cd / np.asarray(mp)) * t) - v
    nb, xb = incsearch(fp, 1, 200)
    print("Numbers of brackets: ", nb)
    print("Root interval: ", xb)