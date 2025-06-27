#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using l = long;

const l MAX = 2e5 + 5;

l n, m, dist[MAX], pre[MAX];
vector<l> adj[MAX];
queue<l> q;

// Duyệt đồ thị theo phương thức BFS để tìm đường đi ngắn nhất từ start
void bfs(l start)
{
    fill(dist + 1, dist + 1 + n, -1); // Khởi tạo khoảng cách
    queue<l> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())  // Duyệt theo hàng đợi q gồm các đỉnh cho tới khi hết đỉnh để xử lý.
    {
        int u = q.front(); q.pop(); // Lấy đỉnh đầu tiên trong hàng đợi để xử lý và sau đó loại nó khỏi hàng đợi.
        for (int v : adj[u])    // Duyệt qua tất cả các đỉnh v kề với đỉnh u
        {
            if (dist[v] == -1)  // Đỉnh v chưa được thăm
            {
                dist[v] = dist[u] + 1;
                pre[v] = u;
                q.push(v);  // Thêm đỉnh v vào hàng đợi
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    cin >> n >> m;
    for (l i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        adj[u].emplace_back(v); // Thêm đỉnh v vào danh sách kề của u, nghĩa là u có thể đi đến v.
        adj[v].emplace_back(u); // Thêm đỉnh u vào danh sách kề của v, nghĩa là u có thể đi đến v.
    }

    bfs(1); 

    if (dist[n] == -1) 
        cout << "IMPOSSIBLE" << endl; // Không có đường đi
    else 
    {
        vector<l> path;
        for (l u = n; u; u = pre[u])
            path.push_back(u);
        reverse(path.begin(), path.end());  // Truy vết đường đi

        cout << path.size() << '\n';
        for (l u : path)
            cout << u << " ";
        cout << '\n';
    }

    return 0;
}