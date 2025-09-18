# model for minimal cost diet
def solve_diet(N):
	s = newSolver('Diet')
	nbF, nbN = len(N) - 2, len(N[0]) - 3
	FMin, FMax, FCost, NMin, NMax = nbN, nbN + 1, nbN + 2, nbF, nbF + 1
	f = [s.NumVar(N[i][FMin], N[i][FMax], '') for i in range(nbF)]
	for j in range(nbN):
		s.Add(N[NMin][j] <= s.Sum([f[i] * N[i][j] for i in range(nbF)]))
		s.Add(s.Sum([f[i] * N[i][j] for i in range(nbF)]) <= N[NMax][j])
	s.Minimize(s.Sum([f[i] * N[i][FCost] for i in range(nbF)]))
	rc = s.Solve()
	return rc, ObjVal(s), SolVal(f)

# utility function to create an appropriate solver instance
from ortools.linear_solver import pywraplp
def newSolver(name, integer = False):
	return pywraplp.Solver(name, pywraplp.Solver.CBC_MIXED_INTEGER_PROGRAMMING if integer else pywraplp.Solver.GLOP_LINEAR_PROGRAMMING)

# utility functions to extract values from OR-Tools objects
def SolVal(x):
	if type(x) is not list:
		return 0 if x is None else x if isinstance(x, (int, float)) else x.SolutionValue() if x.Integer() is False else int(x.SolutionValue())
	elif type(x) is list:
		return [SolVal(e) for e in x]
def ObjVal(x):
	return x.Objective().Value()	