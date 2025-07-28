import collections

# Use a dictionary for memoization in the recursive self-conjugate partition count
# Key: tuple (n, k), Value: count
memo_selfcjg_rec = {}

# (c)(i) Recursive implementation for p_k^selfcjg(n) (partitions into k distinct odd parts)
# n: the number to partition
# k: the number of distinct odd parts (hooks)
def p_selfcjg_recursive(n: int, k: int) -> int:
    # Base cases
    if k < 0 or n < 0:
        return 0  # Invalid input, no partitions possible
    if k == 0:
        return 1 if n == 0 else 0  # p_0^selfcjg(0) = 1 (empty partition), otherwise 0
    
    # Smallest sum for k distinct odd parts is k^2 (1 + 3 + ... + (2k-1))
    if n < k * k:
        return 0  # Not enough sum to form k distinct odd parts

    # Check memoization table to avoid redundant calculations
    if (n, k) in memo_selfcjg_rec:
        return memo_selfcjg_rec[(n, k)]

    # Recurrence relation: p_k^selfcjg(n) = p_k^selfcjg(n-2k) + p_{k-1}^selfcjg(n-1)
    # Term 1: Corresponds to partitions where all parts are >= 3. We subtract 2 from each of the k parts.
    # Term 2: Corresponds to partitions where the smallest part is 1. We remove 1.
    result = p_selfcjg_recursive(n - 2 * k, k) + p_selfcjg_recursive(n - 1, k - 1)

    # Store result in memoization table
    memo_selfcjg_rec[(n, k)] = result
    return result

# (c)(ii) Dynamic Programming implementation for p_k^selfcjg(n) (partitions into k distinct odd parts)
# n: the number to partition
# k: the number of distinct odd parts (hooks)
def p_selfcjg_dp_impl(n: int, k: int) -> int:
    # dp[i][j] stores p_j^selfcjg(i)
    # Initialize a 2D list (DP table) with zeros
    dp = [[0] * (k + 1) for _ in range(n + 1)]

    # Base case: p_0^selfcjg(0) = 1 (empty partition)
    dp[0][0] = 1

    # Fill the DP table using the recurrence relation
    for i in range(n + 1):  # Iterate through sums from 0 to n
        for j in range(k + 1):  # Iterate through number of parts (hooks) from 0 to k
            if i == 0 and j == 0:
                continue  # Already handled dp[0][0]

            # Pruning: Smallest sum for j distinct odd parts is j*j
            if i < j * j:
                dp[i][j] = 0
                continue

            # Term 1: p_j^selfcjg(i-2j)
            # This term is valid if i-2j is non-negative
            if i >= 2 * j:
                dp[i][j] += dp[i - 2 * j][j]
            # Term 2: p_{j-1}^selfcjg(i-1)
            # This term is valid if i-1 and j-1 are non-negative
            if i >= 1 and j >= 1:
                dp[i][j] += dp[i - 1][j - 1]
    
    return dp[n][k]  # Return the desired value

# Global list to store distinct odd partitions found for part (a)
distinct_odd_partitions_found = []

# Helper function for (a) to generate distinct odd partitions using backtracking
# target_sum: the remaining sum that needs to be partitioned
# remaining_parts: the number of parts (elements) still needed in the partition
# max_val: the maximum odd value that can be chosen for the current part
# current_partition: the partition being built (passed by reference)
def generate_distinct_odd_partitions(target_sum: int, remaining_parts: int, max_val: int, current_partition: list):
    # Base case: if no more parts are needed
    if remaining_parts == 0:
        if target_sum == 0:  # If the sum is also zero, a valid partition is found
            distinct_odd_partitions_found.append(list(current_partition)) # Append a copy
        return

    # Pruning: if the target_sum is too small to form 'remaining_parts' distinct odd integers
    # The smallest sum for 'remaining_parts' distinct odd integers is 1+3+...+(2*remaining_parts-1) = remaining_parts^2
    if target_sum < remaining_parts * remaining_parts:
        return

    # Iterate through possible odd values for the current part in decreasing order
    # 'val' must be odd and less than or equal to 'max_val' and 'target_sum'
    for val in range(min(max_val, target_sum), 0, -2): # Iterate downwards by 2 to get odd numbers
        # If the current value can be added without exceeding the target_sum
        if val <= target_sum:
            current_partition.append(val)  # Add the current value to the partition
            # Recursively call for the remaining sum and parts,
            # setting the new max_val to 'val - 2' to ensure distinctness and decreasing order
            generate_distinct_odd_partitions(target_sum - val, remaining_parts - 1, val - 2, current_partition)
            current_partition.pop()  # Backtrack: remove the current value for other possibilities

