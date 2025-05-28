#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int cnt = 0;
vector<string>a;
int n, m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

vector<int>adj[100005];
vector<bool>check(100005, false);
vector<int> father;
/*
phan tich:
tim K thanh phan lien thong -> chon 1 dinh lam bo (father) --> noi K - 1 bo vao 1 tplt G, G se noi tat ca TPLT
*/

void dfs(int u) {
    check[u] = true;
    for (auto v : adj[u]) {
        if (!check[v]) {
            dfs(v);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            father.push_back(i);
            dfs(i);
        }
    }
    cout << father.size() - 1 << endl;
    int G = father[0];
    for (int i = 1; i < father.size(); i++) {
        cout << G << " " << father[i] << endl;
    }
}