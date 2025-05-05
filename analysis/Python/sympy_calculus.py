# sequences
## sources: https://docs.sympy.org/latest/modules/series/sequences.html
from sympy import sequence
from sympy.abc import n
print(sequence(n**2, (n, 0, 5))) # output: SeqFormula(n**2, (n, 0, 5))
print(sequence((1, 2, 3), (n, 0, 5))) # output: SeqPer((1, 2, 3), (n, 0, 5))

from sympy import SeqFormula
from sympy.abc import n
SeqFormula(n**2).coeff_mul(2) # output: SeqFormula(2*n**2, (n, 0, oo))

from sympy import sequence, sqrt, oo, lucas
from sympy.abc import n, x, y
sequence(n**2).find_linear_recurrence(10, 2) # output: []
sequence(n**2).find_linear_recurrence(10) # output: [3, -3, 1]
sequence(2**n).find_linear_recurrence(10) # output: [2]
sequence(23*n**4+91*n**2).find_linear_recurrence(10) # output: [5, -10, 10, -5, 1]
sequence(sqrt(5)*(((1 + sqrt(5))/2)**n - (-(1 + sqrt(5))/2)**(-n))/5).find_linear_recurrence(10) # output: [1, 1]
sequence(x+y*(-2)**(-n), (n, 0, oo)).find_linear_recurrence(30) # output: [1/2, 1/2]
sequence(3*5**n + 12).find_linear_recurrence(20,gfvar=x) # output: ([6, -5], 3*(5 - 21*x)/((x - 1)*(5*x - 1)))
sequence(lucas(n)).find_linear_recurrence(15,gfvar=x) # output: ([1, 1], (x - 2)/(x**2 + x - 1))

#-----------------------------------------------------------------------------%

# integral
## source: https://docs.sympy.org/latest/modules/integrals/integrals.html
from sympy import *
init_printing(use_unicode=False) # what for?
x = Symbol('x')
print(integrate(x**2 + x + 1, x)) # output: x**3/3 + x**2/2 + x
print(integrate(x/(x**2+2*x+1), x)) # output: log(x + 1) + 1/(x + 1)
print(integrate(x**2 * exp(x) * cos(x), x)) # output: x**2*exp(x)*sin(x)/2 + x**2*exp(x)*cos(x)/2 - x*exp(x)*sin(x) + exp(x)*sin(x)/2 - exp(x)*cos(x)/2
print(integrate(exp(-x**2)*erf(x), x)) # output: sqrt(pi)*erf(x)**2/4