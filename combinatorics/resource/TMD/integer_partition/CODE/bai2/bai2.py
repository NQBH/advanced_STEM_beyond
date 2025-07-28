# problem2.py
# Full implementation for counting partitions of n where the largest part is k,
# and comparing it to the number of partitions of n into k parts.
# The core of the program is an efficient Dynamic Programming solution.

import sys

def count_partitions_dp(n, k):
    """
    Counts the number of partitions of n into exactly k parts using Dynamic Programming.
    Based on the identity p_k(n) = p_{k-1}(n-1) + p_k(n-k).
    This value is also proven to be equal to p_max(n, k), the number of partitions
    of n where the largest part is k.

    Args:
        n (int): The integer to partition.
        k (int): The number of parts (which also corresponds to the largest part).

    Returns:
        int: The number of partitions, p_k(n) or p_max(n, k).
    """
    # Basic validation: if k is larger than n, no partition is possible (since parts are positive).
    # Also handles negative inputs gracefully.
    if n < 0 or k < 0 or k > n:
        # The only exception is n=0, k=0, which will be handled by the base case.
        if n == 0 and k == 0:
            pass
        else:
            return 0

    # dp[i][j] will store the number of partitions of integer 'i' into exactly 'j' parts.
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    
    # Base case: There is one way to partition 0 into 0 parts (the empty partition).
    dp[0][0] = 1

    # Fill the DP table in a bottom-up manner.
    for i in range(1, n + 1):
        for j in range(1, k + 1):
            # A number 'i' cannot be partitioned into more parts than its value.
            if i < j:
                continue
            
            # This is the recurrence relation p_k(n) = p_{k-1}(n-1) + p_k(n-k).
            # It translates to dp[i][j] = dp[i-1][j-1] + dp[i-j][j].
            
            # Case 1: Partitions where the smallest part is 1.
            # If we remove this part, we are left with partitioning (i-1) into (j-1) parts.
            val1 = dp[i-1][j-1]
            
            # Case 2: Partitions where the smallest part is > 1.
            # If we subtract 1 from each of the j parts, we are left with partitioning (i-j) into j parts.
            val2 = dp[i-j][j]
            
            dp[i][j] = val1 + val2
            
    return dp[n][k]

def main():
    """
    Main function to drive the program. It gets user input, calculates the
    number of partitions, and prints the result along with the mathematical explanation.
    """
    print("--- Problem 2: Counting Partitions by Largest Part ---")
    try:
        n_str = input("Enter the integer to partition (n): ")
        k_str = input("Enter the value of the largest part (k): ")
        n = int(n_str)
        k = int(k_str)
        if n < 0 or k < 0: 
            raise ValueError("n and k must be non-negative integers.")
    except ValueError as e:
        print(f"Error: Invalid input. {e}", file=sys.stderr)
        return

    print("-" * 60)
    print("Mathematical Analysis Result:")
    print("The number of partitions of n with the largest part k, p_max(n, k)")
    print("  is EQUAL to")
    print("The number of partitions of n into exactly k parts, p_k(n).")
    print("This program calculates this value using Dynamic Programming.")
    print("-" * 60)

    # Calculate the value using the DP function.
    result = count_partitions_dp(n, k)
    
    # Print the final, unified result.
    print(f"The value for p_max({n}, {k}) = p_k({n}) is: {result}")
    print("-" * 60)

if __name__ == "__main__":
    main()