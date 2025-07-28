"""
Integer Partition Analysis Module
Implements algorithms for analyzing self-conjugate partitions and odd-part partitions
"""

from typing import List, Tuple
from dataclasses import dataclass


@dataclass
class PartitionResults:
    """Structure to hold partition analysis results"""
    self_conjugate_list: List[List[int]]
    odd_parts_only_list: List[List[int]]
    distinct_odd_parts_list: List[List[int]]
    total_self_conjugate: int
    total_odd_parts: int
    total_distinct_odd: int


class PartitionAnalysis:
    """Class containing partition analysis algorithms"""
    
    @staticmethod
    def check_if_partition_is_self_conjugate(partition_elements: List[int]) -> bool:
        """
        Check if a given partition equals its conjugate (transpose)
        
        Args:
            partition_elements: Vector containing partition elements
            
        Returns:
            True if partition is self-conjugate, false otherwise
        """
        number_of_parts = len(partition_elements)
        conjugate_form = [0] * number_of_parts
        
        for i in range(number_of_parts):
            for j in range(number_of_parts):
                if partition_elements[j] >= i + 1:
                    conjugate_form[i] += 1
        
        for index in range(number_of_parts):
            if partition_elements[index] != conjugate_form[index]:
                return False
        
        return True
    
    @staticmethod
    def find_partitions_with_fixed_size(target_sum: int, 
                                       required_parts: int, 
                                       max_allowed_value: int,
                                       working_partition: List[int],
                                       found_partitions: List[List[int]]) -> None:
        """
        Generate partitions of specified number with exact part count
        
        Args:
            target_sum: Sum to achieve
            required_parts: Number of parts needed
            max_allowed_value: Maximum value for next part
            working_partition: Current partition being constructed
            found_partitions: Container for valid partitions
        """
        if required_parts == 0 and target_sum == 0:
            if PartitionAnalysis.check_if_partition_is_self_conjugate(working_partition):
                found_partitions.append(working_partition.copy())
            return
        
        if required_parts <= 0 or target_sum <= 0:
            return
        
        for candidate_value in range(min(max_allowed_value, target_sum), 0, -1):
            working_partition.append(candidate_value)
            PartitionAnalysis.find_partitions_with_fixed_size(
                target_sum - candidate_value, 
                required_parts - 1, 
                candidate_value, 
                working_partition, 
                found_partitions
            )
            working_partition.pop()
    
    @staticmethod
    def discover_self_conjugate_partitions(input_number: int) -> List[List[int]]:
        """
        Discover all self-conjugate partitions for given number
        
        Args:
            input_number: Number to partition
            
        Returns:
            List containing all self-conjugate partitions
        """
        result_collection = []
        temporary_partition = []
        
        for size_limit in range(1, input_number + 1):
            PartitionAnalysis.find_partitions_with_fixed_size(
                input_number, 
                size_limit, 
                input_number, 
                temporary_partition, 
                result_collection
            )
        
        return result_collection
    
    @staticmethod
    def construct_odd_number_partitions(remaining_value: int,
                                       minimum_odd: int,
                                       building_partition: List[int],
                                       collected_partitions: List[List[int]]) -> None:
        """
        Generate partitions using only odd numbers (repetition allowed)
        
        Args:
            remaining_value: Remaining sum to partition
            minimum_odd: Smallest odd number to use
            building_partition: Partition under construction
            collected_partitions: Storage for valid partitions
        """
        if remaining_value == 0:
            collected_partitions.append(building_partition.copy())
            return
        
        if remaining_value < 0:
            return
        
        odd_candidate = minimum_odd
        while odd_candidate <= remaining_value:
            building_partition.append(odd_candidate)
            PartitionAnalysis.construct_odd_number_partitions(
                remaining_value - odd_candidate, 
                odd_candidate, 
                building_partition, 
                collected_partitions
            )
            building_partition.pop()
            odd_candidate += 2
    
    @staticmethod
    def build_distinct_odd_partitions(remaining_sum: int,
                                     next_odd_start: int,
                                     current_partition: List[int],
                                     result_storage: List[List[int]]) -> None:
        """
        Create partitions using distinct odd numbers only
        
        Args:
            remaining_sum: Sum left to achieve
            next_odd_start: Next odd number to consider
            current_partition: Partition being built
            result_storage: Container for completed partitions
        """
        if remaining_sum == 0:
            result_storage.append(current_partition.copy())
            return
        
        if remaining_sum < 0:
            return
        
        odd_value = next_odd_start
        while odd_value <= remaining_sum:
            current_partition.append(odd_value)
            PartitionAnalysis.build_distinct_odd_partitions(
                remaining_sum - odd_value, 
                odd_value + 2, 
                current_partition, 
                result_storage
            )
            current_partition.pop()
            odd_value += 2
    
    @staticmethod
    def load_number_from_file(file_name: str) -> int:
        """
        Load target number from input file
        
        Args:
            file_name: Name of input file
            
        Returns:
            Integer value from file
        """
        try:
            with open(file_name, 'r') as data_file:
                target_value = int(data_file.readline().strip())
                return target_value
        except FileNotFoundError:
            print(f"Error: Unable to open file {file_name}")
            exit(1)
        except ValueError:
            print("Error: Invalid number format in file")
            exit(1)
    
    @staticmethod
    def display_formatted_partition(partition_data: List[int]) -> None:
        """
        Display a partition in readable format
        
        Args:
            partition_data: The partition to display
        """
        print(" + ".join(map(str, partition_data)))
    
    @staticmethod
    def organize_partitions_for_display(partitions_list: List[List[int]]) -> None:
        """
        Organize partitions for consistent display
        
        Args:
            partitions_list: Collection of partitions to sort
        """
        for single_partition in partitions_list:
            single_partition.sort(reverse=True)
        partitions_list.sort()
    
    @staticmethod
    def execute_complete_analysis(analysis_number: int) -> PartitionResults:
        """
        Perform comprehensive partition analysis
        
        Args:
            analysis_number: Number to analyze
            
        Returns:
            Complete analysis results
        """
        helper_partition = []
        
        # Analyze self-conjugate partitions
        self_conjugate_list = PartitionAnalysis.discover_self_conjugate_partitions(analysis_number)
        total_self_conjugate = len(self_conjugate_list)
        
        # Analyze odd-only partitions
        odd_parts_only_list = []
        PartitionAnalysis.construct_odd_number_partitions(
            analysis_number, 1, helper_partition, odd_parts_only_list
        )
        PartitionAnalysis.organize_partitions_for_display(odd_parts_only_list)
        total_odd_parts = len(odd_parts_only_list)
        
        # Analyze distinct odd partitions
        helper_partition.clear()
        distinct_odd_parts_list = []
        PartitionAnalysis.build_distinct_odd_partitions(
            analysis_number, 1, helper_partition, distinct_odd_parts_list
        )
        PartitionAnalysis.organize_partitions_for_display(distinct_odd_parts_list)
        total_distinct_odd = len(distinct_odd_parts_list)
        
        return PartitionResults(
            self_conjugate_list=self_conjugate_list,
            odd_parts_only_list=odd_parts_only_list,
            distinct_odd_parts_list=distinct_odd_parts_list,
            total_self_conjugate=total_self_conjugate,
            total_odd_parts=total_odd_parts,
            total_distinct_odd=total_distinct_odd
        )
    
    @staticmethod
    def present_analysis_results(target_number: int, results: PartitionResults) -> None:
        """
        Present analysis results to user
        
        Args:
            target_number: Number being analyzed
            results: Complete analysis results
        """
        print(f"{target_number}\n")
        
        # Display self-conjugate partitions
        print(f"Total self-conjugate partitions of {target_number}: {results.total_self_conjugate}")
        for partition in results.self_conjugate_list:
            PartitionAnalysis.display_formatted_partition(partition)
        print()
        
        # Display odd-parts partitions
        print(f"Partitions of {target_number} using odd parts: {results.total_odd_parts}")
        for partition in results.odd_parts_only_list:
            PartitionAnalysis.display_formatted_partition(partition)
        print()
        
        # Display distinct odd partitions
        print(f"Partitions of {target_number} into distinct odd parts: {results.total_distinct_odd}")
        for partition in results.distinct_odd_parts_list:
            PartitionAnalysis.display_formatted_partition(partition)
        print()
        
        # Present comparison
        if results.total_self_conjugate == results.total_distinct_odd:
            print("Self-conjugate partitions count = Distinct odd parts count")
        else:
            print("=> Counts are DIFFERENT")


def main() -> None:
    """Main program entry point"""
    INPUT_FILE_NAME = "input.txt"
    
    number_to_analyze = PartitionAnalysis.load_number_from_file(INPUT_FILE_NAME)
    
    if number_to_analyze < 0:
        print("Input must be a non-negative integer.")
        return
    
    analysis_outcome = PartitionAnalysis.execute_complete_analysis(number_to_analyze)
    PartitionAnalysis.present_analysis_results(number_to_analyze, analysis_outcome)


if __name__ == "__main__":
    main() 