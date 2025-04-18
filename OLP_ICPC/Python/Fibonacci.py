# naive Fibonacci
def fib(n):
	if n == 0:
		return 0
	if n == 1:
		return 1
	else:
		return fib(n - 1) + fib(n - 2)

n = int(input("n = "))
elements = [str(fib(x)) for x in range(1, n + 1)]
print("Fibonacci sequence of length ", n, ":",",".join(elements))