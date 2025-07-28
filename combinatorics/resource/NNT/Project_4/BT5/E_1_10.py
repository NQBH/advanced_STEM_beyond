class ExtendedFCNS_Tree:
    """
    Implements the extended first-child, next-sibling tree representation
    using Python lists and internal node numbering.

    Nodes are represented by integer IDs (0, 1, 2, ...).
    Sentinel value for non-existent parent/child/sibling is -1.
    """

    def __init__(self):
        """
        Initializes an empty tree.
        """
        self._root = -1  # ID of the root node
        self._next_node_id = 0  # Next available ID for a new node

        # Core FCNS lists and their extensions for O(1) operations
        self._parent = []          # _parent[i] = parent ID of node i
        self._first_child = []     # _first_child[i] = first child ID of node i
        self._next_sibling = []    # _next_sibling[i] = next sibling ID of node i
        self._previous_sibling = [] # _previous_sibling[i] = previous sibling ID of node i

        # Extensions for O(1) T.number_of_children(v) and T.children(v)
        self._num_children = []    # _num_children[i] = count of children of node i
        self._children_lists = []  # _children_lists[i] = list of children IDs of node i (in order)

    def _expand_lists(self):
        """Helper to extend all internal lists for a new node."""
        self._parent.append(-1)
        self._first_child.append(-1)
        self._next_sibling.append(-1)
        self._previous_sibling.append(-1)
        self._num_children.append(0)
        self._children_lists.append([]) # Append an empty list for the new node's children

    def new_node(self):
        """
        Creates a new, unattached node and returns its ID.
        Time complexity: O(1) amortized (due to list appends)
        """
        node_id = self._next_node_id
        self._next_node_id += 1
        self._expand_lists()
        return node_id

    def set_root(self, node_id):
        """
        Sets the given node as the root of the tree.
        Assumes the tree is currently empty.
        Time complexity: O(1)
        """
        if self._root != -1:
            raise ValueError("Root already set. Cannot set a new root for a non-empty tree.")
        if node_id >= self._next_node_id or node_id < 0:
            raise IndexError("Node ID does not exist or is invalid.")
        self._root = node_id
        self._parent[node_id] = -1 # Ensure root's parent is -1

    def add_child(self, parent_id, child_id):
        """
        Adds child_id as a child of parent_id.
        Assumes parent_id and child_id are valid, existing node IDs.
        Time complexity: O(1)
        """
        if parent_id >= self._next_node_id or child_id >= self._next_node_id or \
           parent_id < 0 or child_id < 0:
            raise IndexError("Parent or child node ID out of bounds.")
        if self._parent[child_id] != -1:
            raise ValueError(f"Node {child_id} already has a parent.")
        if parent_id == child_id:
            raise ValueError("Node cannot be its own parent.")
        if self.is_root(child_id) and self.root() == child_id:
            raise ValueError(f"Node {child_id} is the root and cannot be a child.")


        # Update parent pointer for the child
        self._parent[child_id] = parent_id

        # Update parent's child count
        self._num_children[parent_id] += 1

        # Add child to parent's children_list (maintains order by append)
        self._children_lists[parent_id].append(child_id)

        # Update FCNS and previous_sibling pointers
        if self._first_child[parent_id] == -1:
            # If this is the first child of the parent
            self._first_child[parent_id] = child_id
            # Previous sibling of first child is -1 (already default)
        else:
            # The new child is added at the end of _children_lists[parent_id]
            # So, the one before it is the new child's previous sibling.
            # And the old last child's next_sibling should point to the new child.
            old_last_child_of_parent = self._children_lists[parent_id][-2]
            
            self._next_sibling[old_last_child_of_parent] = child_id
            self._previous_sibling[child_id] = old_last_child_of_parent
            # Next sibling of new child is -1 (already default)

    # --- Implement Abstract Operations from Sect. 1.3 ---

    def number_of_nodes(self):
        """
        T.number_of_nodes() gives the number of nodes |V| of tree T.
        Time complexity: O(1)
        """
        return self._next_node_id

    def root(self):
        """
        T.root() gives root[T].
        Time complexity: O(1)
        """
        return self._root

    def is_root(self, v):
        """
        T.is_root(v) is true if node v = root[T], and false otherwise.
        Time complexity: O(1)
        """
        if v < 0 or v >= self._next_node_id:
            return False # Node does not exist
        return v == self._root

    def number_of_children(self, v):
        """
        T.number_of_children(v) gives children[v].
        Time complexity: O(1)
        """
        if v < 0 or v >= self._next_node_id:
            raise IndexError("Node ID out of bounds.")
        return self._num_children[v]

    def parent(self, v):
        """
        T.parent(v) gives parent[v].
        Time complexity: O(1)
        """
        if v < 0 or v >= self._next_node_id:
            raise IndexError("Node ID out of bounds.")
        return self._parent[v]

    def children(self, v):
        """
        T.children(v) gives a list of the children of node v in T.
        Time complexity: O(1) (returns a reference to the internal list)
        """
        if v < 0 or v >= self._next_node_id:
            raise IndexError("Node ID out of bounds.")
        # Return a copy to prevent external modification of the internal list
        return list(self._children_lists[v]) 

    def is_leaf(self, v):
        """
        T.is_leaf(v) is true if node v is a leaf of T, and false otherwise.
        Time complexity: O(1)
        """
        if v < 0 or v >= self._next_node_id:
            raise IndexError("Node ID out of bounds.")
        return self._num_children[v] == 0

    def first_child(self, v):
        """
        T.first_child(v) gives the first child of node v, or -1 if v is a leaf.
        Time complexity: O(1)
        """
        if v < 0 or v >= self._next_node_id:
            raise IndexError("Node ID out of bounds.")
        return self._first_child[v]

    def last_child(self, v):
        """
        T.last_child(v) gives the last child of node v, or -1 if v is a leaf.
        Time complexity: O(1)
        """
        if v < 0 or v >= self._next_node_id:
            raise IndexError("Node ID out of bounds.")
        if self._num_children[v] == 0:
            return -1
        return self._children_lists[v][-1] # Get last element from the children list

    def previous_sibling(self, v):
        """
        T.previous_sibling(v) gives the previous child of T.parent(v) before v.
        Returns -1 if v is the first child or has no parent.
        Time complexity: O(1)
        """
        if v < 0 or v >= self._next_node_id:
            raise IndexError("Node ID out of bounds.")
        return self._previous_sibling[v]

    def next_sibling(self, v):
        """
        T.next_sibling(v) gives the next child of T.parent(v) after v.
        Returns -1 if v is the last child.
        Time complexity: O(1)
        """
        if v < 0 or v >= self._next_node_id:
            raise IndexError("Node ID out of bounds.")
        return self._next_sibling[v]

    def is_first_child(self, v):
        """
        T.is_first_child(v) is true if node v is the first child of its parent.
        Time complexity: O(1)
        """
        if v < 0 or v >= self._next_node_id:
            raise IndexError("Node ID out of bounds.")
        parent_v = self._parent[v]
        if parent_v == -1: # Is root or doesn't exist
            return False
        return self._first_child[parent_v] == v

    def is_last_child(self, v):
        """
        T.is_last_child(v) is true if node v is the last child of its parent.
        Time complexity: O(1)
        """
        if v < 0 or v >= self._next_node_id:
            raise IndexError("Node ID out of bounds.")
        parent_v = self._parent[v]
        if parent_v == -1: # Is root or doesn't exist
            return False
        return self._children_lists[parent_v] and self._children_lists[parent_v][-1] == v