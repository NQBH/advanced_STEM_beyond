from typing import Dict, List

# A type alias for graph representation for better readability.
GraphAdjList = Dict[int, List[int]]

class GraphGenerator:
    """
    A class to generate various families of standard graphs.

    This class implements algorithms to construct path, cycle, wheel, complete,
    and complete bipartite graphs. It simulates the abstract operations like
    `new_vertex` and `new_edge` described in the textbook by manipulating
    an internal adjacency list dictionary.
    """
    def __init__(self):
        """Initializes the generator with an empty graph."""
        self.adj: GraphAdjList = {}
        self.num_vertices: int = 0

    def _clear(self):
        """Resets the generator to an empty state for a new graph."""
        self.adj = {}
        self.num_vertices = 0

    def _new_vertex(self) -> int:
        """Simulates the `new_vertex` operation."""
        v_id = self.num_vertices
        self.adj[v_id] = []
        self.num_vertices += 1
        return v_id

    def _new_edge(self, u: int, v: int):
        """Simulates the `new_edge` operation for an undirected graph."""
        if u in self.adj and v in self.adj:
            self.adj[u].append(v)
            self.adj[v].append(u)

    def generate_path_graph(self, n: int) -> GraphAdjList:
        """Exercise 1.3: Generates a Path Graph P_n."""
        self._clear()
        if n <= 0: return self.adj
        vertices = [self._new_vertex() for _ in range(n)]
        for i in range(n - 1):
            self._new_edge(vertices[i], vertices[i + 1])
        return self.adj

    def generate_cycle_graph(self, n: int) -> GraphAdjList:
        """Exercise 1.3: Generates a Cycle Graph C_n."""
        # A cycle is a path with an edge connecting the ends.
        self.generate_path_graph(n)
        if n > 2:
            self._new_edge(n - 1, 0)
        return self.adj

    def generate_wheel_graph(self, n: int) -> GraphAdjList:
        """
        Exercise 1.3: Generates a Wheel Graph W_n.
        W_n has n vertices: one central vertex connected to a cycle of n-1 vertices.
        """
        self._clear()
        if n <= 3: return self.adj # A wheel needs at least 4 vertices.
        
        center_vertex = self._new_vertex() # Node 0
        outer_vertices = [self._new_vertex() for _ in range(n - 1)] # Nodes 1 to n-1
        
        # Connect center to all outer vertices
        for v in outer_vertices:
            self._new_edge(center_vertex, v)
        
        # Connect outer vertices in a cycle
        for i in range(n - 1):
            # Connects node_i to node_{i+1}, and wraps around for the last one.
            # Indices of outer_vertices are 0 to n-2.
            # Node IDs of outer_vertices are 1 to n-1.
            self._new_edge(outer_vertices[i], outer_vertices[(i + 1) % (n - 1)])
        return self.adj

    def generate_complete_graph(self, n: int) -> GraphAdjList:
        """Exercise 1.4: Generates a Complete Graph K_n."""
        self._clear()
        if n <= 0: return self.adj
        vertices = [self._new_vertex() for _ in range(n)]
        for i in range(n):
            for j in range(i + 1, n):
                self._new_edge(vertices[i], vertices[j])
        return self.adj

    def generate_complete_bipartite_graph(self, p: int, q: int) -> GraphAdjList:
        """Exercise 1.4: Generates a Complete Bipartite Graph K_p,q."""
        self._clear()
        if p <= 0 or q <= 0: return self.adj
        
        # Partition X: nodes 0 to p-1
        partition_X = [self._new_vertex() for _ in range(p)]
        # Partition Y: nodes p to p+q-1
        partition_Y = [self._new_vertex() for _ in range(q)]
        
        # Connect every vertex in X to every vertex in Y
        for u in partition_X:
            for v in partition_Y:
                self._new_edge(u, v)
        return self.adj

def print_graph(graph: GraphAdjList, name: str):
    """Helper function to print a graph for verification."""
    print(f"--- {name} ---")
    if not graph:
        print("  (Empty Graph)")
        return
    for node in sorted(graph.keys()):
        print(f"  Node {node} -> {sorted(graph[node])}")
    print("--------------------")

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR EXERCISES 1.3 & 1.4
# =================================================================================
if __name__ == "__main__":
    gen = GraphGenerator()

    print("=" * 60)
    print("    Graph Generator Demo (Exercises 1.3 & 1.4)     ")
    print("=" * 60)

    # --- Exercise 1.3 ---
    print("\n--- Exercise 1.3 ---\n")
    print_graph(gen.generate_path_graph(5), "Path Graph P_5")
    print_graph(gen.generate_cycle_graph(5), "Cycle Graph C_5")
    print_graph(gen.generate_wheel_graph(5), "Wheel Graph W_5")

    # --- Exercise 1.4 ---
    print("\n--- Exercise 1.4 ---\n")
    print_graph(gen.generate_complete_graph(5), "Complete Graph K_5")
    print_graph(gen.generate_complete_bipartite_graph(3, 2), "Complete Bipartite Graph K_3,2")

    print("=" * 60)