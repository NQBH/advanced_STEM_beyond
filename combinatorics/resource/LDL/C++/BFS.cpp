#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj; // adj[u] la danh sach ke cua dinh u

vector<int> bfs(int start) {
    vector<bool> visited(n, false); // danh dau cac dinh da tham
    queue<int> q;                   // hang doi de luu cac dinh se duyet
    vector<int> order;              // luu thu tu duyet cac dinh

    visited[start] = true; // danh dau dinh bat dau
    q.push(start);         // dua dinh bat dau vao hang doi

    while (!q.empty()) {
        int u = q.front(); // lay dinh o dau hang doi
        q.pop();
        order.push_back(u); // ghi nhan thu tu duyet

        // duyet tat ca cac dinh ke voi u
        for (int v : adj[u]) {
            if (!visited[v]) {        // neu v chua duoc tham
                visited[v] = true;    // danh dau v
                q.push(v);            // dua v vao hang doi
            }
        }
    }
    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; // nhap so dinh va so cap dinh noi voi nhau
    adj.assign(n, {}); // khoi tao danh sach ke

    for (int i = 0; i < m; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        // them k lan canh tu u den v
        for (int j = 0; j < k; j++) {
            adj[u].push_back(v);
            adj[v].push_back(u); // do thi vo huong
        }
    }

    int start_node = 0; // bat dau BFS tu dinh 0
    vector<int> result = bfs(start_node);

    // in ra thu tu duyet
    for (int u : result) {
        cout << u << " ";
    }
    cout << "\n";

    return 0;
}