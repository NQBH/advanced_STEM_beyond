from math import sqrt

def ua(n):
	return (-1)**n / n

def ub(n):
	return 1 / sqrt(n)

def uc(n):
	return -1 / sqrt(n)

def ud(n):
	return (-1)**n / sqrt(n)

MAX_LOOP = 100000
epsilon = float(input())

for i in range(1, MAX_LOOP + 1):
	if abs(ua(i)) < epsilon:
		print(i) # N_epsilon
		break

for i in range(1, MAX_LOOP + 1):
	if abs(ub(i)) < epsilon:
		print(i) # N_epsilon
		break

for i in range(1, MAX_LOOP + 1):
	if abs(uc(i)) < epsilon:
		print(i) # N_epsilon
		break

for i in range(1, MAX_LOOP + 1):
	if abs(ud(i)) < epsilon:
		print(i) # N_epsilon
		break