import collections

def dfs(V, adj, src):
    """
    Hàm thực hiện thuật toán Tìm kiếm theo chiều sâu (DFS)
    V: Tổng số đỉnh của đồ thị
    adj: Danh sách kề biểu diễn đồ thị
    src: Đỉnh bắt đầu duyệt
    """
    
    # Set để lưu các đỉnh đã được thăm
    visited = set()
    
    print(f"Ket qua duyet DFS bat dau tu dinh {src}: ", end="")

    # Hàm đệ quy nội bộ
    def dfs_recursive(u):
        # Đánh dấu đỉnh hiện tại đã thăm và xử lý nó
        visited.add(u)
        print(u, end=" ")

        # Duyệt qua tất cả các đỉnh kề của đỉnh u
        for v in adj[u]:
            # Nếu đỉnh kề v chưa được thăm, gọi đệ quy
            if v not in visited:
                dfs_recursive(v)

    # Bắt đầu quá trình đệ quy từ đỉnh nguồn
    dfs_recursive(src)
    print() # In một dòng mới

# Hàm main để xây dựng đồ thị và chạy thuật toán
if __name__ == "__main__":
    V = 7  # Ví dụ đồ thị có 7 đỉnh (từ 0 đến 6)
    
    # Biểu diễn đồ thị bằng danh sách kề (list of lists)
    adj = [[] for _ in range(V)]

    # Hàm trợ giúp để thêm cạnh (cho đồ thị vô hướng)
    def add_edge(u, v):
        adj[u].append(v)
        adj[v].append(u)

    # --- Xây dựng một đồ thị ví dụ ---
    add_edge(0, 1)
    add_edge(0, 2)
    add_edge(1, 3)
    add_edge(1, 4)
    add_edge(2, 5)
    add_edge(2, 6)
    add_edge(0, 2) # Cạnh song song
    adj[6].append(6) # Khuyên

    # Bắt đầu duyệt từ đỉnh 0
    dfs(V, adj, 0)