import math
import numpy as np

# f(x) = x^2 + 5sin x
def f(x):
	return x**2 + 5*np.sin(x)

def df(x): # derivative f'(x) of f(x)
	return 2*x + 5 * np.cos(x)

x = float(input("x = "))
print("f(x) = ", f(x))
print("df(x) = ", df(x))

tol = 1e-3 # tolerance: just a small number

def gradient_descent(x0, eta): # x0: starting point, eta: learning rate
	x = [x0]
	for i in range(100):
		x_new = x[-1] - eta*df(x[-1]) # x_new: x_{t+1}, x[-1]: x_t
		if abs(df(x_new)) < tol:
			break
		x.append(x_new)
	return(x, i)

x0 = float(input("x0 = "))
eta = float(input("eta = "))
if eta <= 0:
	print("error: eta must be positive!")
else:
	print(gradient_descent(x0, eta))

# f1(x) = x^3 + 3x^2  + 5sin x - 7cos x + sqrt{2}e^{-2x}
def f1(x):
	return x**3 + 3*x**2 + 5*np.sin(x) - 7*np.cos(x) + np.sqrt(2)*np.exp(-2*x)
def df1(x):
	return 3*x**2 + 6*x + 5*np.cos(x) + 7*np.sin(x) - 2*np.sqrt(2)*np.exp(-2*x)

x = float(input("x = "))
print("f(x) = ", f(x))
print("df(x) = ", df(x))

tol = 1e-3 # tolerance: just a small number

def gradient_descent_f1(x0, eta): # x0: starting point, eta: learning rate
	x = [x0]
	for i in range(100):
		x_new = x[-1] - eta*df1(x[-1]) # x_new: x_{t+1}, x[-1]: x_t
		if abs(df1(x_new)) < tol:
			break
		x.append(x_new)
	return(x, i)

x0 = float(input("x0 = "))
eta = float(input("eta = "))
if eta <= 0:
	print("error: eta must be positive!")
else:
	print(gradient_descent_f1(x0, eta))

# f(x,y) = 2x^3y^2 + sqrt(x^3)/y + sin(x^2y) + e^{cos(xy^2)}

def f(x, y):
    return 2*x**3*y**2 + np.sqrt(x**3)/y + np.sin(x**2 * y) + np.exp(np.cos(x * y**2))

def grad_f(x, y):
    df_dx = 6*x**2 * y**2 + (3/2) * x**0.5 / y + 2*x*y * np.cos(x**2 * y) - y**2 * np.sin(x * y**2) * np.exp(np.cos(x * y**2))
    df_dy = 4*x**3 * y - np.sqrt(x**3) / y**2 + x**2 * np.cos(x**2 * y) - 2*x*y * np.sin(x * y**2) * np.exp(np.cos(x * y**2))
    return np.array([df_dx, df_dy])

x = float(input("x = "))
y = float(input("y = "))
print("f(x,y) = ", f(x,y))
print("grad f(x,y) = ", grad_f(x,y))

def gradient_descent(x0, y0, eta):
	### edit
	return None

x0 = float(input("x0 = "))
y0 = float(input("y0 = "))
eta = float(input("eta = "))
if eta <= 0:
	print("error: eta must be positive!")
else:
	print(gradient_descent_f1(x0, eta))