import sys
input = lambda: sys.stdin.readline().strip()
n = int(input())
ax,ay = map(int, input().split())   # hau
bx,by = map(int, input().split())   # vua
cx,cy = map(int, input().split())   # dich      # x_cot     y_hang
if (bx < ax and cx > ax) or (bx > ax and cx < ax) or (by < ay and cy > ay) or (by > ay and cy < ay):
    print('NO')
else: print('YES')