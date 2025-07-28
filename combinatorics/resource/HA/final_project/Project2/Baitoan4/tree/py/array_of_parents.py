"""
Array of Parents implementation for Tree representations
"""

from typing import List
from dataclasses import dataclass

NIL_VALUE = -1


@dataclass
class ArrayOfParents:
    """Structure to represent array of parents for tree"""
    parent_array: List[int]
    number_of_nodes: int
    root_node: int
    
    def __init__(self, number_of_nodes: int = 0):
        self.number_of_nodes = number_of_nodes
        self.root_node = NIL_VALUE
        self.parent_array = [NIL_VALUE] * number_of_nodes


def read_array_of_parents_from_file(file_name: str) -> ArrayOfParents:
    """
    Read array of parents from input file
    
    Args:
        file_name: Name of input file
        
    Returns:
        ArrayOfParents structure containing the tree data
    """
    try:
        with open(file_name, 'r') as input_file:
            number_of_nodes = int(input_file.readline().strip())
            
            array_parents = ArrayOfParents(number_of_nodes)
            
            for node_index in range(number_of_nodes):
                parent_value = int(input_file.readline().strip())
                array_parents.parent_array[node_index] = parent_value
                if parent_value == NIL_VALUE:
                    array_parents.root_node = node_index
            
            return array_parents
    except FileNotFoundError:
        print(f"Error: Cannot open file {file_name}")
        return ArrayOfParents()
    except Exception as e:
        print(f"Error reading file: {e}")
        return ArrayOfParents()


def display_array_of_parents(array_parents: ArrayOfParents) -> None:
    """
    Display array of parents to console
    
    Args:
        array_parents: The array of parents to display
    """
    print("=== Array of Parents ===")
    print(f"Number of nodes: {array_parents.number_of_nodes}")
    print(f"Root node: {array_parents.root_node}")
    
    print("Parent array:")
    for node_index in range(array_parents.number_of_nodes):
        parent = array_parents.parent_array[node_index]
        parent_str = str(parent) if parent != NIL_VALUE else "NIL"
        print(f"Node {node_index}: parent = {parent_str}")
    print()


def write_array_of_parents_to_file(array_parents: ArrayOfParents, file_name: str) -> None:
    """
    Write array of parents to output file
    
    Args:
        array_parents: The array of parents to write
        file_name: Name of output file
    """
    try:
        with open(file_name, 'w') as output_file:
            output_file.write("=== Array of Parents ===\n")
            output_file.write(f"Number of nodes: {array_parents.number_of_nodes}\n")
            output_file.write(f"Root node: {array_parents.root_node}\n")
            
            output_file.write("Parent array:\n")
            for node_index in range(array_parents.number_of_nodes):
                parent = array_parents.parent_array[node_index]
                parent_str = str(parent) if parent != NIL_VALUE else "NIL"
                output_file.write(f"Node {node_index}: parent = {parent_str}\n")
    except Exception as e:
        print(f"Error: Cannot create file {file_name}: {e}")


def convert_array_parents_to_first_child_next_sibling(parent_array: List[int], 
                                                    number_of_nodes: int) -> 'FirstChildNextSibling':
    """
    Convert array of parents to first-child next-sibling representation
    
    Args:
        parent_array: Array of parent indices
        number_of_nodes: Number of nodes in the tree
        
    Returns:
        FirstChildNextSibling structure containing the converted data
    """
    from first_child_next_sibling import FirstChildNextSibling
    
    fcns_tree = FirstChildNextSibling(number_of_nodes)
    
    # Build children lists for each node
    children_lists = [[] for _ in range(number_of_nodes)]
    for node_index in range(number_of_nodes):
        if parent_array[node_index] != NIL_VALUE:
            children_lists[parent_array[node_index]].append(node_index)
        else:
            fcns_tree.root_node = node_index
    
    # Convert children lists to first-child next-sibling representation
    for node_index in range(number_of_nodes):
        if children_lists[node_index]:
            fcns_tree.first_child_array[node_index] = children_lists[node_index][0]
            for child_index in range(len(children_lists[node_index]) - 1):
                current_child = children_lists[node_index][child_index]
                next_child = children_lists[node_index][child_index + 1]
                fcns_tree.next_sibling_array[current_child] = next_child
    
    return fcns_tree


def convert_array_parents_to_graph_based(parent_array: List[int], 
                                        number_of_nodes: int) -> 'GraphBasedRepresentation':
    """
    Convert array of parents to graph-based representation
    
    Args:
        parent_array: Array of parent indices
        number_of_nodes: Number of nodes in the tree
        
    Returns:
        GraphBasedRepresentation structure containing the converted data
    """
    from graph_based_representation import GraphBasedRepresentation
    
    graph_tree = GraphBasedRepresentation(number_of_nodes)
    
    for node_index in range(number_of_nodes):
        if parent_array[node_index] != NIL_VALUE:
            graph_tree.adjacency_data[parent_array[node_index]].append(node_index)
        else:
            graph_tree.root_node = node_index
    
    return graph_tree 