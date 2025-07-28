#include <bits/stdc++.h>
using namespace std;

int n, m, s=0;
vector<pair<int,int>> edges; //cạnh (u->v)
vector<int> chosen; //index các cạnh đang chọn

//subgraph với các cạnh đang chọn
vector<vector<int>> adj;
vector<int> indeg;

//0: chưa thăm, 1: đang thăm, 2: đã thăm
bool hasCycleUtil(int u, vector<int>&color) {
    color[u]=1;
    for (int v : adj[u]) {
        if (color[v]==1) return true;
        if (color[v]==0 && hasCycleUtil(v,color)) return true;
    }
    color[u]=2;
    return false;
}

bool hasCycle() {
    vector<int> color(n+1,0);
    for (int i=1; i<=n; ++i) {
        if (color[i]==0 && hasCycleUtil(i,color)) return true;
    }
    return false;
}

bool isArborescence() {
    //kiểm tra số cạnh
    if ((int)chosen.size() != n-1) return false;

    adj.assign(n+1, {});
    indeg.assign(n+1, 0);
    for (int idx : chosen) {
        int u=edges[idx].first, v=edges[idx].second;
        adj[u].push_back(v);
        indeg[v]++;
    }

    //tìm root (indeg == 0)
    int root=-1;
    int root_count=0;
    for (int i=1; i<=n; ++i) {
        if (indeg[i]==0) {
            root=i;
            ++root_count;
        }
    }
    if (root_count!=1) return false;

    if (hasCycle()) return false;

    //kiểm tra liên thông (DFS)
    vector<bool>visited(n+1,false);
    stack<int>stk; stk.push(root);
    visited[root]=true;
    while (!stk.empty()) {
        int u=stk.top(); stk.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                stk.push(v);
            }
        }
    }
    for (int i=1; i<=n; ++i)
        if (!visited[i]) return false;

    return true;
}

//start: idx cạnh đang xét, edges_used: số cạnh đã chọn vào chosen
void backtrack(int start, int edges_used) {
    if (edges_used==n-1) {
        if (isArborescence()) {
            s++;
            //in arborescence
            cout<<"Arborescence:\n";
            for (int idx : chosen) {
                cout<<edges[idx].first<<" -> "<<edges[idx].second<< "\n";
            }
            cout<<"------\n";
        }
        return;
    }
    //hết cạnh mà chưa chọn đủ n-1 cạnh
    if (start==m) return;

    //chọn cạnh start
    chosen.push_back(start);
    backtrack(start+1, edges_used+1);
    chosen.pop_back();

    //không chọn cạnh start
    backtrack(start+1, edges_used);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    edges.resize(m);
    for (int i=0; i<m; i++) cin>>edges[i].first>>edges[i].second;
    cout<<"Spanning arborescences:\n";
    backtrack(0, 0);
    cout<<"\nTotal spanning trees: "<<s;
    return 0;
}

/*
Input: Prob 1.3
7 12
1 2
1 3
1 4
2 4
2 5
3 6
4 6
4 7
5 7
6 1
7 6
7 2
*/
