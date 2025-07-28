#!/usr/bin/env python3
"""
@file ferreries_diagram.py
@brief Generates and displays Ferrers diagrams for integer partitions
@details Implements partition generation and Ferrers diagram visualization in Python
"""

from typing import List, TextIO, Optional
import sys


class Partition:
    """
    Represents a partition of an integer with associated operations
    """
    
    def __init__(self, elements: Optional[List[int]] = None) -> None:
        """
        Constructs a partition from list of integers
        
        Args:
            elements: List containing partition elements, defaults to empty list
        """
        self._partition_elements: List[int] = elements if elements is not None else []
    
    def add_element(self, value: int) -> None:
        """
        Adds an element to the partition
        
        Args:
            value: Value to add to partition
        """
        self._partition_elements.append(value)
    
    def remove_last_element(self) -> None:
        """
        Removes the last element from partition
        """
        if self._partition_elements:
            self._partition_elements.pop()
    
    def get_elements(self) -> List[int]:
        """
        Gets the partition elements
        
        Returns:
            Copy of partition elements list
        """
        return self._partition_elements.copy()
    
    def get_size(self) -> int:
        """
        Gets the size of the partition
        
        Returns:
            Number of elements in partition
        """
        return len(self._partition_elements)
    
    def is_empty(self) -> bool:
        """
        Checks if partition is empty
        
        Returns:
            True if partition has no elements
        """
        return len(self._partition_elements) == 0
    
    def find_maximum_value(self) -> int:
        """
        Finds the maximum value in the partition
        
        Returns:
            Maximum value, or 0 if partition is empty
        """
        if not self._partition_elements:
            return 0
        return max(self._partition_elements)
    
    def calculate_sum(self) -> int:
        """
        Calculates the sum of all partition elements
        
        Returns:
            Sum of all elements in partition
        """
        return sum(self._partition_elements)


class FileInputHandler:
    """
    Handles input operations for partition generation
    """
    
    def __init__(self, file_name: str) -> None:
        """
        Constructs input handler with file name
        
        Args:
            file_name: Name of input file to read from
        """
        self._file_name: str = file_name
    
    def read_partition_parameters(self) -> tuple[int, int]:
        """
        Reads partition parameters from file
        
        Returns:
            Tuple containing (target_sum, number_of_parts)
            
        Raises:
            FileNotFoundError: If input file cannot be opened
            ValueError: If file format is invalid
        """
        try:
            with open(self._file_name, 'r', encoding='utf-8') as input_file:
                line = input_file.readline().strip()
                target_sum, number_of_parts = map(int, line.split())
                return target_sum, number_of_parts
        except FileNotFoundError:
            raise FileNotFoundError(f"Error: Cannot open {self._file_name} file")
        except (ValueError, IndexError) as error:
            raise ValueError(f"Error: Failed to read parameters from {self._file_name}: {error}")


class ConsoleInputHandler:
    """
    Handles console input operations for partition generation
    """
    
    @staticmethod
    def read_partition_parameters() -> tuple[int, int]:
        """
        Reads partition parameters from console
        
        Returns:
            Tuple containing (target_sum, number_of_parts)
            
        Raises:
            ValueError: If input format is invalid
        """
        try:
            line = input().strip()
            target_sum, number_of_parts = map(int, line.split())
            return target_sum, number_of_parts
        except (ValueError, IndexError) as error:
            raise ValueError(f"Error: Invalid input format. Expected two integers: {error}")


class FerrersDisplay:
    """
    Handles display operations for Ferrers diagrams
    """
    
    def __init__(self, output_stream: TextIO) -> None:
        """
        Constructs display handler with output stream
        
        Args:
            output_stream: Output stream for displaying results
        """
        self._output_stream: TextIO = output_stream
    
    def _display_ferrers_row(self, row_length: int, total_width: int) -> None:
        """
        Displays a single row of the Ferrers diagram
        
        Args:
            row_length: Number of stars in the row
            total_width: Total width for alignment
        """
        stars = "*" * row_length
        spaces = " " * (total_width - row_length)
        self._output_stream.write(f"{stars}{spaces} {row_length}\n")
    
    def _display_transpose_row(self, row_index: int, partition: Partition) -> None:
        """
        Displays a single row of the transposed Ferrers diagram
        
        Args:
            row_index: Current row index
            partition: Partition to display
        """
        elements = partition.get_elements()
        row_parts = []
        
        for element in elements:
            if element > row_index:
                row_parts.append("*")
            else:
                row_parts.append(" ")
        
        row_content = " ".join(row_parts).rstrip()
        self._output_stream.write(f"{row_content}\n")
    
    def _display_partition_values(self, partition: Partition) -> None:
        """
        Displays the partition values as footer
        
        Args:
            partition: Partition to display
        """
        elements = partition.get_elements()
        values_string = " ".join(str(element) for element in elements)
        self._output_stream.write(f"{values_string}\n")
    
    def display_ferrers(self, partition: Partition) -> None:
        """
        Displays the standard Ferrers diagram
        
        Args:
            partition: Partition to display
        """
        self._output_stream.write("F:\n")
        maximum_value = partition.find_maximum_value()
        elements = partition.get_elements()
        
        for row_length in elements:
            self._display_ferrers_row(row_length, maximum_value)
    
    def display_ferrers_transpose(self, partition: Partition) -> None:
        """
        Displays the transposed Ferrers diagram
        
        Args:
            partition: Partition to display
        """
        self._output_stream.write("FT:\n")
        maximum_value = partition.find_maximum_value()
        
        for row_index in range(maximum_value):
            self._display_transpose_row(row_index, partition)
        
        self._display_partition_values(partition)
    
    def display_separator(self) -> None:
        """
        Displays separator between partitions
        """
        self._output_stream.write("====================\n")
    
    def display_header(self, target_sum: int, number_of_parts: int) -> None:
        """
        Displays program header information
        
        Args:
            target_sum: Target sum for partitions
            number_of_parts: Number of parts in each partition
        """
        self._output_stream.write(f"Generating all partitions of {target_sum} "
                                f"into exactly {number_of_parts} parts:\n")
        self.display_separator()
    
    def display_completion(self) -> None:
        """
        Displays program completion message
        """
        self._output_stream.write("Done.\n")


