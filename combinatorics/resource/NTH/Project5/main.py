import heapq
import sys

# Hàm cài đặt thuật toán Dijkstra
def dijkstra(V, adj, src):
    """
    V: Số đỉnh
    adj: Danh sách kề biểu diễn đồ thị
    src: Đỉnh nguồn
    """
    
    # Mảng lưu khoảng cách, khởi tạo tất cả là vô cùng
    # sys.maxsize hoạt động như INT_MAX trong C++
    dist = [sys.maxsize] * V

    # Hàng đợi ưu tiên để lưu (khoảng cách, đỉnh)
    pq = [(0, src)]
    
    # Đặt khoảng cách của đỉnh nguồn là 0
    dist[src] = 0

    while pq:
        # Lấy đỉnh u có khoảng cách nhỏ nhất ra khỏi hàng đợi
        # d là khoảng cách, u là đỉnh
        d, u = heapq.heappop(pq)

        # Nếu khoảng cách đã lấy ra lớn hơn khoảng cách đã lưu,
        # đây là một bản ghi cũ, ta bỏ qua.
        if d > dist[u]:
            continue

        # Duyệt qua tất cả các đỉnh kề của u
        for v, weight in adj[u]:
            # Bước "Thư giãn" (Relaxation):
            # Nếu tìm thấy đường đi ngắn hơn đến v thông qua u
            if dist[u] + weight < dist[v]:
                # Cập nhật khoảng cách mới cho v
                dist[v] = dist[u] + weight
                # Thêm cặp {khoảng cách mới, v} vào hàng đợi
                heapq.heappush(pq, (dist[v], v))

    # In kết quả
    print(f"Khoang cach ngan nhat tu dinh nguon {src}:")
    for i in range(V):
        if dist[i] == sys.maxsize:
            print(f"Dinh {i}: khong toi duoc")
        else:
            print(f"Dinh {i}: {dist[i]}")

# Hàm main để chạy ví dụ
if __name__ == "__main__":
    V = 6  # Số đỉnh
    # Danh sách kề, adj[i] chứa danh sách các (đỉnh kề, trọng số) của i
    adj = [[] for _ in range(V)]

    # Thêm các cạnh vào đồ thị
    # Cấu trúc giống hệt ví dụ C++
    adj[0].append((1, 4))
    adj[1].append((0, 4))
    adj[0].append((2, 1))
    adj[2].append((0, 1))
    adj[1].append((2, 2))
    adj[2].append((1, 2))
    adj[1].append((3, 5))
    adj[3].append((1, 5))
    adj[2].append((4, 3))
    adj[4].append((2, 3))
    adj[3].append((4, 1))
    adj[4].append((3, 1))
    adj[4].append((5, 2))
    adj[5].append((4, 2))

    # Thêm cạnh song song (trường hợp đa đồ thị)
    adj[0].append((2, 10))
    adj[2].append((0, 10))

    # Thêm khuyên (trường hợp đồ thị tổng quát)
    adj[5].append((5, 7))

    source_vertex = 0
    dijkstra(V, adj, source_vertex)