import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = input()
    if ord(n[0]) < ord(n[1]): print(((ord(n[0])-97)*25) + (ord(n[1]) - 97))
    else: print(((ord(n[0]) - 97)*25) + (ord(n[1]) - 96))