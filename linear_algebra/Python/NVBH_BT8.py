n = int(input("Nhap n: "))

zero = [[0]*n for _ in range(n)]
I = [[1 if i==j else 0 for j in range(n)] for i in range(n)]

print("\nMa tran 0:")
for r in zero:
    print(*r)

print("\nMa tran don vi:")
for r in I:
    print(*r)
