#===============================================================================
# Origin : https://github.com/SCKIMOSU/Numerical-Analysis/blob/master/cdf.py
#===============================================================================

import numpy as np
import matplotlib.pyplot as plt

nd=np.random.randn(10000)
ra=np.int(np.floor(np.min(nd)))
rb=np.int(np.ceil(np.max(nd)))
hist, bin_left=np.histogram(nd, bins=np.arange(ra, rb+1, 1))
bin_width=(rb-ra)/np.size(bin_left)
pdf=hist/np.size(nd)
cdf=np.cumsum(pdf)
plt.figure("PDF and CDF")
# Bar()특성상 n개-1 까지만
plt.subplot(1, 2, 1)
# plt.bar(bin_edges[:-1], pdf, bin_width)
plt.bar(bin_left[:-1], pdf, bin_width)
plt.title('pdf')
plt.xlabel('normal distribution')
plt.ylabel('pdf')
plt.subplot(1, 2, 2)
plt.bar(bin_left[:-1], cdf, bin_width, facecolor='m')
plt.title('cdf')
plt.xlabel('normal distribution')
plt.ylabel('cdf')
plt.show()