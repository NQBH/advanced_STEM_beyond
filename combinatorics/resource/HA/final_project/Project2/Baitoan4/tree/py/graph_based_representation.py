"""
Graph-Based Representation implementation for Tree representations
"""

from typing import List
from dataclasses import dataclass

NIL_VALUE = -1


@dataclass
class GraphBasedRepresentation:
    """Structure to represent graph-based representation for tree"""
    adjacency_data: List[List[int]]
    number_of_nodes: int
    root_node: int
    
    def __init__(self, number_of_nodes: int = 0):
        self.number_of_nodes = number_of_nodes
        self.root_node = NIL_VALUE
        self.adjacency_data = [[] for _ in range(number_of_nodes)]


def read_graph_based_representation_from_file(file_name: str) -> GraphBasedRepresentation:
    """
    Read graph-based representation from input file
    
    Args:
        file_name: Name of input file
        
    Returns:
        GraphBasedRepresentation structure containing the tree data
    """
    try:
        with open(file_name, 'r') as input_file:
            number_of_nodes = int(input_file.readline().strip())
            
            graph_tree = GraphBasedRepresentation(number_of_nodes)
            
            for node_index in range(number_of_nodes):
                line = input_file.readline().strip().split()
                if line and line[0] != '0':
                    num_children = int(line[0])
                    for i in range(1, num_children + 1):
                        if i < len(line):
                            child = int(line[i])
                            graph_tree.adjacency_data[node_index].append(child)
            
            # Find root node (node with no incoming edges)
            has_incoming = [False] * number_of_nodes
            for node_index in range(number_of_nodes):
                for child in graph_tree.adjacency_data[node_index]:
                    has_incoming[child] = True
            
            for node_index in range(number_of_nodes):
                if not has_incoming[node_index]:
                    graph_tree.root_node = node_index
                    break
            
            return graph_tree
    except FileNotFoundError:
        print(f"Error: Cannot open file {file_name}")
        return GraphBasedRepresentation()
    except Exception as e:
        print(f"Error reading file: {e}")
        return GraphBasedRepresentation()


def display_graph_based_representation(graph_tree: GraphBasedRepresentation) -> None:
    """
    Display graph-based representation to console
    
    Args:
        graph_tree: The graph-based representation tree to display
    """
    print("=== Graph-Based Representation ===")
    print(f"Number of nodes: {graph_tree.number_of_nodes}")
    print(f"Root node: {graph_tree.root_node}")
    
    print("Adjacency lists:")
    for node_index in range(graph_tree.number_of_nodes):
        if graph_tree.adjacency_data[node_index]:
            children = " ".join(map(str, graph_tree.adjacency_data[node_index]))
            print(f"Node {node_index}: children = [{children}]")
        else:
            print(f"Node {node_index}: children = []")
    print()


def write_graph_based_representation_to_file(graph_tree: GraphBasedRepresentation, file_name: str) -> None:
    """
    Write graph-based representation to output file
    
    Args:
        graph_tree: The graph-based representation tree to write
        file_name: Name of output file
    """
    try:
        with open(file_name, 'w') as output_file:
            output_file.write("=== Graph-Based Representation ===\n")
            output_file.write(f"Number of nodes: {graph_tree.number_of_nodes}\n")
            output_file.write(f"Root node: {graph_tree.root_node}\n")
            
            output_file.write("Adjacency lists:\n")
            for node_index in range(graph_tree.number_of_nodes):
                if graph_tree.adjacency_data[node_index]:
                    children = " ".join(map(str, graph_tree.adjacency_data[node_index]))
                    output_file.write(f"Node {node_index}: children = [{children}]\n")
                else:
                    output_file.write(f"Node {node_index}: children = []\n")
    except Exception as e:
        print(f"Error: Cannot create file {file_name}: {e}")


def convert_graph_based_to_array_parents(adjacency_data: List[List[int]], 
                                        number_of_nodes: int) -> 'ArrayOfParents':
    """
    Convert graph-based representation to array of parents
    
    Args:
        adjacency_data: Adjacency list data (parent -> children)
        number_of_nodes: Number of nodes in the tree
        
    Returns:
        ArrayOfParents structure containing the converted data
    """
    from array_of_parents import ArrayOfParents
    
    array_parents = ArrayOfParents(number_of_nodes)
    
    # Find root and build parent relationships
    for parent_index in range(number_of_nodes):
        for child in adjacency_data[parent_index]:
            if 0 <= child < number_of_nodes:
                array_parents.parent_array[child] = parent_index
    
    # Find root node (node with no parent)
    for node_index in range(number_of_nodes):
        if array_parents.parent_array[node_index] == NIL_VALUE:
            array_parents.root_node = node_index
            break
    
    return array_parents


def convert_graph_based_to_first_child_next_sibling(adjacency_data: List[List[int]], 
                                                   number_of_nodes: int) -> 'FirstChildNextSibling':
    """
    Convert graph-based representation to first-child next-sibling
    
    Args:
        adjacency_data: Adjacency list data (parent -> children)
        number_of_nodes: Number of nodes in the tree
        
    Returns:
        FirstChildNextSibling structure containing the converted data
    """
    from first_child_next_sibling import FirstChildNextSibling
    
    fcns_tree = FirstChildNextSibling(number_of_nodes)
    
    # Find root node (node with no incoming edges)
    has_incoming = [False] * number_of_nodes
    for node_index in range(number_of_nodes):
        for child in adjacency_data[node_index]:
            has_incoming[child] = True
    
    for node_index in range(number_of_nodes):
        if not has_incoming[node_index]:
            fcns_tree.root_node = node_index
            break
    
    # Convert adjacency lists to first-child next-sibling
    for parent_index in range(number_of_nodes):
        children = adjacency_data[parent_index]
        if children:
            # Set first child
            fcns_tree.first_child_array[parent_index] = children[0]
            
            # Set next sibling relationships
            for i in range(len(children) - 1):
                fcns_tree.next_sibling_array[children[i]] = children[i + 1]
    
    return fcns_tree 