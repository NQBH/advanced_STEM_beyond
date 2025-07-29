def is_self_conjugate(partition):
    max_len = max(partition)
    conjugate = []

    for i in range(1, max_len + 1):
        count = 0
        for val in partition:
            if val >= i:
                count += 1
            else:
                break
        conjugate.append(count)

    return conjugate == partition


def generate_self_conjugate_partitions(n, k=None):
    result = []

    def backtrack(remaining, curr, max_val):
        if remaining == 0:
            if k is None or len(curr) == k:
                sorted_part = sorted(curr, reverse=True)
                if is_self_conjugate(sorted_part):
                    result.append(sorted_part)
            return
        for i in range(min(remaining, max_val), 0, -1):
            curr.append(i)
            backtrack(remaining - i, curr, i)
            curr.pop()

    backtrack(n, [], n)
    return result


def generate_odd_partitions(n):
    result = []

    def backtrack(remaining, curr, min_odd):
        if remaining == 0:
            result.append(curr.copy())
            return
        for i in range(min_odd, remaining + 1, 2):
            curr.append(i)
            backtrack(remaining - i, curr, i)
            curr.pop()

    backtrack(n, [], 1)
    return result


# (c.i) De quy
def p_k_selfconj_recursive(n, k, memo={}):
    key = (n, k)
    if key in memo:
        return memo[key]
    if n == 0 and k == 0:
        return 1
    if n <= 0 or k <= 0:
        return 0

    count = 0

    def backtrack(remaining, parts_left, curr, max_val):
        nonlocal count
        if remaining == 0 and parts_left == 0:
            sorted_part = sorted(curr, reverse=True)
            if is_self_conjugate(sorted_part):
                count += 1
            return
        if remaining <= 0 or parts_left <= 0:
            return
        for i in range(min(remaining, max_val), 0, -1):
            curr.append(i)
            backtrack(remaining - i, parts_left - 1, curr, i)
            curr.pop()

    backtrack(n, k, [], n)
    memo[key] = count
    return count


# (c.ii) Quy hoach dong
def p_k_selfconj_dp(n, k):
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 1

    for sum_val in range(1, n + 1):
        for parts in range(1, min(k, sum_val) + 1):
            count = 0

            def backtrack(remaining, parts_left, curr, max_val):
                nonlocal count
                if remaining == 0 and parts_left == 0:
                    sorted_part = sorted(curr, reverse=True)
                    if is_self_conjugate(sorted_part):
                        count += 1
                    return
                if remaining <= 0 or parts_left <= 0:
                    return
                for i in range(min(remaining, max_val), 0, -1):
                    curr.append(i)
                    backtrack(remaining - i, parts_left - 1, curr, i)
                    curr.pop()

            backtrack(sum_val, parts, [], sum_val)
            dp[sum_val][parts] = count

    return dp[n][k]

if __name__ == "__main__":
    n = int(input("Nhap n (so can phan hoach): "))
    k = int(input("Nhap k (so phan cua tu lien hop): "))

    # (a) Dem va in cac phan hoach tu lien hop co k phan
    print(f"\n(a) Cac phan hoach tu lien hop cua {n} co {k} phan:")
    sc_parts = generate_self_conjugate_partitions(n, k)
    for p in sc_parts:
        print("  ", p)
    print(f"=> So phan hoach tu lien hop p_k^selfcjg({n},{k}) = {len(sc_parts)}")

    # (b) So sanh voi so phan hoach co so luong phan tu la so le
    odd_parts = generate_odd_partitions(n)
    print(f"\n(b) So phan hoach cua {n} co so luong phan la so le:")
    for p in odd_parts:
        print("  ", p)
    print(f"=> Tong cong co {len(odd_parts)} phan hoach co so phan le")

    # (c.i) De quy
    res_recursive = p_k_selfconj_recursive(n, k)
    print(f"\n(c.i) Tinh bang de quy: p_k^selfcjg({n},{k}) = {res_recursive}")

    # (c.ii) Quy hoach dong
    res_dp = p_k_selfconj_dp(n, k)
    print(f"(c.ii) Tinh bang quy hoach dong: p_k^selfcjg({n},{k}) = {res_dp}")