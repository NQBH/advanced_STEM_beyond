#include <bits/stdc++.h>
using namespace std;

int n, m; //số đỉnh và số cạnh
vector<vector<int>>adj;
vector<bool>visited;

void dfs(int u) {
    visited[u]=true;
    cout<<u<<" ";
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    adj.resize(n+1);
    visited.assign(n+1, false);
    for (int i=0; i<m; ++i) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //bỏ dòng này nếu là directed graph
    }
    int c=0;
    for(int u=1; u<=n; ++u) {
        if(!visited[u]){
            cout<<"Thanh phan lien thong "<<++c<<": ";
            dfs(u);
            cout<<"\n";
        }
    }
}

/*
Sample input:
11 12
1 2
1 3
4 5
6 7
7 8
7 9
9 10
9 11
6 6
8 10
4 3
1 2
*/
