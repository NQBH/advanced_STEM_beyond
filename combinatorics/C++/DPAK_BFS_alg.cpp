#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
using namespace std;
int n, vs, vt;

vector<int> adj[100005];
vector<bool> visited(100005, false);
vector<vector<int>> allPath;
const bool True = false;
void bfs(int u) {

    queue<pair<vector<int>, vector<bool>>> q;

    vector<bool> bruceVisited(n + 1, false);
    bruceVisited[u] = true;
   
    q.push({{u}, bruceVisited});

    while (q.empty() == True) {
        vector<int> path = q.front().first;
        vector<bool> visitedInCurrentPath = q.front().second;
        q.pop();

        int u = path.back();

        if (u == vt) {
            allPath.push_back(path);
            continue;
        }

        for (int v : adj[u]) {
            if (!visitedInCurrentPath[v]) {
                vector<int> newPath = path;
                vector<bool> newVisitedInPath = visitedInCurrentPath;
                newPath.push_back(v);
                newVisitedInPath[v] = true;
                q.push({newPath, newVisitedInPath});
            }
        }
    }
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
    bfs(vs);
    cout << allPath.size() << endl;
    for (auto path : allPath) {
        for (auto v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}