class PartitionGenerator:
    """
    Generates integer partitions with specified constraints
    """
    
    def __init__(self, display_handler: FerrersDisplay) -> None:
        """
        Constructs partition generator with display handler
        
        Args:
            display_handler: Handler for displaying results
        """
        self._display_handler: FerrersDisplay = display_handler
    
    def _generate_partitions_recursive(self, remaining_sum: int, remaining_parts: int,
                                     current_partition: Partition, maximum_value: int) -> None:
        """
        Recursively generates partitions with specified constraints
        
        Args:
            remaining_sum: Remaining sum to partition
            remaining_parts: Remaining parts to generate
            current_partition: Current partition being built
            maximum_value: Maximum value allowed for next part
        """
        if remaining_parts == 0:
            if remaining_sum == 0:
                self._display_complete_partition(current_partition)
            return
        
        upper_limit = min(remaining_sum, maximum_value)
        for value in range(upper_limit, 0, -1):
            current_partition.add_element(value)
            self._generate_partitions_recursive(remaining_sum - value, remaining_parts - 1,
                                              current_partition, value)
            current_partition.remove_last_element()
    
    def _display_complete_partition(self, partition: Partition) -> None:
        """
        Displays a complete partition with both diagrams
        
        Args:
            partition: Complete partition to display
        """
        self._display_handler.display_ferrers(partition)
        self._display_handler.display_ferrers_transpose(partition)
        self._display_handler.display_separator()
    
    def generate_all_partitions(self, target_sum: int, number_of_parts: int) -> None:
        """
        Generates all partitions with specified parameters
        
        Args:
            target_sum: Target sum for all partitions
            number_of_parts: Number of parts in each partition
        """
        self._display_handler.display_header(target_sum, number_of_parts)
        
        current_partition = Partition()
        self._generate_partitions_recursive(target_sum, number_of_parts, 
                                          current_partition, target_sum)
        
        self._display_handler.display_completion()


class FerrersApplication:
    """
    Coordinates the Ferrers diagram application workflow
    """
    
    def __init__(self, use_file_input: bool = True, file_name: str = "input.txt") -> None:
        """
        Constructs the application with input configuration
        
        Args:
            use_file_input: Whether to use file input (True) or console input (False)
            file_name: Name of input file if using file input
        """
        self._use_file_input: bool = use_file_input
        self._file_input_handler: Optional[FileInputHandler] = None
        self._console_input_handler: Optional[ConsoleInputHandler] = None
        
        if use_file_input:
            self._file_input_handler = FileInputHandler(file_name)
        else:
            self._console_input_handler = ConsoleInputHandler()
        
        display_handler = FerrersDisplay(sys.stdout)
        self._partition_generator = PartitionGenerator(display_handler)
    
    def execute_application(self) -> int:
        """
        Executes the complete application workflow
        
        Returns:
            Exit status (0 for success, 1 for error)
        """
        try:
            if self._use_file_input and self._file_input_handler:
                target_sum, number_of_parts = self._file_input_handler.read_partition_parameters()
            elif self._console_input_handler:
                target_sum, number_of_parts = self._console_input_handler.read_partition_parameters()
            else:
                raise RuntimeError("No input handler configured")
            
            self._partition_generator.generate_all_partitions(target_sum, number_of_parts)
            return 0
            
        except (FileNotFoundError, ValueError, RuntimeError) as error:
            print(f"Error occurred: {error}", file=sys.stderr)
            return 1


def main() -> int:
    """
    Main program entry point
    
    Returns:
        Program exit status
    """
    try:
        # Try file input first, fall back to console input if file doesn't exist
        try:
            application = FerrersApplication(use_file_input=True, file_name="input.txt")
            return application.execute_application()
        except FileNotFoundError:
            print("input.txt not found, using console input:", file=sys.stderr)
            application = FerrersApplication(use_file_input=False)
            return application.execute_application()
            
    except Exception as error:
        print(f"Unexpected error occurred: {error}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main()) 