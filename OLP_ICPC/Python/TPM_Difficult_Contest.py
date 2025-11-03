import sys
input = lambda: sys.stdin.readline().strip()
t=int(input())
for _ in range(t):
    n = list(input())
    a = n.count('T')
    b = n.count('F')
    values_to_remove = {'T','F'}
    n = [x for x in n if x not in values_to_remove]
    s = ''.join(n)
    print(('T' * a) + ('F' * b) + s) 