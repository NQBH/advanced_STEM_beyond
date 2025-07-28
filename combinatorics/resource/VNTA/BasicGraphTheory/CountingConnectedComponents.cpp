#include <bits/stdc++.h>
using namespace std;

/*
Input:
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
Connected Component 1 : 1 2 3 6 7 4
Connected Component 2 : 5 8 9
Connected Component 3 : 10
The number of connected components: 3
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

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()) {
        int v = q.front();
        //cout<<v<<' ';
        q.pop();
        for(int x : adj[v]) {
            if(!visited[x]) {
                q.push(x);
                visited[x]=true;
            }
        }
    }
}

void ConnectedComponents(){
    int cnt=0;
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            cnt++;
            cout<<"\nConnected Component "<<cnt<<" : ";
            dfs(i);
            //bfs(i);
        }
    }
    cout<<"\nThe number of connected components: "<<cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    inp();
    ConnectedComponents();
}
