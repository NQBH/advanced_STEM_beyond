#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n; 
vector<int> depth;
vector<int> parent;
vector<int> adj[2005];
int ans = 0;

int dfs(int u) {
    if (parent[u] == -1) return depth[u] = 1;
    if (depth[u] != 0) return depth[u];
    return depth[u] = 1 + dfs(parent[u]);
}

signed main() {
    
    cin >> n;
    depth.resize(n + 1, 0);
    parent.resize(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
//        if (parent[i] != -1) adj[parent[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) dfs(i);

    int ans = *max_element(depth.begin() + 1, depth.end());
    cout << ans;

}
