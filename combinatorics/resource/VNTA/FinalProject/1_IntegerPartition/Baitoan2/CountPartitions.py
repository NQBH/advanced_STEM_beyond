MAX = 205

p = [[0] * MAX for _ in range(MAX)]      # p[n][k]: số phân hoạch n dùng phần tử <= k
pk = [[0] * MAX for _ in range(MAX)]     # pk[n][k]: số phân hoạch n thành đúng k phần tử

for i in range(MAX):
    p[0][i] = 1
    pk[0][i] = 1 if i == 0 else 0

for n in range(1, MAX):
    for k in range(1, MAX):
        if n >= k:
            pk[n][k] = pk[n - 1][k - 1] + pk[n - k][k]
        else:
            pk[n][k] = pk[n - 1][k - 1]

        p[n][k] = p[n][k - 1]
        if n >= k:
            p[n][k] += p[n - k][k]

n, k = map(int, input().split())

pnk = p[n][k]
pn_k1 = p[n][k - 1] if k > 0 else 0
pmax = pnk - pn_k1
pk_val = pk[n][k]

print(f"Số phân hoạch của {n} với phần tử không lớn hơn {k}: p(n,k) = {pnk}")
print(f"Số phân hoạch của {n} với phần tử lớn nhất bằng {k}: p_max(n,k) = {pmax}")
print(f"Số phân hoạch của {n} thành đúng {k} phần tử: p_k(n) = {pk_val}")

if pmax == pk_val:
    print("=> p_max(n,k) = p_k(n)")
elif pmax < pk_val:
    print("=> p_max(n,k) < p_k(n)")
else:
    print("=> p_max(n,k) > p_k(n)")