#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+5;
int n, m, u, v;
vector<int> adj[MAX];
bool visited[MAX];
vector<int>res;

void inp() {
    cin>>n>>m;
    for(int i=1; i<=m; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u) {
    visited[u]=true;
    for(int v : adj[u]) {
        if(!visited[v]) dfs(v);
    }
}

void solve() {
    inp();
    int cnt=0;
    for(int i=1; i<=n; i++) {
        if (!visited[i]) {
            res.push_back(i);
            dfs(i);
            cnt++;
        }
    }
    cnt--;
    cout<<cnt<<'\n';
    if(cnt!=0)
        for(int i=0; i+1<res.size(); i++) {
            cout<<res[i]<<' '<<res[i+1]<<'\n';
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}