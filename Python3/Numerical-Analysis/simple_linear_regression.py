import numpy as np
import matplotlib.pyplot as plt

x = np.array([0, 1, 2, 3, 4, 5])
y = np.array([0, 0.8, 0.9, 0.1, -0.8, -1])
n = np.size(x)

#b = (n * np.sum(x * y) - (np.sum(x) * np.sum(y))) / (n * np.sum(x**2) - (np.sum(x))**2)
#a = (np.sum(y) - b * np.sum(x)) / n

p1 = np.polyfit(x, y, 1)
p2 = np.polyfit(x, y, 2)
p3 = np.polyfit(x, y, 3)

plt.figure("simple linear regression")
plt.plot(x, y, 'o')
plt.grid()
plt.plot(x, np.polyval(p1, x), 'r-')
plt.plot(x, np.polyval(p2, x), 'b--')
plt.plot(x, np.polyval(p3, x), 'm:')
plt.show()

