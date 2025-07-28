from typing import List

def is_self_conjugate(parts: List[int]) -> bool:
    m = len(parts)
    conjugate = []
    max_part = max(parts) if parts else 0

    for i in range(1, max_part + 1):
        cnt = 0
        for val in parts:
            if val >= i:
                cnt += 1
            else:
                break
        conjugate.append(cnt)

    if len(conjugate) != len(parts):
        return False
    for i in range(len(parts)):
        if parts[i] != conjugate[i]:
            return False
    return True


# (i) Đệ quy
memo_recursive = {}

def p_selfcjg_recursive(n, k):
    if n == 0 and k == 0:
        return 1
    if n < 0 or k <= 0 or k > n:
        return 0

    key = (n, k)
    if key in memo_recursive:
        return memo_recursive[key]

    count = 0
    current = []

    def generate(remain, parts, max_val):
        nonlocal count
        if parts == 0 and remain == 0:
            temp = sorted(current, reverse=True)
            if len(temp) == k and is_self_conjugate(temp):
                count += 1
            return
        if parts <= 0 or remain <= 0:
            return
        for val in range(min(max_val, remain), 0, -1):
            current.append(val)
            generate(remain - val, parts - 1, val)
            current.pop()

    generate(n, k, n)
    memo_recursive[key] = count
    return count


# (ii) Quy hoạch động
def p_selfcjg_dp(n, k):
    if n == 0 and k == 0:
        return 1
    if n < 0 or k <= 0 or k > n:
        return 0

    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 1

    for total in range(1, n + 1):
        for parts in range(1, min(k, total) + 1):
            count = 0
            current = []

            def generate(remain, curr_parts, max_val):
                nonlocal count
                if curr_parts == 0 and remain == 0:
                    temp = sorted(current, reverse=True)
                    if len(temp) == parts and is_self_conjugate(temp):
                        count += 1
                    return
                if curr_parts <= 0 or remain <= 0:
                    return
                for val in range(min(max_val, remain), 0, -1):
                    current.append(val)
                    generate(remain - val, curr_parts - 1, val)
                    current.pop()

            generate(total, parts, total)
            dp[total][parts] = count

    return dp[n][k]

n, k = map(int, input().split())

memo_recursive.clear()
res_rec = p_selfcjg_recursive(n, k)
print(f"Số phân hoạch tự liên hợp của {n} có {k} phần (Đệ quy): {res_rec}")

res_dp = p_selfcjg_dp(n, k)
print(f"Số phân hoạch tự liên hợp của {n} có {k} phần (DP): {res_dp}")