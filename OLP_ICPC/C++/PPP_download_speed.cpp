// PPP_download_speed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define l long

l n;   // Số máy tính 
l m;   // Số kết nối
l c;

vector<vector<l>> computers;      // Ma trận máy tính
vector<vector<l>> connections;           // Số kết nối

l BFS(l s, l t, vector<l>& parent)  // Duyệt đồ thị theo cách Breadth-first search để tìm đường tăng luồng
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<l, l>> q;
    q.push({ s, (l)1e9 });

    while (!q.empty())
    {
        l pres = q.front().first;
        l flow = q.front().second;
        q.pop();

        for (l next : connections[pres])
        {
            if (parent[next] == -1 && computers[pres][next] > 0)
            {
                parent[next] = pres;
                l new_flow = min(flow, computers[pres][next]);
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
    // Dựa trên phép duyệt BFS, sử dụng thuật toán Edmonds-Karp để tìm đường tăng luồng ngắn nhất (ít cạnh nhất)
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
            computers[prev][pres] -= new_flow;
            computers[pres][prev] += new_flow;
            pres = prev;
        }
    }
    return flow;
}

int main()
{
    cin >> n >> m;

    computers.assign(n + 1, vector<l>(n + 1, 0));
    connections.resize(n + 1);

    for (l i = 0; i < m; ++i)
    {
        l u, v;
        cin >> u >> v >> c;
        computers[u][v] += c;
        connections[u].push_back(v);
        connections[v].push_back(u);
    }

    cout << max_flow(1, n) << endl; // Tính luồng cực đại

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
