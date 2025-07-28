#include <bits/stdc++.h>
using namespace std;

/*
Input:
1 7
10 8
1 2
2 3
2 4
3 6
3 7
5 8
6 7
8 9
Output:
YES
1 2 3 6 7
*/

int n, m, s, t;
vector<int> adj[1001];
bool visited[100001];
int parent[100001];

void inp() {
    cin>>s>>t;
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
}

void dfs(int u) {
    visited[u]=true;
    for(int v : adj[u]) {
        if (!visited[v])
        {
            parent[v]=u;
            dfs(v);
        }
    }
}

void path() {
    dfs(s);
    if(!visited[t]) cout<<"\nNO";
    else {
        cout<<"\nYES\n";
        vector<int>path;
        while(t!=s) {
            path.push_back(t);
            t=parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(int x : path) cout<<x<<' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    inp();
    path();
}
