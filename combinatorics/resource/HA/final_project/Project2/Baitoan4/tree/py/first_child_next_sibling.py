"""
First-Child Next-Sibling implementation for Tree representations
"""

from typing import List
from dataclasses import dataclass

NIL_VALUE = -1


@dataclass
class FirstChildNextSibling:
    """Structure to represent first-child next-sibling for tree"""
    first_child_array: List[int]
    next_sibling_array: List[int]
    number_of_nodes: int
    root_node: int
    
    def __init__(self, number_of_nodes: int = 0):
        self.number_of_nodes = number_of_nodes
        self.root_node = NIL_VALUE
        self.first_child_array = [NIL_VALUE] * number_of_nodes
        self.next_sibling_array = [NIL_VALUE] * number_of_nodes


def read_first_child_next_sibling_from_file(file_name: str) -> FirstChildNextSibling:
    """
    Read first-child next-sibling from input file
    
    Args:
        file_name: Name of input file
        
    Returns:
        FirstChildNextSibling structure containing the tree data
    """
    try:
        with open(file_name, 'r') as input_file:
            number_of_nodes = int(input_file.readline().strip())
            
            fcns_tree = FirstChildNextSibling(number_of_nodes)
            
            for node_index in range(number_of_nodes):
                line = input_file.readline().strip().split()
                first_child = int(line[0])
                next_sibling = int(line[1])
                
                fcns_tree.first_child_array[node_index] = first_child
                fcns_tree.next_sibling_array[node_index] = next_sibling
            
            # Find root node (node that is not a first child or next sibling)
            is_child_or_sibling = [False] * number_of_nodes
            for node_index in range(number_of_nodes):
                if fcns_tree.first_child_array[node_index] != NIL_VALUE:
                    is_child_or_sibling[fcns_tree.first_child_array[node_index]] = True
                if fcns_tree.next_sibling_array[node_index] != NIL_VALUE:
                    is_child_or_sibling[fcns_tree.next_sibling_array[node_index]] = True
            
            for node_index in range(number_of_nodes):
                if not is_child_or_sibling[node_index]:
                    fcns_tree.root_node = node_index
                    break
            
            return fcns_tree
    except FileNotFoundError:
        print(f"Error: Cannot open file {file_name}")
        return FirstChildNextSibling()
    except Exception as e:
        print(f"Error reading file: {e}")
        return FirstChildNextSibling()


def display_first_child_next_sibling(fcns_tree: FirstChildNextSibling) -> None:
    """
    Display first-child next-sibling to console
    
    Args:
        fcns_tree: The first-child next-sibling tree to display
    """
    print("=== First-Child Next-Sibling ===")
    print(f"Number of nodes: {fcns_tree.number_of_nodes}")
    print(f"Root node: {fcns_tree.root_node}")
    
    print("First-child and next-sibling arrays:")
    for node_index in range(fcns_tree.number_of_nodes):
        first_child = fcns_tree.first_child_array[node_index]
        next_sibling = fcns_tree.next_sibling_array[node_index]
        
        first_child_str = str(first_child) if first_child != NIL_VALUE else "NIL"
        next_sibling_str = str(next_sibling) if next_sibling != NIL_VALUE else "NIL"
        
        print(f"Node {node_index}: first_child = {first_child_str}, next_sibling = {next_sibling_str}")
    print()


def write_first_child_next_sibling_to_file(fcns_tree: FirstChildNextSibling, file_name: str) -> None:
    """
    Write first-child next-sibling to output file
    
    Args:
        fcns_tree: The first-child next-sibling tree to write
        file_name: Name of output file
    """
    try:
        with open(file_name, 'w') as output_file:
            output_file.write("=== First-Child Next-Sibling ===\n")
            output_file.write(f"Number of nodes: {fcns_tree.number_of_nodes}\n")
            output_file.write(f"Root node: {fcns_tree.root_node}\n")
            
            output_file.write("First-child and next-sibling arrays:\n")
            for node_index in range(fcns_tree.number_of_nodes):
                first_child = fcns_tree.first_child_array[node_index]
                next_sibling = fcns_tree.next_sibling_array[node_index]
                
                first_child_str = str(first_child) if first_child != NIL_VALUE else "NIL"
                next_sibling_str = str(next_sibling) if next_sibling != NIL_VALUE else "NIL"
                
                output_file.write(f"Node {node_index}: first_child = {first_child_str}, next_sibling = {next_sibling_str}\n")
    except Exception as e:
        print(f"Error: Cannot create file {file_name}: {e}")


def convert_first_child_next_sibling_to_array_parents(first_child_array: List[int], 
                                                    next_sibling_array: List[int], 
                                                    number_of_nodes: int) -> 'ArrayOfParents':
    """
    Convert first-child next-sibling to array of parents
    
    Args:
        first_child_array: Array of first child indices
        next_sibling_array: Array of next sibling indices
        number_of_nodes: Number of nodes in the tree
        
    Returns:
        ArrayOfParents structure containing the converted data
    """
    from array_of_parents import ArrayOfParents
    
    array_parents = ArrayOfParents(number_of_nodes)
    
    # Find root node
    is_child = [False] * number_of_nodes
    for node_index in range(number_of_nodes):
        if first_child_array[node_index] != NIL_VALUE:
            # Mark first child as a child
            is_child[first_child_array[node_index]] = True
            # Mark all siblings in the chain as children
            current_sibling = first_child_array[node_index]
            while current_sibling != NIL_VALUE:
                is_child[current_sibling] = True
                current_sibling = next_sibling_array[current_sibling]
    
    for node_index in range(number_of_nodes):
        if not is_child[node_index]:
            array_parents.root_node = node_index
            break
    
    # Build parent relationships
    for node_index in range(number_of_nodes):
        if first_child_array[node_index] != NIL_VALUE:
            current_child = first_child_array[node_index]
            while current_child != NIL_VALUE:
                array_parents.parent_array[current_child] = node_index
                current_child = next_sibling_array[current_child]
    
    return array_parents


def convert_first_child_next_sibling_to_graph_based(first_child_array: List[int], 
                                                  next_sibling_array: List[int], 
                                                  number_of_nodes: int) -> 'GraphBasedRepresentation':
    """
    Convert first-child next-sibling to graph-based representation
    
    Args:
        first_child_array: Array of first child indices
        next_sibling_array: Array of next sibling indices
        number_of_nodes: Number of nodes in the tree
        
    Returns:
        GraphBasedRepresentation structure containing the converted data
    """
    from graph_based_representation import GraphBasedRepresentation
    
    graph_tree = GraphBasedRepresentation(number_of_nodes)
    
    # Find root node
    is_child = [False] * number_of_nodes
    for node_index in range(number_of_nodes):
        if first_child_array[node_index] != NIL_VALUE:
            # Mark first child as a child
            is_child[first_child_array[node_index]] = True
            # Mark all siblings in the chain as children
            current_sibling = first_child_array[node_index]
            while current_sibling != NIL_VALUE:
                is_child[current_sibling] = True
                current_sibling = next_sibling_array[current_sibling]
    
    for node_index in range(number_of_nodes):
        if not is_child[node_index]:
            graph_tree.root_node = node_index
            break
    
    # Build adjacency lists (parent -> children)
    for node_index in range(number_of_nodes):
        if first_child_array[node_index] != NIL_VALUE:
            current_child = first_child_array[node_index]
            while current_child != NIL_VALUE:
                graph_tree.adjacency_data[node_index].append(current_child)
                current_child = next_sibling_array[current_child]
    
    return graph_tree 