#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
bool check[1000001];
vector<int> G[100001], lead;

void dfs(int u)
{
    check[u] = true;
    for(int v : G[u])
        if(!check[v]) dfs(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i=1; i <= n; ++i)
        if(!check[i])
        {
            ans++;
            lead.push_back(i);
            dfs(i);
        }
    
    cout << ans - 1 << '\n';
    if(ans > 1)
    {
        int u = lead[0];
        int v;
        for(int i=1; i < ans; ++i)
        {
            v = lead[i];
            cout << u << ' ' << v << '\n';
            u = v;
        }
    }
    return 0;
}