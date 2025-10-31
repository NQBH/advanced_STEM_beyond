for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    print('YES' if a == b == c == d else 'NO')