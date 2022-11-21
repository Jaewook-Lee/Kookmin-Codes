import numpy as np
import matplotlib.pyplot as plt


m = 55
g = 9.8
cd = 0.25

# Eulor
v0 = 0
v1 = (1 - 0)*(g - cd / m * v0**2) + v0
v2 = (2 - 1)*(g - cd / m * v1**2) + v1
v3 = (3 - 2)*(g - cd / m * v2**2) + v2
v4 = (4 - 3)*(g - cd / m * v3**2) + v3

vel_eulor = [v0, v1, v2, v3, v4]

# Not Eulor(Original)
vel = []
for t in range(0, 5):
    v = np.sqrt(g * m / cd) * np.tanh(np.sqrt(g * cd / m) * t)
    vel.append(v)
time = [0, 1, 2, 3, 4]

plt.plot(time, vel, '-r<', label="Original")
plt.plot(time, vel_eulor, '-b>', label="Euler")
plt.grid(True)
plt.legend()
plt.show()