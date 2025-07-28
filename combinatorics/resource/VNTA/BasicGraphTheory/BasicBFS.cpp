#include <bits/stdc++.h>
using namespace std;

/*
Input:
10 11
1 2
1 3
1 5
1 10
2 4
3 6
3 7
3 9
5 8
6 7
8 9
Output: 1 2 3 5 10 4 6 7 9 8
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

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()) {
        int v = q.front();
        cout<<v<<' ';
        q.pop();
        for(int x : adj[v]) {
            if(!visited[x]) {
                q.push(x);
                visited[x]=true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    inp();
    bfs(1);
}
