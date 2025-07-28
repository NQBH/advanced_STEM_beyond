#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Sử dụng pair để lưu {trọng số, đỉnh}
// Dùng cho hàng đợi ưu tiên để sắp xếp theo trọng số
using namespace std;
typedef pair<int, int> iPair;

// Hàm cài đặt thuật toán Dijkstra
void dijkstra(int V, const vector<vector<iPair>>& adj, int src) {
    // Hàng đợi ưu tiên để lưu {khoảng cách, đỉnh}
    // greater<iPair> biến nó thành một min-heap (ưu tiên phần tử nhỏ nhất)
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Mảng lưu khoảng cách, khởi tạo tất cả là vô cùng
    vector<int> dist(V, numeric_limits<int>::max());

    // Thêm đỉnh nguồn vào hàng đợi và đặt khoảng cách của nó là 0
    pq.push({0, src});
    dist[src] = 0;

    // Vòng lặp chính của thuật toán
    while (!pq.empty()) {
        // Lấy đỉnh u có khoảng cách nhỏ nhất ra khỏi hàng đợi
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        // Nếu khoảng cách đã lấy ra lớn hơn khoảng cách đã lưu,
        // đây là một bản ghi cũ, ta bỏ qua.
        if (d > dist[u]) {
            continue;
        }

        // Duyệt qua tất cả các đỉnh kề của u
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Bước "Thư giãn" (Relaxation):
            // Nếu tìm thấy đường đi ngắn hơn đến v thông qua u
            if (dist[u] + weight < dist[v]) {
                // Cập nhật khoảng cách mới cho v
                dist[v] = dist[u] + weight;
                // Thêm cặp {khoảng cách mới, v} vào hàng đợi
                pq.push({dist[v], v});
            }
        }
    }

    // In kết quả
    cout << "Khoang cach ngan nhat tu dinh nguon " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "Dinh " << i << ": khong toi duoc\n";
        } else {
            cout << "Dinh " << i << ": " << dist[i] << "\n";
        }
    }
}

// Hàm main để chạy ví dụ
int main() {
    int V = 6; // Số đỉnh
    vector<vector<iPair>> adj(V);

    // Thêm các cạnh vào đồ thị
    // adj[u].push_back({v, weight});
    adj[0].push_back({1, 4});
    adj[1].push_back({0, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});
    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 5});
    adj[3].push_back({1, 5});
    adj[2].push_back({4, 3});
    adj[4].push_back({2, 3});
    adj[3].push_back({4, 1});
    adj[4].push_back({3, 1});
    adj[4].push_back({5, 2});
    adj[5].push_back({4, 2});

    // Thêm cạnh song song (trường hợp đa đồ thị)
    adj[0].push_back({2, 10});
    adj[2].push_back({0, 10});

    // Thêm khuyên (trường hợp đồ thị tổng quát)
    adj[5].push_back({5, 7});

    int source_vertex = 0;
    dijkstra(V, adj, source_vertex);

    return 0;
}