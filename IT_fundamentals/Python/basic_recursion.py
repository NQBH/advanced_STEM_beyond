n = int(input())
S = 0
# sum of 1st n positive integers S = n * (n + 1) / 2
for i in range(1, n + 1):
	S += i
# recursion -- đệ quy
def recursive_S(n, sum):
	if n < 1:
		return sum
	else:
		return recursive_S(n - 1, sum + n)

print(recursive_S(n, 0))