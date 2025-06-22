n = int(input())
P = 0 # probability of derangement P(n) = !n / n! = \sum_{i=0}^n (-1)^i / i!
factorial = 1 # store i!
for i in range(2, n + 1):
	factorial *= i # i!
	P += (-1) ** (i % 2) / factorial
print(P)