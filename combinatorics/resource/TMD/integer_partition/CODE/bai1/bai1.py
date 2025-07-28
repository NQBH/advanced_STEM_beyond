# problem1.py
# Full implementation for finding partitions of n into k parts
# and drawing their Ferrers and transposed Ferrers diagrams.

import sys

def find_partitions_recursive(target_sum, num_parts, max_val, current_partition, results):
    """
    Core recursive function using backtracking to find partitions.

    Args:
        target_sum (int): The remaining sum to be partitioned.
        num_parts (int): The number of remaining parts to find.
        max_val (int): The maximum value for the next part (to ensure non-increasing order).
        current_partition (list): The list of parts found so far in the current recursive branch.
        results (list): A list to aggregate all valid partitions found.
    """
    # --- Base Case ---
    # If only one part remains, it must equal the entire remaining sum.
    if num_parts == 1:
        # Check if this final value is valid (must be >= 1 and <= max_val).
        if 1 <= target_sum <= max_val:
            # Add the final part and save the complete partition.
            results.append(current_partition + [target_sum])
        return

    # --- Recursive Step ---
    # Iterate through all possible values 'i' for the current part.
    # The loop goes downwards from max_val to ensure non-increasing order (λ_i >= λ_{i+1}).
    for i in range(max_val, 0, -1):
        remaining_sum = target_sum - i
        remaining_parts = num_parts - 1
        
        # --- Pruning to improve efficiency ---
        # Minimum condition: The remaining sum must be large enough for the remaining parts (at least 1 each).
        # Maximum condition: The remaining sum cannot be too large (at most 'i' for each remaining part).
        if remaining_sum >= remaining_parts and remaining_sum <= remaining_parts * i:
            find_partitions_recursive(
                remaining_sum, 
                remaining_parts, 
                i, # The max value for the next call is the current value 'i'.
                current_partition + [i], 
                results
            )

def generate_all_partitions(n, k):
    """
    Wrapper function to initialize and start the recursive process for finding partitions.
    
    Args:
        n (int): The integer to partition.
        k (int): The number of parts.

    Returns:
        list[list[int]]: A list of all partitions, where each partition is a list of integers.
    """
    if n < k or k <= 0:
        return []
    
    results = []
    # The initial max_val is n - (k-1) because the other k-1 parts must be at least 1.
    initial_max_val = n - (k - 1)
    find_partitions_recursive(n, k, initial_max_val, [], results)
    return results

def draw_ferrers(partition):
    """
    Draws the Ferrers diagram (F) for a given partition.
    
    Args:
        partition (list[int]): A list of integers representing a partition.
    """
    print("  Ferrers Diagram (F):")
    for part in partition:
        print(f"    {'* ' * part}")

def draw_transpose(partition):
    """
    Draws the transposed Ferrers diagram (F^T).
    
    Args:
        partition (list[int]): A list of integers representing a partition.
    """
    print("  Transposed Ferrers Diagram (F^T):")
    if not partition:
        return
        
    # The number of rows in the transposed diagram equals the largest part of the original partition.
    max_part = partition[0]
    
    # Iterate through each row of the transposed diagram.
    for i in range(1, max_part + 1):
        # The length of row i (λ'_i) is the number of parts in λ that are >= i.
        count = sum(1 for part in partition if part >= i)
        print(f"    {'* ' * count}")

def main():
    """
    Main function to drive the program. It gets user input, finds partitions,
    and prints the results along with their diagrams.
    """
    print("--- Problem 1: Ferrers Diagrams & Partitions ---")
    try:
        n = int(input("Enter the integer to partition (n): "))
        k = int(input("Enter the number of parts (k): "))
        if n <= 0 or k <= 0: 
            raise ValueError("n and k must be positive integers.")
    except ValueError as e:
        print(f"Error: Invalid input. {e}", file=sys.stderr)
        return

    # Generate all partitions of n into k parts.
    partitions = generate_all_partitions(n, k)
    print("-" * 50)
    
    if not partitions:
        print(f"There are no partitions of {n} into {k} parts (p_{k}({n}) = 0).")
    else:
        print(f"Found {len(partitions)} partitions of {n} into {k} parts (p_{k}({n}) = {len(partitions)}).")
        for i, p in enumerate(partitions):
            print(f"\n[{i+1}] Partition: {p}")
            draw_ferrers(p)
            draw_transpose(p)
            print("-" * 50)

if __name__ == "__main__":
    main()