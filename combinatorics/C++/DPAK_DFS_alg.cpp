#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
using namespace std;
int n, vs, vt;

vector<int> adj[100005];
vector<bool> visited(100005, false);
vector<vector<int>> allPath;

void dfs(int u, vector<int>& path) {
    path.push_back(u);
    visited[u] = true;

    if (u == vt) {
        allPath.push_back(path);
    } else {
        for (auto v : adj[u]) {
            if (!visited[v]) {
                dfs(v, path);
            }
        }
    }

    visited[u] = false;
    path.pop_back();
}

int main() {
    KhangGPT40_TramAnhGrok3;
    cin >> n >> vs >> vt;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string s; getline(cin,s);
        s = s + " ";
        vector<int> a;
        string t;
        for (auto c : s) {
            if (c == ' ') {
                if (!t.empty()) {
                    a.push_back(stoi(t));
                    t.clear();
                }
            }
            else {
                t += c;
            }
        }
        for (auto u : a) {
            if (u != 0)
                adj[i].push_back(u);
        }
    }
    vector<int> tmp;
    dfs(vs, tmp);
    cout << allPath.size() << endl;
    for (auto path : allPath) {
        for (auto v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}