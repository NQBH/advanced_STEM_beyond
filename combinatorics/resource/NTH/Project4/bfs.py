import collections

def bfs(V, adj, src):
    """
    Hàm thực hiện thuật toán Tìm kiếm theo chiều rộng (BFS)
    V: Tổng số đỉnh của đồ thị
    adj: Danh sách kề biểu diễn đồ thị
    src: Đỉnh bắt đầu duyệt
    """
    
    # Set để lưu các đỉnh đã được thăm, giúp kiểm tra nhanh hơn
    visited = set()
    
    # Hàng đợi (queue) cho BFS, sử dụng deque để có hiệu năng tốt
    queue = collections.deque()

    # Bắt đầu từ đỉnh nguồn: đánh dấu đã thăm và thêm vào hàng đợi
    visited.add(src)
    queue.append(src)

    print(f"Ket qua duyet BFS bat dau tu dinh {src}: ", end="")

    # Vòng lặp chính của thuật toán
    while queue:
        # Lấy một đỉnh ra khỏi hàng đợi và xử lý nó
        u = queue.popleft()
        print(u, end=" ")

        # Duyệt qua tất cả các đỉnh kề của đỉnh u
        for v in adj[u]:
            # Nếu đỉnh kề v chưa được thăm
            if v not in visited:
                # Đánh dấu nó đã được thăm và thêm vào hàng đợi
                visited.add(v)
                queue.append(v)
    
    print() # In một dòng mới cho đẹp

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
    # Cấu trúc giống hệt ví dụ C++ để giải quyết cả 3 bài toán
    add_edge(0, 1)
    add_edge(0, 2)
    add_edge(1, 3)
    add_edge(1, 4)
    add_edge(2, 5)
    add_edge(2, 6)

    # Thêm cạnh song song (trường hợp đa đồ thị)
    add_edge(0, 2)

    # Thêm khuyên (trường hợp đồ thị tổng quát)
    adj[6].append(6)

    # Bắt đầu duyệt từ đỉnh 0
    bfs(V, adj, 0)