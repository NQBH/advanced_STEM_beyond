#include <iostream>
#include <vector>
#include <functional>


using namespace std;

/**
 * Hàm thực hiện thuật toán Tìm kiếm theo chiều sâu (DFS) bằng đệ quy
 * V :Tổng số đỉnh của đồ thị
 * adj: Danh sách kề biểu diễn đồ thị
 * src: Đỉnh bắt đầu duyệt
 */
void dfs(int V, const vector<vector<int>>& adj, int src) {
    // Mảng boolean để đánh dấu các đỉnh đã được thăm
    vector<bool> visited(V, false);

    cout << "Ket qua duyet DFS bat dau tu dinh " << src << ": ";

    
    function<void(int)> dfs_recursive = 
        [&](int u) {
        
        visited[u] = true;
        cout << u << " ";

        // Duyệt qua tất cả các đỉnh kề của đỉnh u
        for (int v : adj[u]) {
            // Nếu đỉnh kề v chưa được thăm, gọi đệ quy
            if (!visited[v]) {
                dfs_recursive(v);
            }
        }
    };

    // Bắt đầu quá trình đệ quy từ đỉnh nguồn
    dfs_recursive(src);
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
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    add_edge(1, 4);
    add_edge(2, 5);
    add_edge(2, 6);
    add_edge(0, 2); // Cạnh song song
    adj[6].push_back(6); // Khuyên

    // Bắt đầu duyệt từ đỉnh 0
    dfs(V, adj, 0);

    return 0;
}