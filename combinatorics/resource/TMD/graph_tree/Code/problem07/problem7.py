# problem7.py
# Full implementation for various tree traversal algorithms on a binary tree.

from collections import deque

class TreeNode:
    """A node in a binary tree."""
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

# --- (a) Pre-order Traversal (DFS: Root -> Left -> Right) ---
def preorder_traversal(node):
    """
    Performs a pre-order traversal on the tree rooted at 'node'.
    
    Args:
        node (TreeNode): The root of the tree/subtree to traverse.

    Returns:
        list: A list of node values in pre-order.
    """
    if not node:
        return []
    # Visit the root, then traverse the left subtree, then the right subtree.
    return [node.value] + preorder_traversal(node.left) + preorder_traversal(node.right)

# --- (b) Post-order Traversal (DFS: Left -> Right -> Root) ---
def postorder_traversal(node):
    """
    Performs a post-order traversal on the tree rooted at 'node'.
    
    Args:
        node (TreeNode): The root of the tree/subtree to traverse.

    Returns:
        list: A list of node values in post-order.
    """
    if not node:
        return []
    # Traverse the left subtree, then the right subtree, and finally visit the root.
    return postorder_traversal(node.left) + postorder_traversal(node.right) + [node.value]

# --- (c) Top-down Traversal (BFS / Level-order) ---
def top_down_traversal(root):
    """
    Performs a top-down (level-order) traversal using a queue (BFS).
    
    Args:
        root (TreeNode): The root of the tree.

    Returns:
        list: A list of node values in level-order.
    """
    if not root:
        return []
    
    result = []
    queue = deque([root]) # Use a deque for an efficient queue implementation
    
    while queue:
        node = queue.popleft() # Dequeue the node at the front
        result.append(node.value)
        
        # Enqueue left child if it exists
        if node.left:
            queue.append(node.left)
            
        # Enqueue right child if it exists
        if node.right:
            queue.append(node.right)
            
    return result

# --- (d) Bottom-up Traversal (Reverse Level-order) ---
def bottom_up_traversal(root):
    """
    Performs a bottom-up (reverse level-order) traversal.
    This implementation first performs a level-order traversal, storing each level,
    and then constructs the final result by reversing the order of the levels.
    
    Args:
        root (TreeNode): The root of the tree.

    Returns:
        list: A list of node values in bottom-up order.
    """
    if not root:
        return []
    
    levels = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        current_level = []
        for _ in range(level_size):
            node = queue.popleft()
            current_level.append(node.value)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        levels.append(current_level)
    
    # Flatten the list of levels in reverse order.
    result = []
    for level in reversed(levels):
        result.extend(level)
        
    return result

def main():
    """Main function to build the example tree and demonstrate the traversals."""
    # Constructing the example tree:
    #         F
    #        / \
    #       B   G
    #      / \   \
    #     A   D   I
    #        / \ /
    #       C  E H
    root = TreeNode('F')
    root.left = TreeNode('B')
    root.right = TreeNode('G')
    root.left.left = TreeNode('A')
    root.left.right = TreeNode('D')
    root.left.right.left = TreeNode('C')
    root.left.right.right = TreeNode('E')
    root.right.right = TreeNode('I')
    root.right.right.left = TreeNode('H')

    print("--- Problem 7: Tree Traversals ---")
    print("For the following tree structure:")
    print("        F\n       / \\\n      B   G\n     / \\   \\\n    A   D   I\n       / \\ /\n      C  E H\n")
    
    # (a) Pre-order
    preorder_res = preorder_traversal(root)
    print(f"(a) Pre-order Traversal:  {preorder_res}")
    
    # (b) Post-order
    postorder_res = postorder_traversal(root)
    print(f"(b) Post-order Traversal: {postorder_res}")

    # (c) Top-down
    top_down_res = top_down_traversal(root)
    print(f"(c) Top-down Traversal:   {top_down_res}")

    # (d) Bottom-up
    bottom_up_res = bottom_up_traversal(root)
    print(f"(d) Bottom-up Traversal:  {bottom_up_res}")

if __name__ == "__main__":
    main()