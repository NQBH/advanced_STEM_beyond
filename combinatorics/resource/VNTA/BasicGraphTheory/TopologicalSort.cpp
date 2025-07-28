#include <bits/stdc++.h>
using namespace std;

/*
Input:
7 7
1 2
1 6
2 3
2 4
3 5
4 5
7 6
Output:
DFS: 7 1 6 2 4 3 5
Kahn: 1 7 2 6 3 4 5
*/

const int MAX=1e6+5;
int n, m, u, v;
vector<int> adj[MAX];
bool visited[MAX];
vector<int> topoDFS, topoKahn;
int degIn[MAX];

void inp() {
    cin>>n>>m;
    for(int i=1; i<=m; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        degIn[v]++;
    }
}

void dfs(int u) {
    visited[u]=true;
    for(int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
    topoDFS.push_back(u);
}

void kahn() {
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(degIn[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int u=q.front(); q.pop();
        topoKahn.push_back(u);
        for (int v : adj[u]) {
            degIn[v]--;
            if(degIn[v]==0) q.push(v);
        }
    }
    cout<<"\nKahn: ";
    for(int x : topoKahn) cout<<x<<' ';
}

void solve() {
    inp();

    //DFS
    memset(visited, false, sizeof(visited));
    for(int i=1; i<=n; i++) {
        if(!visited[i]) dfs(i);
    }
    reverse(topoDFS.begin(), topoDFS.end());
    cout<<"\nDFS: ";
    for(int x : topoDFS) cout<<x<<' ';

    //Kahn
    kahn();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}
