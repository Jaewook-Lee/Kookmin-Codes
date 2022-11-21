# https://github.com/SCKIMOSU/Numerical-Analysis/blob/master/Data_visualization.py

# Problem : Bungee jumpers suffered significant vertebrae injury
#           when free-fall velocity exceeds 36m/s
#           after 4 seconds fo free-fall.
#           Find out the mass that exceeds 36m/s after 4 sec.

import numpy as np
import matplotlib.pyplot as plt


g = 9.81
cd = 0.25
t = 4
v = 36

m = np.linspace(40, 200, 100)
fm = np.sqrt(g*m/cd) * np.tanh(np.sqrt(g*cd/m)*t)

plt.figure(1)
plt.plot(m, fm)
plt.grid()
plt.show()

fm1 = np.sqrt(g*m/cd) * np.tanh(np.sqrt(g*cd/m)*t) - v
k = np.linspace(0, 0, 100)

plt.figure(2)
plt.plot(m, fm1, m, k)
plt.grid()
plt.show()