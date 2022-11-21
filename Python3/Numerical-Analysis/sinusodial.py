import numpy as np
import matplotlib.pyplot as plt

Fs = 150.0
Ts = 1.0 / Fs

t = np.arange(0, 1, Ts)

ff = 5
y = np.sin(2 * np.pi * ff * t)
y1 = np.cos(2 * np.pi * ff * t)

plt.subplot(2, 1, 1)
plt.plot(t, y, "b.")
plt.xlabel("time")
plt.ylabel("sin(t)")
plt.grid()

plt.subplot(2, 1, 2)
plt.plot(t, y1, "r*")
plt.xlabel("time")
plt.ylabel("cos(t)")
plt.grid()

plt.show()