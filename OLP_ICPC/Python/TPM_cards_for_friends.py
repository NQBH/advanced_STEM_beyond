def can_cut(w, h, n):
    count = 1
    while w % 2 == 0:
        w =  w // 2
        count = count * 2
    while h % 2 == 0:
        h = h // 2
        count = count * 2
    if count >= n:
        return True
    else:
        return False
    
t = int(input())
for _ in range(t):
    w, h, n = map(int, input().split())
    if can_cut(w, h, n):
        print("YES")
    else:
        print("NO")