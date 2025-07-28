def is_self_conjugate(parts):
    m = len(parts)
    conjugate = [0] * m
    for i in range(m):
        for j in range(m):
            if parts[j] >= i + 1:
                conjugate[i] += 1
    return parts == conjugate

def gen_self_conjugate_partitions(n, k, max_val, curr, result):
    if k == 0 and n == 0:
        if is_self_conjugate(curr):
            result.append(curr[:])
        return
    if k <= 0 or n <= 0:
        return
    for i in range(min(max_val, n), 0, -1):
        curr.append(i)
        gen_self_conjugate_partitions(n - i, k - 1, i, curr, result)
        curr.pop()

def gen_odd_partitions(n, min_odd, curr, result):
    if n == 0:
        result.append(curr[:])
        return
    if n < 0:
        return
    for odd in range(min_odd, n + 1, 2):
        curr.append(odd)
        gen_odd_partitions(n - odd, odd, curr, result)
        curr.pop()

def count_odd_partitions(n):
    dp = [0] * (n + 1)
    dp[0] = 1
    for odd in range(1, n + 1, 2):
        for i in range(odd, n + 1):
            dp[i] += dp[i - odd]
    return dp[n]

def gen_distinct_odd_partitions(n, start, curr, result):
    if n == 0:
        result.append(curr[:])
        return
    if n < 0:
        return
    for odd in range(start, n + 1, 2):
        curr.append(odd)
        gen_distinct_odd_partitions(n - odd, odd + 2, curr, result)
        curr.pop()

n = int(input())

# Tự liên hợp
all_self_conj_parts = []
curr = []
for k in range(1, n + 1):
    gen_self_conjugate_partitions(n, k, n, curr, all_self_conj_parts)

print(f"\n=== Tổng số phân hoạch tự liên hợp của {n}: {len(all_self_conj_parts)}")
for part in all_self_conj_parts:
    print(" + ".join(map(str, part)))

# Phân hoạch toàn số lẻ
odd_parts = []
curr = []
gen_odd_partitions(n, 1, curr, odd_parts)
for part in odd_parts:
    part.sort(reverse=True)
odd_parts.sort()

print(f"\n=== Số phân hoạch của {n} có phần tử lẻ: {len(odd_parts)}")
for part in odd_parts:
    print(" + ".join(map(str, part)))

# Phân hoạch lẻ phân biệt
distinct_odd_parts = []
curr = []
gen_distinct_odd_partitions(n, 1, curr, distinct_odd_parts)
for part in distinct_odd_parts:
    part.sort(reverse=True)
distinct_odd_parts.sort()

print(f"\n=== Số phân hoạch của {n} thành các phần lẻ phân biệt: {len(distinct_odd_parts)}")
for part in distinct_odd_parts:
    print(" + ".join(map(str, part)))

# So sánh
print("\n=== So sánh:")
print(f"Tổng số phân hoạch tự liên hợp = {len(all_self_conj_parts)}")
print(f"Số phân hoạch lẻ phân biệt = {len(distinct_odd_parts)}")
if len(all_self_conj_parts) == len(distinct_odd_parts):
    print("=> Bằng nhau")
else:
    print("=> Khác nhau")