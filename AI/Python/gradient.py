import numpy as np

# f(x) = x^2 + 5sin x
def f(x):
	return x**2 + 5*np.sin(x)

def df(x):
	return 2*x + 5 * np.cos(x)

x = float(input())
print("f(x) = ", f(x))
print("df(x) = ", df(x))

# f(x) = x^3 + 3x^2  + 5sin x - 7cos x + \sqrt{2}e^{-2x}
def f1(x):
	return x**3 + 3*x**2 + 5*np.sin(x) - 7*np.cos(x) + np.sqrt(2)*np.exp(-2*x)
def df1(x):
	return 3*x**2 + 6*x + 5*np.cos(x) + 7*np.sin(x) - 2*np.sqrt(2)*np.exp(-2*x)
x = float(input())
print("f1(x) = ", f1(x))
print("df1(x) = ", df1(x))