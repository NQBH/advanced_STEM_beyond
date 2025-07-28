def is_tree(graph, n_vertices):
    """Kiểm tra đồ thị có phải cây không - O(n²)"""
    
    # Đếm số cạnh
    edge_count = 0
    for i in range(n_vertices):
        for j in range(n_vertices):
            if graph[i][j]:
                edge_count += 1
    
    # Kiểm tra điều kiện cơ bản: cạnh = đỉnh - 1
    if edge_count != n_vertices - 1:
        return False, "Edge count != vertex count - 1"
    
    # Kiểm tra liên thông bằng DFS
    visited = [False] * n_vertices
    stack = [0]  # bắt đầu từ đỉnh 0
    visited_count = 0
    
    while stack:
        v = stack.pop()
        if not visited[v]:
            visited[v] = True
            visited_count += 1
            for w in range(n_vertices):
                if graph[v][w] and not visited[w]:
                    stack.append(w)
    
    # Kiểm tra tất cả đỉnh được thăm
    if visited_count != n_vertices:
        return False, "Not connected"
    
    return True, "Valid tree"

def main():
    # Test case 1: Cây hợp lệ (đường thẳng 3 đỉnh)
    tree1 = [
        [0, 1, 0],
        [1, 0, 1],
        [0, 1, 0]
    ]
    result, msg = is_tree(tree1, 3)
    print(f"Test 1 - Linear tree: {result} ({msg})")
    
    # Test case 2: Không phải cây (có chu trình)
    cycle = [
        [0, 1, 1],
        [1, 0, 1],
        [1, 1, 0]
    ]
    result, msg = is_tree(cycle, 3)
    print(f"Test 2 - Cycle: {result} ({msg})")
    
    # Test case 3: Không liên thông
    disconnected = [
        [0, 1, 0],
        [1, 0, 0],
        [0, 0, 0]
    ]
    result, msg = is_tree(disconnected, 3)
    print(f"Test 3 - Disconnected: {result} ({msg})")

if __name__ == "__main__":
    main()