#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
using namespace std;

int n, vs, vt;
vector<int> adj[1001];
bool visited[100001];
vector<int> path;
vector<vector<int>> allPaths;

void dfs(int u) {
    visited[u]=true;
    path.push_back(u);
    if (u==vt) {
        allPaths.push_back(path);
    } else {
        for (int v:adj[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }
    visited[u]=false;
    path.pop_back();
}

int main(){
    KhangGPT40_TramAnhGrok3;
    cin>>n>>vs>>vt;
    cin.ignore();
    for (int i=1; i<=n; i++) {
        string s, num;
        getline(cin, s);
        if (s=="0") continue;
        stringstream ss(s);
        while(ss>>num){
            adj[i].push_back(stoi(num));
        }
    }
    dfs(vs);
    cout<<allPaths.size()<<"\n";
    for (auto &p : allPaths) {
        for (int v : p) cout<<v<<" ";
        cout<<"\n";
    }
}