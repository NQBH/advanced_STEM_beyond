// PPP_police_chase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define l long

l n, m;
vector<vector<l>> crossings;      // Ma trận crossings
vector<vector<l>> adj;           // Danh sách kề

l BFS(l s, l t, vector<l>& parent)  // Duyệt đồ thị theo cách Breadth-first search để tìm đường tăng luồng
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<l, l>> q;
    q.push({ s, (l)1e3 });

    while (!q.empty())
    {
        l cur = q.front().first;
        l flow = q.front().second;
        q.pop();

        for (l next : adj[cur])
        {
            if (parent[next] == -1 && crossings[cur][next] > 0)
            {
                parent[next] = cur;
                l new_flow = min(flow, crossings[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({ next, new_flow });
            }
        }
    }
    return 0;
}

l max_flow(l s, l t)    // Tìm max_flow sử dụng thuật toán Edmonds-Karp
{
    l flow = 0;
    vector<l> parent(n + 1);
    l new_flow;

    while ((new_flow = BFS(s, t, parent)))
    {
        flow += new_flow;
        l pres = t;
        while (pres != s)
        {
            l prev = parent[pres];
            crossings[prev][pres] -= new_flow;
            crossings[pres][prev] += new_flow;
            pres = prev;
        }
    }
    return flow;
}

void DFS(l u, vector<bool>& visited)    // Phân vùng đồ thị và xác định cạnh cắt cực tiểu (min_cut)
{
    visited[u] = true;
    for (l v : adj[u])
    {
        if (!visited[v] && crossings[u][v] > 0)
            DFS(v, visited);
    }
}

int main()
{
    cin >> n >> m;

    crossings.assign(n + 1, vector<l>(n + 1, 0));
    adj.resize(n + 1);

    for (l i = 0; i < m; ++i)
    {
        l u, v;
        cin >> u >> v;
        crossings[u][v] += 1;
        crossings[v][u] += 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    max_flow(1, n); // Tính luồng cực đại

    vector<bool> visited(n + 1, false);
    DFS(1, visited); // Đánh dấu các đỉnh có thể đến được từ 1 sau khi cắt

    vector<pair<l, l>> min_cut; // Cạnh cắt cực tiểu

    for (l u = 1; u <= n; ++u)
    {
        if (visited[u])
        {
            for (l v : adj[u])
            {
                if (!visited[v] && crossings[u][v] == 0 && crossings[v][u] >= 1)
                    min_cut.emplace_back(u, v);
            }
        }
    }

    cout << min_cut.size() << '\n';
    for (auto edge : min_cut)
        cout << edge.first << " " << edge.second << '\n';

    return 0;
}
