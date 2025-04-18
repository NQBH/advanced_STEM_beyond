# compute sum of 1st n naturals
def recursive_sum(n, sum):
	if n < 1:
		return sum
	else:
		return recursive_sum(n - 1, sum + n)

n = int(input("n = "))
print(recursive_sum(n, 0))

# compute factorial n!
def recursive_factorial(n):
	if n == 0:
		return 1
	return n * recursive_factorial(n - 1)

n = int(input("n = "))
print(recursive_factorial(n))

# for give positive integer n, compute 2!, 3!,..., n!
def iterative_factorial(n):
	ans = 1
	for i in range(2, n + 1):
		ans *= i
	return ans

n = int(input("n = "))
for i in range(n + 1):
	print(i, iterative_factorial(i))

# print Fibonacci sequence of length n
def fib(n):
	if n == 0:
		return 0
	if n == 1:
		return 1
	else:
		return fib(n - 1) + fib(n - 2)

n = int(input("n = "))

## print nth Fibonacci element
print(n, "th Fibonacci element = ", fib(n))

## print Fibonacci sequence of length n
elements = [str(fib(x)) for x in range(1, n + 1)]
print("Fibonacci sequence of length ", n, ":",",".join(elements))