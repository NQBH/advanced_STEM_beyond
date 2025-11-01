t = int(input())
for i in range(t):
	n, a, b, c = map(int, input().split())
    sum = a + b + c
    d = n // sum * 3
    if n % sum == 0:
        print(d)
    elif n % sum <= a:
        print(d + 1)
    elif n % sum <= a + b:
        print(d + 2)
    else:
        print(d + 3)