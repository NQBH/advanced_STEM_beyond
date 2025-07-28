#include <bits/stdc++.h>
using namespace std;

/*
Input:
9 9
1 2
1 3
1 5
2 4
3 6
3 7
3 9
5 8
8 9
Output: 1 2 4 3 6 7 9 8 5
*/

int n, m;
vector<int> adj[1001];
bool visited[1001];

void inp() {
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u){
    cout<<u<<" ";
    visited[u]=true;
    for(int v : adj[u]){
        if(!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    inp();
    dfs(1);
}
