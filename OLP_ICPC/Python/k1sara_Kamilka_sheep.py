t = int(input())
for test in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    print(max(a) - min(a))