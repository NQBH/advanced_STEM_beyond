# gcd
def gcd(a, b):
	while a != b:
		if a > b:
			a = a - b
		else:
			b = b - a
	return a

# compute sum of elements of a sequence
def sum_seq(A):
	S = 0
	for i in range(len(A)):
		S = S + A[i]
	return S

# count even elements of a sequence
def count_even(A):
	count = 0
	for i in range(len(A)):
		if A[i] % 2 == 0:
			count = count + 1
	return count

# count odd elements of a sequence
def count_odd(A):
	count = 0
	for i in range(len(A)):
		if A[i] % 2 != 0:
			count = count + 1
	return count

# insertion sort
def insertion_sort(A):
	for i in range(1, len(A)):
		j = i
		while j > 0 and A[j] < A[j-1]:
			A[j], A[j-1] = A[j-1], A[i]
			j = j - 1

# compute runtime of insertion sort algorithm
from time import perf_counter
from random import randint

def seq_gen(n):
	A = []
	for i in range(n):
		A.append(randint(0, n))
		return A

n = 1000
A = seq_gen(n)
t1 = perf_counter()
insertion_sort(A)
t2 = perf_counter()
print("time: ", t2 - t1, " secs")