import math

class GraphAdjacencyMatrix:
    """
    Implements a graph using an adjacency matrix representation.
    Vertices are represented by internal integer indices starting from 0.
    Edges are represented by (source_vertex_idx, target_vertex_idx) tuples.
    """

    def __init__(self):
        """
        Initializes an empty graph.
        """
        self.adj_matrix = []  # List of lists representing the adjacency matrix
        self.num_vertices = 0
        self.num_edges = 0
        # For simplicity, vertex "objects" are their integer indices.
        # If actual vertex objects were needed, a list like self._vertices = []
        # would store them, and new_vertex would add to this list.

    def _resize_matrix(self, new_size):
        """
        Resizes the adjacency matrix to accommodate new_size vertices.
        Initializes new cells to 0.
        """
        # Add new rows
        for _ in range(new_size - len(self.adj_matrix)):
            self.adj_matrix.append([0] * len(self.adj_matrix))
        # Add new columns to all rows
        for i in range(len(self.adj_matrix)):
            while len(self.adj_matrix[i]) < new_size:
                self.adj_matrix[i].append(0)

    # --- Vertex and Edge Creation/Deletion Operations ---

    def new_vertex(self):
        """
        Inserts a new vertex in graph G. Returns its internal index.
        """
        new_vertex_id = self.num_vertices
        self.num_vertices += 1
        self._resize_matrix(self.num_vertices)
        # Ensure new row/column for new vertex is all zeros
        # (handled by _resize_matrix when expanding)
        return new_vertex_id

    def new_edge(self, u, v):
        """
        Inserts a new edge in graph G going out of vertex u and coming into vertex v.
        Assumes u and v are valid internal vertex indices.
        """
        if u < 0 or u >= self.num_vertices or v < 0 or v >= self.num_vertices:
            raise IndexError("Vertex index out of bounds.")
        if self.adj_matrix[u][v] == 0:
            self.adj_matrix[u][v] = 1
            self.num_edges += 1
        # If edge already exists, do nothing (for simple graph)
        return (u, v) # Return the edge representation

    def del_vertex(self, v):
        """
        Deletes vertex v from graph G, together with all those edges going
        out of or coming into vertex v. This implementation conceptually removes
        the vertex by setting all its incident edges to 0 and marking it
        as inactive. It does NOT re-index subsequent vertices, which would
        be complex for a raw adjacency matrix.
        For a true "delete and re-index", a new matrix would often be built.
        """
        if v < 0 or v >= self.num_vertices:
            raise IndexError("Vertex index out of bounds.")

        # Mark all outgoing edges from v as deleted
        for col in range(self.num_vertices):
            if self.adj_matrix[v][col] == 1:
                self.adj_matrix[v][col] = 0
                self.num_edges -= 1

        # Mark all incoming edges to v as deleted
        for row in range(self.num_vertices):
            if self.adj_matrix[row][v] == 1:
                self.adj_matrix[row][v] = 0
                self.num_edges -= 1
        
        # Conceptually, vertex v is now "deleted" or "inactive".
        # For this simplified adjacency matrix, we don't shrink the matrix
        # or re-index other vertices. Operations like `vertices()` should
        # ideally filter out deleted vertices if a more robust deletion
        # mechanism (e.g., using a boolean `active_vertices` list) were implemented.
        # For simplicity, we just zero out connections.
        
        # If a strict re-indexing of vertices (e.g., v becomes the next available index)
        # is required, this method needs a complete overhaul, likely involving
        # building a new matrix and mapping old indices to new ones.
        # For the scope of this exercise, zeroing out connections is sufficient.


    def del_edge(self, u, v):
        """
        Deletes edge (u, v) from graph G.
        """
        if u < 0 or u >= self.num_vertices or v < 0 or v >= self.num_vertices:
            raise IndexError("Vertex index out of bounds.")
        if self.adj_matrix[u][v] == 1:
            self.adj_matrix[u][v] = 0
            self.num_edges -= 1

    # --- Graph Information Operations ---

    def vertices(self):
        """
        G.vertices() gives a list of the vertices of graph G in order.
        Returns active vertex indices.
        """
        return list(range(self.num_vertices)) # Assuming all created vertices are "active" unless del_vertex handles state

    def edges(self):
        """
        G.edges() gives a list of the edges of graph G in order fixed by the representation.
        Returns edges as (source, target) tuples.
        """
        edge_list = []
        for u in range(self.num_vertices):
            for v in range(self.num_vertices):
                if self.adj_matrix[u][v] == 1:
                    edge_list.append((u, v))
        return edge_list

    def number_of_vertices(self):
        """
        G.number_of_vertices() gives the order n of graph G.
        """
        return self.num_vertices

    def number_of_edges(self):
        """
        G.number_of_edges() gives the size m of graph G.
        """
        return self.num_edges

    # --- Vertex-Specific Information Operations ---

    def incoming(self, v):
        """
        G.incoming(v) gives a list of the edges of graph G coming into vertex v.
        Returns a list of source vertices.
        """
        if v < 0 or v >= self.num_vertices:
            raise IndexError("Vertex index out of bounds.")
        incoming_sources = []
        for u in range(self.num_vertices):
            if self.adj_matrix[u][v] == 1:
                incoming_sources.append(u)
        return incoming_sources

    def outgoing(self, v):
        """
        G.outgoing(v) gives a list of the edges of graph G going out of vertex v.
        Returns a list of target vertices.
        """
        if v < 0 or v >= self.num_vertices:
            raise IndexError("Vertex index out of bounds.")
        outgoing_targets = []
        for w in range(self.num_vertices):
            if self.adj_matrix[v][w] == 1:
                outgoing_targets.append(w)
        return outgoing_targets

    def indeg(self, v):
        """
        G.indeg(v) gives the number of edges coming into vertex v in graph G.
        """
        return len(self.incoming(v))

    def outdeg(self, v):
        """
        G.outdeg(v) gives the number of edges going out of vertex v in graph G.
        """
        return len(self.outgoing(v))

    def adjacent(self, u, v):
        """
        G.adjacent(v, w) is true if there is an edge in graph G going out of
        vertex v and coming into vertex w, and false otherwise.
        """
        if u < 0 or u >= self.num_vertices or v < 0 or v >= self.num_vertices:
            return False # Or raise IndexError, depending on desired behavior
        return self.adj_matrix[u][v] == 1

    # --- Edge Source/Target Operations (Extended from Problem 1.4) ---

    def source(self, edge):
        """
        G.source(e) gives the source vertex of edge e.
        Edge e is represented as a (source, target) tuple.
        """
        return edge[0]

    def target(self, edge):
        """
        G.target(e) gives the target vertex of edge e.
        Edge e is represented as a (source, target) tuple.
        """
        return edge[1]

    def opposite(self, v, edge):
        """
        G.opposite(v, e) gives G.target(e) if vertex v is the source of edge e,
        and G.source(e) otherwise.
        """
        s, t = edge
        if v == s:
            return t
        elif v == t:
            return s
        else:
            raise ValueError("Vertex v is not part of the given edge.")

    # --- Traversal and Iteration Operations (Simplified for Adjacency Matrix) ---
    # These operations are more natural for linked-list representations.
    # For adjacency matrix, they typically involve iterating through the matrix
    # to find the "first", "last", "predecessor", or "successor" based on index order.

    def first_vertex(self):
        """
        G.first_vertex() gives the first vertex in the representation of graph G.
        """
        if self.num_vertices == 0:
            return None
        return 0 # Assuming vertices are numbered 0, 1, 2, ...

    def last_vertex(self):
        """
        G.last_vertex() gives the last vertex in the representation of graph G.
        """
        if self.num_vertices == 0:
            return None
        return self.num_vertices - 1

    def pred_vertex(self, v):
        """
        G.pred_vertex(v) gives the predecessor of vertex v in the representation of graph G.
        """
        if v <= 0 or v >= self.num_vertices:
            return None # No predecessor or out of bounds
        return v - 1

    def succ_vertex(self, v):
        """
        G.succ_vertex(v) gives the successor of vertex v in the representation of graph G.
        """
        if v < 0 or v >= self.num_vertices - 1:
            return None # No successor or out of bounds
        return v + 1

    def first_edge(self):
        """
        G.first_edge() gives the first edge in the representation of graph G.
        (Based on row-major iteration of the adjacency matrix)
        """
        for u in range(self.num_vertices):
            for v in range(self.num_vertices):
                if self.adj_matrix[u][v] == 1:
                    return (u, v)
        return None

    def last_edge(self):
        """
        G.last_edge() gives the last edge in the representation of graph G.
        (Based on reverse row-major iteration of the adjacency matrix)
        """
        for u in range(self.num_vertices - 1, -1, -1):
            for v in range(self.num_vertices - 1, -1, -1):
                if self.adj_matrix[u][v] == 1:
                    return (u, v)
        return None
    
    def _find_edge_index(self, edge):
        """Helper to find the linear index of an edge in a flattened list of all edges."""
        all_edges = self.edges()
        try:
            return all_edges.index(edge)
        except ValueError:
            return -1 # Not found

    def pred_edge(self, edge):
        """
        G.pred_edge(e) gives the predecessor of edge e.
        (Based on position in the list returned by G.edges())
        """
        all_edges = self.edges()
        idx = self._find_edge_index(edge)
        if idx > 0:
            return all_edges[idx - 1]
        return None

    def succ_edge(self, edge):
        """
        G.succ_edge(e) gives the successor of edge e.
        (Based on position in the list returned by G.edges())
        """
        all_edges = self.edges()
        idx = self._find_edge_index(edge)
        if idx != -1 and idx < len(all_edges) - 1:
            return all_edges[idx + 1]
        return None

    def first_in_edge(self, v):
        """
        G.first_in_edge(v) gives the first edge coming into vertex v.
        Returns (source, target) tuple.
        """
        if v < 0 or v >= self.num_vertices:
            return None
        for u in range(self.num_vertices):
            if self.adj_matrix[u][v] == 1:
                return (u, v)
        return None

    def last_in_edge(self, v):
        """
        G.last_in_edge(v) gives the last edge coming into vertex v.
        Returns (source, target) tuple.
        """
        if v < 0 or v >= self.num_vertices:
            return None
        for u in range(self.num_vertices - 1, -1, -1):
            if self.adj_matrix[u][v] == 1:
                return (u, v)
        return None

    def _find_in_edge_index(self, edge):
        """Helper to find the index of an incoming edge for its target vertex."""
        target_v = edge[1]
        incoming_edges_for_target = []
        for u in range(self.num_vertices):
            if self.adj_matrix[u][target_v] == 1:
                incoming_edges_for_target.append((u, target_v))
        try:
            return incoming_edges_for_target.index(edge)
        except ValueError:
            return -1

    def in_pred(self, edge):
        """
        G.in_pred(e) gives the previous edge after e in the representation of graph G
        coming into vertex G.target(e).
        """
        target_v = edge[1]
        incoming_edges_for_target = []
        for u in range(self.num_vertices):
            if self.adj_matrix[u][target_v] == 1:
                incoming_edges_for_target.append((u, target_v))
        
        idx = self._find_in_edge_index(edge)
        if idx > 0:
            return incoming_edges_for_target[idx - 1]
        return None


    def in_succ(self, edge):
        """
        G.in_succ(e) gives the next edge after e in the representation of graph G
        coming into vertex G.target(e).
        """
        target_v = edge[1]
        incoming_edges_for_target = []
        for u in range(self.num_vertices):
            if self.adj_matrix[u][target_v] == 1:
                incoming_edges_for_target.append((u, target_v))
        
        idx = self._find_in_edge_index(edge)
        if idx != -1 and idx < len(incoming_edges_for_target) - 1:
            return incoming_edges_for_target[idx + 1]
        return None

    def first_adj_edge(self, v):
        """
        G.first_adj_edge(v) gives the first edge going out of vertex v.
        Returns (source, target) tuple.
        """
        if v < 0 or v >= self.num_vertices:
            return None
        for w in range(self.num_vertices):
            if self.adj_matrix[v][w] == 1:
                return (v, w)
        return None

    def last_adj_edge(self, v):
        """
        G.last_adj_edge(v) gives the last edge going out of vertex v.
        Returns (source, target) tuple.
        """
        if v < 0 or v >= self.num_vertices:
            return None
        for w in range(self.num_vertices - 1, -1, -1):
            if self.adj_matrix[v][w] == 1:
                return (v, w)
        return None

    def _find_adj_edge_index(self, edge):
        """Helper to find the index of an outgoing edge for its source vertex."""
        source_u = edge[0]
        outgoing_edges_from_source = []
        for w in range(self.num_vertices):
            if self.adj_matrix[source_u][w] == 1:
                outgoing_edges_from_source.append((source_u, w))
        try:
            return outgoing_edges_from_source.index(edge)
        except ValueError:
            return -1

    def adj_pred(self, edge):
        """
        G.adj_pred(e) gives the previous edge after e in the representation of graph G
        going out of vertex G.source(e).
        """
        source_u = edge[0]
        outgoing_edges_from_source = []
        for w in range(self.num_vertices):
            if self.adj_matrix[source_u][w] == 1:
                outgoing_edges_from_source.append((source_u, w))
        
        idx = self._find_adj_edge_index(edge)
        if idx > 0:
            return outgoing_edges_from_source[idx - 1]
        return None

    def adj_succ(self, edge):
        """
        G.adj_succ(e) gives the next edge after e in the representation of graph G
        going out of vertex G.source(e).
        """
        source_u = edge[0]
        outgoing_edges_from_source = []
        for w in range(self.num_vertices):
            if self.adj_matrix[source_u][w] == 1:
                outgoing_edges_from_source.append((source_u, w))
        
        idx = self._find_adj_edge_index(edge)
        if idx != -1 and idx < len(outgoing_edges_from_source) - 1:
            return outgoing_edges_from_source[idx + 1]
        return None