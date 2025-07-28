#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Hàm thực hiện thuật toán Tìm kiếm theo chiều rộng (BFS)
 * @param V: Tổng số đỉnh của đồ thị
 * @param adj: Danh sách kề biểu diễn đồ thị
 * @param src: Đỉnh bắt đầu duyệt
 */
void bfs(int V, const vector<vector<int>>& adj, int src) {
    // Mảng boolean để đánh dấu các đỉnh đã được thăm
    vector<bool> visited(V, false);

    // Hàng đợi (queue) cho BFS
    queue<int> q;

    // Bắt đầu từ đỉnh nguồn: đánh dấu đã thăm và thêm vào hàng đợi
    visited[src] = true;
    q.push(src);

    cout << "Ket qua duyet BFS bat dau tu dinh " << src << ": ";

    // Vòng lặp chính của thuật toán
    while (!q.empty()) {
        // Lấy một đỉnh ra khỏi hàng đợi và xử lý nó (ở đây là in ra màn hình)
        int u = q.front();
        q.pop();
        cout << u << " ";

        // Duyệt qua tất cả các đỉnh kề của đỉnh u
        for (int v : adj[u]) {
            // Nếu đỉnh kề v chưa được thăm
            if (!visited[v]) {
                // Đánh dấu nó đã được thăm và thêm vào hàng đợi
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

// Hàm main để xây dựng đồ thị và chạy thuật toán
int main() {
    int V = 7; // Ví dụ đồ thị có 7 đỉnh (từ 0 đến 6)
    
    // Biểu diễn đồ thị bằng danh sách kề
    vector<vector<int>> adj(V);

    // Hàm trợ giúp để thêm cạnh (cho đồ thị vô hướng)
    auto add_edge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    // --- Xây dựng một đồ thị ví dụ ---
    // Các cạnh của đơn đồ thị
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    add_edge(1, 4);
    add_edge(2, 5);
    add_edge(2, 6);

    // Thêm cạnh song song (để giải quyết bài toán đa đồ thị)
    // Thêm một cạnh nữa giữa đỉnh 0 và 2
    add_edge(0, 2);

    // Thêm khuyên (để giải quyết bài toán đồ thị tổng quát)
    // Đỉnh 6 có một cạnh nối với chính nó
    adj[6].push_back(6);

    // Bắt đầu duyệt từ đỉnh 0
    bfs(V, adj, 0);

    return 0;
}