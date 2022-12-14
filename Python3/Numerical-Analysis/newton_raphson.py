# https://github.com/SCKIMOSU/Numerical-Analysis/blob/master/newton.py#L29

import numpy as np


def sech(x):
    return np.cosh(x) ** (-1)


def newton_raphson(func, dfunc, xr):
    maxit = 50
    es = 1.0e-5
    iter = 0

    while (1):
        xrold = xr
        xr = np.float(xr - func(xr) / dfunc(xr))
        iter = iter + 1

        if xr != 0:
            ea = np.float(np.abs((np.float(xr) - np.float(xrold)) / np.float(xr)) * 100)

        if np.int(ea <= es) | np.int(iter >= maxit):
            break

        root = xr
        fx = func(xr)
    return root, fx, ea, iter

if __name__ == '__main__':
    g = 9.81; cd = 0.25; v = 36; t = 4;
    fp = lambda m: np.sqrt(g * m / cd) * np.tanh(np.sqrt(g * cd / m) * t) - v
    dfp = lambda m: (1 / 2) * np.sqrt(g / (m * cd)) * np.tanh(np.sqrt(g * cd / m) * t) - g * t / (2 * m) * (
    sech(np.sqrt(g * cd / m) * t)) ** 2

    root, fx, ea, iter = newton_raphson(fp, dfp, 140)
    print('root weight= ', root)
    print('f(root weight, should be zero) =', fx)
    print('ea = should be less than 1.0e-4', ea)
    print('iter =', iter)