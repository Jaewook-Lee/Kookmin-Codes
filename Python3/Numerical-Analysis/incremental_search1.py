# https://github.com/SCKIMOSU/Numerical-Analysis/blob/master/incremental1.py

import numpy as np
import matplotlib.pyplot as plt


def incsearch(func, x_min, x_max, ns):
    x = np.linspace(x_min, x_max, ns)
    f = func(x)
    bracket_num = 0
    x_brackets = []

    for k in np.arange(np.size(x)-1):
        if np.sign(f[k]) != np.sign(f[k+1]):
            bracket_num += 1
            x_brackets.extend([x[k], x[k+1]])

    xbt = np.hstack(x_brackets)
    x_brackets = xbt.reshape(bracket_num, 2)

    return bracket_num, x_brackets

def draw():
    x = np.linspace(3, 6, 200)
    func = lambda x: np.sin(np.dot(10.0, x)) + np.cos(np.dot(3.0, x))
    f = func(x)

    plt.figure(1)
    plt.plot(x, f)
    plt.grid()
    plt.show()

if __name__ == "__main__":
    xmin = 3; xmax = 6
    ns = 200
    fp = lambda x: np.sin(np.dot(10.0, x)) + np.cos(np.dot(3.0, x))
    nb, xb = incsearch(fp, xmin, xmax, ns)

    draw()
    print("Numbers of brackets: ", nb)
    print("Root interval: ", xb)