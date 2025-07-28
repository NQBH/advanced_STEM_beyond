from typing import List, Tuple

class AdjacencyMatrixGraph:
    """
    Implements a directed graph using an adjacency matrix representation,
    wrapped in a Python class as required by Exercise 1.5.

    This class provides the extended operations defined in Problem 1.4,
    allowing manipulation of the graph through vertex pairs instead of
    explicit edge objects.
    """

    def __init__(self, num_vertices: int):
        """
        Constructs a graph with a specified number of vertices.

        :param num_vertices: The number of vertices. The graph will have vertices 0 to n-1.
        """
        self.num_vertices = num_vertices
        # Initialize an n x n matrix (list of lists) with all zeros (no edges).
        self.matrix: List[List[int]] = [[0] * num_vertices for _ in range(num_vertices)]

    def add_edge(self, u: int, v: int):
        """
        Adds a directed edge from u to v.
        
        :param u: The source vertex.
        :param v: The target vertex.
        """
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            self.matrix[u][v] = 1

    def del_edge(self, u: int, v: int):
        """
        (Problem 1.4) Deletes a directed edge from u to v.

        :param u: The source vertex.
        :param v: The target vertex.
        """
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            self.matrix[u][v] = 0

    def source(self, u: int, v: int) -> int:
        """
        (Problem 1.4) Gets the source of an edge defined by (u, v).
        This is a trivial operation as the source is given as an argument.
        """
        return u
        
    def target(self, u: int, v: int) -> int:
        """
        (Problem 1.4) Gets the target of an edge defined by (u, v).
        Trivial operation, returns the given target.
        """
        return v

    def edges(self) -> List[Tuple[int, int]]:
        """
        (Problem 1.4) Returns a list of all edges in the graph.
        Complexity: O(n^2), where n is the number of vertices.

        :return: A list of tuples, where each tuple represents a directed edge.
        """
        edge_list = []
        for i in range(self.num_vertices):
            for j in range(self.num_vertices):
                if self.matrix[i][j] == 1:
                    edge_list.append((i, j))
        return edge_list

    def outgoing(self, v: int) -> List[Tuple[int, int]]:
        """
        (Problem 1.4) Returns a list of all outgoing edges from a vertex.
        Complexity: O(n), where n is the number of vertices.

        :param v: The source vertex.
        :return: A list of tuples representing outgoing edges.
        """
        edge_list = []
        if 0 <= v < self.num_vertices:
            for j in range(self.num_vertices):
                if self.matrix[v][j] == 1:
                    edge_list.append((v, j))
        return edge_list
        
    def incoming(self, v: int) -> List[Tuple[int, int]]:
        """
        (Problem 1.4) Returns a list of all incoming edges to a vertex.
        Complexity: O(n), where n is the number of vertices.

        :param v: The target vertex.
        :return: A list of tuples representing incoming edges.
        """
        edge_list = []
        if 0 <= v < self.num_vertices:
            for i in range(self.num_vertices):
                if self.matrix[i][v] == 1:
                    edge_list.append((i, v))
        return edge_list

    def __str__(self) -> str:
        """
        Helper method to provide a string representation of the matrix for printing.
        """
        return "\n".join(["  " + " ".join(map(str, row)) for row in self.matrix])

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR EXERCISE 1.5
# =================================================================================
if __name__ == "__main__":
    num_nodes = 4
    print("=" * 60)
    print("  Adjacency Matrix Graph Class Demo (Exercise 1.5)   ")
    print("=" * 60)

    # --- 1. Create a graph instance ---
    graph = AdjacencyMatrixGraph(num_nodes)
    print(f"\n--> Initial empty graph with {num_nodes} vertices:")
    print(graph)

    # --- 2. Add some edges ---
    print("\n--> Adding edges: (0,1), (0,2), (1,2), (2,0), (2,3), (3,3)")
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 2)
    graph.add_edge(2, 0)
    graph.add_edge(2, 3)
    graph.add_edge(3, 3)  # A self-loop
    print("Matrix after adding edges:")
    print(graph)

    # --- 3. Test the extended operations ---
    print("\n--> Testing extended operations from Problem 1.4:")

    # Test edges()
    print(f"  All edges: {graph.edges()}")

    # Test outgoing()
    node_to_test = 2
    print(f"  Outgoing edges from node {node_to_test}: {graph.outgoing(node_to_test)}")

    # Test incoming()
    print(f"  Incoming edges to node {node_to_test}: {graph.incoming(node_to_test)}")

    # Test del_edge()
    print("\n--> Deleting edge (0,2)...")
    graph.del_edge(0, 2)
    print("Matrix after deleting edge (0,2):")
    print(graph)

    print("=" * 60)