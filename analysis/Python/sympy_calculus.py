# source: https://docs.sympy.org/latest/modules/integrals/integrals.html
from sympy import *
init_printing(use_unicode=False) # what for?
x = Symbol('x')
print(integrate(x**2 + x + 1, x)) # output: x**3/3 + x**2/2 + x
print(integrate(x/(x**2+2*x+1), x)) # output: log(x + 1) + 1/(x + 1)
print(integrate(x**2 * exp(x) * cos(x), x)) # output: x**2*exp(x)*sin(x)/2 + x**2*exp(x)*cos(x)/2 - x*exp(x)*sin(x) + exp(x)*sin(x)/2 - exp(x)*cos(x)/2
print(integrate(exp(-x**2)*erf(x), x)) # output: sqrt(pi)*erf(x)**2/4