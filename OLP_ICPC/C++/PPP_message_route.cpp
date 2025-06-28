// PPP_message_route.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