# Function for (b) to count partitions of n with an odd number of parts
# n: the number to partition
def count_partitions_odd_num_parts(n: int) -> int:
    # dp_p[i][j] stores the number of partitions of i into j parts
    # Initialize a 2D list (DP table) for standard partition function p(n,k)
    dp_p = [[0] * (n + 1) for _ in range(n + 1)]

    # Base case: partition of 0 into 0 parts is 1 (empty partition)
    dp_p[0][0] = 1

    # Fill the DP table using the standard recurrence relation for p(n,k)
    for i in range(1, n + 1):  # Iterate through sums from 1 to n
        for j in range(1, i + 1):  # Iterate through number of parts from 1 to i
            # p(i,j) = p(i-1, j-1) + p(i-j, j)
            # Term 1: p(i-1, j-1) - corresponds to partitions including at least one '1'
            dp_p[i][j] = dp_p[i - 1][j - 1]
            # Term 2: p(i-j, j) - corresponds to partitions where all parts are >= 2
            if i >= j:  # Ensure i-j is non-negative
                dp_p[i][j] += dp_p[i - j][j]

    total_odd_parts_count = 0
    # Sum up p(n,j) for all odd j (number of parts)
    for j in range(1, n + 1):
        if j % 2 != 0:  # If the number of parts (j) is odd
            total_odd_parts_count += dp_p[n][j]
    return total_odd_parts_count

# Function to print a partition in (p1,p2,...) format
def print_partition(p: list):
    print("(", end="")
    for i, val in enumerate(p):
        print(val, end="")
        if i < len(p) - 1:
            print(",", end="")
    print(")", end="")

if __name__ == "__main__":
    try:
        n = int(input("Nhap n: "))
        k = int(input("Nhap k: "))
    except ValueError:
        print("Vui long nhap so nguyen hop le.")
        exit()

    print(f"\n--- (a) Dem va liet ke so phan hoach tu lien hop cua {n} co {k} phan (hook) ---")
    distinct_odd_partitions_found.clear()  # Clear previous results before generating

    current_partition = []
    # Initial call for generating distinct odd partitions.
    # max_val is set to 'n' if n is odd, or 'n-1' if n is even, to ensure the largest possible part is odd.
    # If n is 0, max_val should be 0 to prevent infinite loop or incorrect behavior.
    initial_max_val = n if n % 2 != 0 else n - 1
    if n == 0: initial_max_val = 0
    generate_distinct_odd_partitions(n, k, initial_max_val, current_partition)

    count_selfcjg_a = len(distinct_odd_partitions_found)
    print(f"So phan hoach tu lien hop cua {n} co {k} phan (hook) la: {count_selfcjg_a}")
    print("Cac phan hoach tu lien hop (duoi dang phan hoach le phan biet tuong ung):")
    if count_selfcjg_a == 0:
        print("Khong co phan hoach nao.")
    else:
        for p in distinct_odd_partitions_found:
            print_partition(p)
            print(f" (tong = {sum(p)})")

    print(f"\n--- (b) Dem so phan hoach cua {n} co le phan, va so sanh ---")
    count_odd_num_parts = count_partitions_odd_num_parts(n)
    print(f"So phan hoach cua {n} co le phan la: {count_odd_num_parts}")
    print(f"So sanh voi p_k^selfcjg({n}) voi k={k} (tu phan a): {count_selfcjg_a}")
    if count_odd_num_parts == count_selfcjg_a:
        print("Hai so nay BANG NHAU.")
    else:
        print("Hai so nay KHAC NHAU.")

    print("\n--- (c) Thiet lap cong thuc truy hoi cho p_k^selfcjg(n) va implementation ---")

    # (c)(i) Recursive implementation with memoization
    memo_selfcjg_rec.clear()  # Clear memoization table before recursive call
    rec_result = p_selfcjg_recursive(n, k)
    print(f"\n(i) Ket qua bang de quy (co nho): p_{k}^selfcjg({n}) = {rec_result}")

    # (c)(ii) Dynamic Programming implementation
    dp_result = p_selfcjg_dp_impl(n, k)
    print(f"(ii) Ket qua bang quy hoach dong: p_{k}^selfcjg({n}) = {dp_result}")

    if rec_result == dp_result:
        print("Ket qua tu de quy va quy hoach dong KHOP NHAU.")
    else:
        print("Ket qua tu de quy va quy hoach dong KHONG KHOP NHAU. Co the co loi.")

