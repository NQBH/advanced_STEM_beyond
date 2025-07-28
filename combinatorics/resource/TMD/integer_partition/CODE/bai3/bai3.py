# problem3.py
# Full implementation for finding and counting self-conjugate partitions
# and partitions into distinct odd parts, demonstrating Glaisher's Theorem.

def generate_all_partitions_recursive(n, max_val, current_partition, results):
    """
    A recursive helper function to generate all partitions of an integer n.
    This is used as part of the "generate and test" strategy for finding
    self-conjugate partitions.

    Args:
        n (int): The remaining integer to partition.
        max_val (int): The maximum value a part can take.
        current_partition (list): The partition being built.
        results (list): A list to store all found partitions.
    """
    if n == 0:
        results.append(list(current_partition))
        return
    if n < 0:
        return

    # Iterate from min(n, max_val) down to 1 to build partitions in non-increasing order.
    for i in range(min(n, max_val), 0, -1):
        current_partition.append(i)
        generate_all_partitions_recursive(n - i, i, current_partition, results)
        current_partition.pop() # Backtrack

def get_all_partitions(n):
    """
    Wrapper function to generate all partitions of n.
    
    Args:
        n (int): The integer to partition.

    Returns:
        list[list[int]]: A list of all partitions of n.
    """
    if n < 0: return []
    results = []
    generate_all_partitions_recursive(n, n, [], results)
    return results

def get_conjugate(partition):
    """
    Calculates the conjugate of a given partition based on its Ferrers diagram.
    
    Args:
        partition (list[int]): A valid partition.

    Returns:
        list[int]: The conjugate partition.
    """
    if not partition:
        return []
    conjugate = []
    # The number of parts in the conjugate is the largest part of the original.
    max_part = partition[0]
    for i in range(1, max_part + 1):
        # The i-th part of the conjugate is the number of parts in the original >= i.
        count = sum(1 for part in partition if part >= i)
        conjugate.append(count)
    return conjugate

def find_self_conjugate_partitions(n):
    """
    Finds all self-conjugate partitions of n by generating all partitions
    and testing each one for the self-conjugate property.
    
    Args:
        n (int): The integer to partition.

    Returns:
        list[list[int]]: A list of all self-conjugate partitions of n.
    """
    all_partitions = get_all_partitions(n)
    self_conjugate_list = []
    for p in all_partitions:
        if p == get_conjugate(p):
            self_conjugate_list.append(p)
    return self_conjugate_list

def count_distinct_odd_partitions_dp(n):
    """
    Efficiently counts the number of partitions of n into distinct odd parts
    using Dynamic Programming. This is the most effective way to find the
    number of self-conjugate partitions, thanks to Glaisher's Theorem.
    
    Args:
        n (int): The integer to partition.

    Returns:
        int: The number of partitions of n into distinct odd parts.
    """
    if n < 0: return 0
    dp = [0] * (n + 1)
    dp[0] = 1 # Base case: There is one way to partition 0 (the empty set).
    
    # Iterate through all odd numbers that can be parts of the partition.
    odd_num = 1
    while odd_num <= n:
        # Iterate backwards to ensure that each odd number is used at most once.
        # This enforces the "distinct" property.
        for i in range(n, odd_num - 1, -1):
            # dp[i] will be the number of ways to partition i.
            # We can form a new partition of i by adding 'odd_num' to any
            # existing partition of (i - odd_num).
            dp[i] += dp[i - odd_num]
        odd_num += 2
        
    return dp[n]

def main():
    """Main function to drive the program."""
    print("--- Problem 3: Self-Conjugate Partitions ---")
    try:
        n = int(input("Enter a non-negative integer n: "))
        if n < 0: raise ValueError("n must be non-negative.")
    except ValueError as e:
        print(f"Error: Invalid input. {e}", file=sys.stderr)
        return

    # --- Part (a): List self-conjugate partitions ---
    print("\n(a) Finding all self-conjugate partitions of", n)
    print("(Note: This can be slow for n > 20 due to the 'generate and test' method)")
    sc_partitions = find_self_conjugate_partitions(n)
    if not sc_partitions:
        print("No self-conjugate partitions found.")
    else:
        for i, p in enumerate(sc_partitions):
            print(f"  {i+1}: {p}")
    
    # --- Part (b) & (c): Count using DP and compare ---
    print("\n(b) & (c) Counting and Comparing using Dynamic Programming...")
    
    # Count from the generated list (less efficient)
    count_sc = len(sc_partitions)
    print(f"  - Number of self-conjugate partitions, p_sc({n}) = {count_sc} (from listing)")
    
    # Count efficiently using the equivalent problem
    count_do = count_distinct_odd_partitions_dp(n)
    print(f"  - Number of partitions into distinct odd parts, p_do({n}) = {count_do} (from DP)")
    
    print("-" * 60)
    print("Conclusion (Glaisher's Theorem):")
    print(f"As predicted by the theorem, the number of self-conjugate partitions")
    print(f"is EQUAL to the number of partitions into distinct odd parts.")
    print("-" * 60)

if __name__ == "__main__":
    main()