t = int(input())
for _ in range(t):
    n = int(input())
   
    found = False
    max_y = n // 2021 
    for y in range(max_y + 1):
        if (n - 2021 * y) % 2020 == 0:
            found = True
            break
    print("YES" if found else "NO")