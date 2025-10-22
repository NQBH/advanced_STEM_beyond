n, l, r, x = map(int, input().split())
nums = list(map(int, input().split()))

mask = 2**n - 1
dem = 0

for i in range(mask + 1):
    k = bin(i)[2:].zfill(n)
    total = 0
    A = []
    for j in range(n):
        if k[j] == '1':
            total += nums[j]
            A.append(nums[j])
    if len(A) >= 2 and l <= total <= r:
        if max(A) - min(A) >= x:
            dem += 1

print(dem)