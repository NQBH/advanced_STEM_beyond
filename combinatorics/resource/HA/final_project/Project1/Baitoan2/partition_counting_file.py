import sys

def count_partitions_with_max_part(n, k):
    if k > n:
        return 0
    if k == n:
        return 1
    if k == 0:
        return 0
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 1
    for i in range(1, n + 1):
        for j in range(1, min(k, i) + 1):
            for prev in range(j + 1):
                if i - j >= 0:
                    dp[i][j] += dp[i - j][prev]
    return dp[n][k]

def count_partitions_with_k_parts(n, k):
    if k > n:
        return 0
    if k == 1:
        return 1
    if k == n:
        return 1
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 1
    for i in range(1, n + 1):
        for j in range(1, min(k, i) + 1):
            dp[i][j] += dp[i - 1][j - 1]
            if i - j >= 0:
                dp[i][j] += dp[i - j][j]
    return dp[n][k]

def print_partitions_with_max_part(n, k, current=None, s=0, max_used=0):
    if current is None:
        current = []
    if s == n:
        if max_used == k:
            print("  " + " + ".join(map(str, current)))
        return
    for i in range(1, k + 1):
        if s + i <= n:
            current.append(i)
            print_partitions_with_max_part(n, k, current, s + i, max(max_used, i))
            current.pop()

def print_partitions_with_k_parts(n, k, current=None, s=0, parts=0):
    if current is None:
        current = []
    if parts == k:
        if s == n:
            print("  " + " + ".join(map(str, current)))
        return
    start = 1 if not current else current[-1]
    for i in range(start, n - s + 1):
        if s + i <= n and parts + 1 <= k:
            current.append(i)
            print_partitions_with_k_parts(n, k, current, s + i, parts + 1)
            current.pop()

def process_test_case(n, k):
    print(f"\n=== TEST CASE: n = {n}, k = {k} ===")
    p_max_nk = count_partitions_with_max_part(n, k)
    print(f"p_max({n},{k}) = {p_max_nk}")
    p_k_n = count_partitions_with_k_parts(n, k)
    print(f"p_{k}({n}) = {p_k_n}")
    print("\n=== COMPARISON ===")
    if p_max_nk == p_k_n:
        print(f"p_max({n},{k}) = p_{k}({n})")
        print(f"p_max({n},{k}) = p_{k}({n}) = {p_max_nk}")
    else:
        print(f"p_max({n},{k}) != p_{k}({n})")
        print(f"p_max({n},{k}) = {p_max_nk}")
        print(f"p_{k}({n}) = {p_k_n}")
    if n <= 10 and k <= 5:
        print("\n=== PARTITION DETAILS ===")
        print(f"\nPartitions of {n} with maximum part {k}:")
        print_partitions_with_max_part(n, k)
        print(f"\nPartitions of {n} into exactly {k} parts:")
        print_partitions_with_k_parts(n, k)
    print("\n" + "=" * 50)

def main():
    print("=== PROBLEM 2: INTEGER PARTITION COUNTING ===")
    print("Reading input from file 'input.txt'...")
    try:
        with open("input.txt") as f:
            lines = f.readlines()
    except FileNotFoundError:
        print("Error: Cannot open input.txt!")
        n, k = map(int, input("Please enter n and k manually: ").split())
        process_test_case(n, k)
        print("\n=== SUMMARY ===")
        print("Processed 1 test case(s).")
        return
    test_count = 0
    for line in lines:
        if not line.strip():
            continue
        n, k = map(int, line.strip().split())
        test_count += 1
        process_test_case(n, k)
    print("\n=== SUMMARY ===")
    print(f"Processed {test_count} test case(s).")

if __name__ == "__main__":
    main()