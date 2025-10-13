# Bài toán con ếch 
n = int(input("Nhập n: "))
power = list(map(int, input("Nhập độ cao: ").split()))

A = []
for i in range(n):
    A.append(0)

if n > 1:
    A[1] = abs(power[1] - power[0])

for i in range(2,n):
    h1 = A[i-1] + abs(power[i] - power[i-1])
    h2 = A[i-2] + abs(power[i] - power[i-2])
    A[i] = min(h1, h2)

print(A[n-1])