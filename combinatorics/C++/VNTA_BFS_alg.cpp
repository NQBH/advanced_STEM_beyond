#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
using namespace std;

int n, vs, vt;
vector<int> adj[1001];
vector<vector<int>> allPaths;

void bfs(int s, int e) {
    queue<vector<int>> q;
    q.push({s});
    while (!q.empty()) {
        vector<int> path=q.front(); q.pop();
        int last=path.back();
        if (last==e) {
            allPaths.push_back(path);
        } else {
            for (int v : adj[last]) {
                if (find(path.begin(),path.end(),v)==path.end()) {
                    vector<int> newPath=path;
                    newPath.push_back(v);
                    q.push(newPath);
                }
            }
        }
    }
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
    bfs(vs, vt);
    cout<<allPaths.size()<<"\n";
    for (auto &p : allPaths) {
        for (int v : p) cout<<v<<" ";
        cout<<"\n";
    }
}