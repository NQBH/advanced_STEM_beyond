#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj; // adj[u] la danh sach ke cua dinh u
vector<bool> visited;    // danh dau dinh da tham chua
vector<int> order;       // luu thu tu cac dinh duoc duyet

// Ham DFS de quy
void dfs(int u) {
    visited[u] = true;    // danh dau da tham dinh u
    order.push_back(u);   // luu dinh u vao thu tu duyet
    for (int v : adj[u]) { 
        if (!visited[v]) { 
            dfs(v);       // goi de quy voi dinh v
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; // nhap so dinh n va so cap dinh noi voi nhau m
    adj.assign(n, {}); // khoi tao danh sach ke

    // Nhap danh sach canh
    for (int i = 0; i < m; i++) {
        int u, v, k;
        cin >> u >> v >> k; 
        // them k lan canh tu u den v
        for (int j = 0; j < k; j++) {
            adj[u].push_back(v);
            adj[v].push_back(u); // do thi vo huong
        }
    }

    visited.assign(n, false); // ban dau tat ca cac dinh chua tham
    order.clear();

    dfs(0); // thuc hien DFS bat dau tu dinh 0

    // In ra thu tu cac dinh duoc duyet
    for (int u : order) {
        cout << u << " ";
    }
    cout << "\n";

    return 0;
}