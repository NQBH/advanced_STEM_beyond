"""
Self-Conjugate Partition Analysis Module
Implements recursive and dynamic programming approaches for counting 
self-conjugate partitions with exactly k parts
"""

from typing import List, Tuple, Dict
from functools import lru_cache


class SelfConjugatePartitions:
    """Class containing algorithms for self-conjugate partition analysis"""
    
    @staticmethod
    def validate_self_conjugate_property(partition_parts: List[int]) -> bool:
        """
        Check if a partition is self-conjugate (equals its transpose)
        
        Args:
            partition_parts: List of partition parts in non-increasing order
            
        Returns:
            True if partition is self-conjugate, false otherwise
        """
        number_of_parts = len(partition_parts)
        conjugate_form = []
        maximum_part = max(partition_parts) if partition_parts else 0
        
        for row_index in range(1, maximum_part + 1):
            column_count = 0
            for part_value in partition_parts:
                if part_value >= row_index:
                    column_count += 1
                else:
                    break
            conjugate_form.append(column_count)
        
        if len(conjugate_form) != number_of_parts:
            return False
        
        for index in range(number_of_parts):
            if partition_parts[index] != conjugate_form[index]:
                return False
        
        return True
    
    @staticmethod
    def calculate_recursive_with_memoization(target_number: int, 
                                           exact_parts: int, 
                                           memoization_table: Dict[Tuple[int, int], int]) -> int:
        """
        Recursive approach with memoization for counting self-conjugate partitions
        
        Args:
            target_number: Number to partition
            exact_parts: Exact number of parts required
            memoization_table: Dictionary for storing computed results
            
        Returns:
            Number of self-conjugate partitions of target_number with exact_parts parts
        """
        if target_number == 0 and exact_parts == 0:
            return 1
        if target_number < 0 or exact_parts <= 0:
            return 0
        if exact_parts > target_number:
            return 0
        
        memo_key = (target_number, exact_parts)
        if memo_key in memoization_table:
            return memoization_table[memo_key]
        
        valid_partitions_count = 0
        current_partition = []
        
        def generate_partitions(remaining_sum: int, remaining_parts: int, maximum_value: int) -> None:
            nonlocal valid_partitions_count
            
            if remaining_parts == 0 and remaining_sum == 0:
                temporary_partition = sorted(current_partition, reverse=True)
                
                if (len(temporary_partition) == exact_parts and 
                    SelfConjugatePartitions.validate_self_conjugate_property(temporary_partition)):
                    valid_partitions_count += 1
                return
            
            if remaining_parts <= 0 or remaining_sum <= 0:
                return
            
            for candidate_value in range(min(maximum_value, remaining_sum), 0, -1):
                current_partition.append(candidate_value)
                generate_partitions(remaining_sum - candidate_value, remaining_parts - 1, candidate_value)
                current_partition.pop()
        
        generate_partitions(target_number, exact_parts, target_number)
        memoization_table[memo_key] = valid_partitions_count
        return valid_partitions_count
    
    @staticmethod
    def calculate_dynamic_programming(target_number: int, exact_parts: int) -> int:
        """
        Dynamic programming approach for counting self-conjugate partitions
        
        Args:
            target_number: Number to partition
            exact_parts: Exact number of parts required
            
        Returns:
            Number of self-conjugate partitions of target_number with exact_parts parts
        """
        if target_number == 0 and exact_parts == 0:
            return 1
        if target_number < 0 or exact_parts <= 0:
            return 0
        if exact_parts > target_number:
            return 0
        
        dp_table = [[0] * (exact_parts + 1) for _ in range(target_number + 1)]
        dp_table[0][0] = 1
        
        for current_sum in range(1, target_number + 1):
            for current_parts in range(1, min(current_sum, exact_parts) + 1):
                valid_count = 0
                working_partition = []
                
                def generate_valid_partitions(remaining_sum: int, 
                                            remaining_parts_count: int, 
                                            maximum_allowed: int) -> None:
                    nonlocal valid_count
                    
                    if remaining_parts_count == 0 and remaining_sum == 0:
                        partition_copy = sorted(working_partition, reverse=True)
                        
                        if (len(partition_copy) == current_parts and 
                            SelfConjugatePartitions.validate_self_conjugate_property(partition_copy)):
                            valid_count += 1
                        return
                    
                    if remaining_parts_count <= 0 or remaining_sum <= 0:
                        return
                    
                    for next_value in range(min(maximum_allowed, remaining_sum), 0, -1):
                        working_partition.append(next_value)
                        generate_valid_partitions(remaining_sum - next_value, 
                                                remaining_parts_count - 1, 
                                                next_value)
                        working_partition.pop()
                
                generate_valid_partitions(current_sum, current_parts, current_sum)
                dp_table[current_sum][current_parts] = valid_count
        
        return dp_table[target_number][exact_parts]
    
    @staticmethod
    def load_parameters_from_file(file_name: str) -> Tuple[int, int]:
        """
        Read input parameters from file
        
        Args:
            file_name: Input file name
            
        Returns:
            Tuple of (target_number, exact_parts) values
        """
        try:
            with open(file_name, 'r') as input_file:
                line = input_file.readline().strip()
                numbers = line.split()
                if len(numbers) >= 2:
                    target_number = int(numbers[0])
                    exact_parts = int(numbers[1])
                    return target_number, exact_parts
                else:
                    raise ValueError("Insufficient numbers in input file")
        except FileNotFoundError:
            print(f"Error: Cannot open file {file_name}")
            exit(1)
        except ValueError as e:
            print(f"Error: Invalid input format - {e}")
            exit(1)
    
    @staticmethod
    def present_computation_results(target_number: int, 
                                  exact_parts: int, 
                                  recursive_result: int, 
                                  dp_result: int) -> None:
        """
        Display computation results with formatted output
        
        Args:
            target_number: The number being partitioned
            exact_parts: The exact number of parts required
            recursive_result: Result from recursive approach
            dp_result: Result from dynamic programming approach
        """
        print(f"Self-conjugate partitions of {target_number} with {exact_parts} parts (Recursive): {recursive_result}")
        print(f"Self-conjugate partitions of {target_number} with {exact_parts} parts (Dynamic Programming): {dp_result}")


def main() -> None:
    """Main program entry point"""
    INPUT_FILE_NAME = "input.txt"
    
    target_number, exact_parts = SelfConjugatePartitions.load_parameters_from_file(INPUT_FILE_NAME)
    
    # Compute using recursive approach with memoization
    memoization_cache = {}
    recursive_result = SelfConjugatePartitions.calculate_recursive_with_memoization(
        target_number, exact_parts, memoization_cache
    )
    
    # Compute using dynamic programming approach
    dynamic_programming_result = SelfConjugatePartitions.calculate_dynamic_programming(
        target_number, exact_parts
    )
    
    # Display results
    SelfConjugatePartitions.present_computation_results(
        target_number, exact_parts, recursive_result, dynamic_programming_result
    )


if __name__ == "__main__":
    main() 