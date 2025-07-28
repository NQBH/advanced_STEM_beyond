#include <bits/stdc++.h>
using namespace std;

/*
Input:
6 6
1 2
2 3
2 4
3 5
3 6
5 6
Output:
Undirected Graph: YES. 3 5 6 3
*/

const int MAX=1e6+5;
int n, m, u, v, st, en;
vector<int> adj[MAX];
bool visited[MAX];
int parent[MAX];

void inp() {
    cin>>n>>m;
    for(int i=1; i<=m; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool dfs(int u) {
    visited[u]=true;
    for(int v : adj[u]) {
        if (!visited[v]) {
            parent[v]=u;
            if (dfs(v)) return true;
        } else if (v!=parent[u]) {
            st=v; en=u;
            return true;
        }
    }
    return false;
}

void solveDFS() {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    cout<<"\nUndirected Graph: ";
    for(int i=1; i<=n; i++) {
        if(!visited[i]){
            if(dfs(i)){
                cout<<"YES. ";
                vector<int>cycle;
                cycle.push_back(st);
                while(en!=st){
                    cycle.push_back(en);
                    en=parent[en];
                }
                cycle.push_back(st);
                reverse(cycle.begin(), cycle.end());
                for(int x:cycle){
                    cout<<x<<" ";
                }
                return;
            }
        }
    }
    cout<<"NO";
}


bool bfs(int u){
    visited[u]=true;
    queue<int>q; q.push(u);
    while(!q.empty()){
        int v=q.front(); q.pop();
        for(int x : adj[v]) {
            if(!visited[x]) {
                q.push(x);
                visited[x]=true;
                parent[x]=v;
            } else if(x!=parent[v]) {
                st=v; en=x;
                return true;
            }
        }
    }
    return false;
}

void solveBFS(){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    cout<<"\nUndirected Graph: ";
    for(int i=1; i<=n; i++) {
        if(!visited[i]){
            if(bfs(i)){
                cout<<"YES. ";
                return;
            }
        }
    }
    cout<<"NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    inp();
    solveDFS();
}
