#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
vector<int>adj[MAXN];
vector<bool>visited(MAXN);
bool hasCycle=false;

void dfs(int u, int parent) {
    visited[u]=true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, u);
        } else if (v!=parent) {
            hasCycle=true;
        }
    }
}

bool isTree(int n, int m) {
    if (m!=n-1) return false;
    dfs(0, -1);
    for (int i=0; i<n; ++i) {
        if (!visited[i]) return false;
    }
    return !hasCycle;
}

int main() {
    int n, m;
    cin>>n>>m;

    for (int i=0; i<m; ++i) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isTree(n,m)) cout<<"YES, this is a tree.";
    else cout<<"NO, this is not a tree.";
    return 0;
}
