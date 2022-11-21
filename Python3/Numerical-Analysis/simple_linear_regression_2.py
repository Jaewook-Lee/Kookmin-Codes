import numpy as np
import matplotlib.pyplot as plt

x = np.arange(10, 90, 10.)
y = np.array([25, 70, 380, 550, 610, 1220, 830, 1450])
p1 = np.polyfit(x, y, 1)
plt.figure(1)
plt.plot(x, y, 'ro', x, np.polyval(p1, x), 'b*-')
plt.grid()
plt.show()

xsum = np.sum(x)
ysum = np.sum(y)
xysum = sum(x * y)

n = np.size(x)
a1 = (n * xysum - xsum * ysum) / (n * np.sum(x**2) - xsum ** 2)
a0 = ysum / n - xsum / n * a1
print(p1)
print(a1, a0)
