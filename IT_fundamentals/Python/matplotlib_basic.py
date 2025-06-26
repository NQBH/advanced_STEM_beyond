import math
import matplotlib.pyplot as plt
import numpy as np
'''
fig, ax = plt.subplots()             # Create a figure containing a single Axes.
ax.plot([1, 2, 3, 4], [1, 4, 2, 3])  # Plot some data on the Axes.
# plt.show()

fig = plt.figure()             # an empty figure with no Axes
fig, ax = plt.subplots()       # a figure with a single Axes
fig, axs = plt.subplots(2, 2)  # a figure with a 2x2 grid of Axes
# a figure with one Axes on the left, and two on the right:
fig, axs = plt.subplot_mosaic([['left', 'right_top'],
                        	   ['left', 'right_bottom']])
# plt.show()
'''

x = np.linspace(-5 * math.pi, 5 * math.pi, 1000)  # Sample data.

# Note that even in the OO-style, we use `.pyplot.figure` to create the Figure.
fig, ax = plt.subplots(figsize=(5, 5), layout='constrained')
ax.plot(x, np.sin(x), label = '$sin x$') # plot of y = sin x
ax.plot(x, np.cos(x), label = '$cos x$') # plot of y = cos x
# ax.plot(x, np.tan(x), label = '$tan x$') # plot of y = tan x
# ax.plot(x, np.cot(x), label = '$cot x$') # plot of y = cot x
#ax.plot(x, x, label='linear')  # Plot some data on the Axes.
# ax.plot(x, x**2, label='quadratic')  # Plot more data on the Axes...
# ax.plot(x, x**3, label='cubic')  # ... and some more.
ax.set_xlabel('x label')  # Add an x-label to the Axes.
ax.set_ylabel('y label')  # Add a y-label to the Axes.
ax.set_title("Simple Plot")  # Add a title to the Axes.
ax.legend()  # Add a legend.
plt.show() 