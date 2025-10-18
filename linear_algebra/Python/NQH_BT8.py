n = int(input("Nhap n (so nguyen duong): "))

zero = [[0 for _ in range(n)] for _ in range(n)]
 
I = [row[:] for row in zero] 
for i in range(n):
        I[i][i] = 1
print(f"\nMa tran 0 ({n}x{n}):")
for row in zero:
        print(*row)

print(f"\nMa tran don vi ({n}x{n}):")
for row in I:
        print(*row)
