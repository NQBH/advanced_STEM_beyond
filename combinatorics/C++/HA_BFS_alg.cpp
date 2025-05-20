#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

int n, vs, vt;
vector<int> adj[1001];
vector<vector<int>> allPaths;
int minDist = -1;

void bfs() {
    queue<vector<int>> q;
    vector<int> dist(1001, -1);

    q.push({vs});
    dist[vs] = 0;

    while (!q.empty()) {
        vector<int> path = q.front(); q.pop();
        int u = path.back();

        // Stop if current path is already longer than shortest found
        if (minDist != -1 && path.size() - 1 > minDist) continue;

        if (u == vt) {
            if (minDist == -1 || path.size() - 1 == minDist) {
                minDist = path.size() - 1;
                allPaths.push_back(path);
            }
            continue;
        }

        for (int v : adj[u]) {
            // Only go forward if:
            // - this node hasn't been visited
            // - or we can reach it in the same shortest distance
            if (dist[v] == -1 || dist[v] >= dist[u] + 1) {
                dist[v] = dist[u] + 1;
                vector<int> newPath = path;
                newPath.push_back(v);
                q.push(newPath);
            }
        }
    }
}

int main() {
    FastIO;
    cin >> n >> vs >> vt;
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        if (s == "0") continue;
        stringstream ss(s);
        int v;
        while (ss >> v) {
            adj[i].push_back(v);
        }
    }

    bfs();

    cout << allPaths.size() << "\n";
    for (auto &p : allPaths) {
        for (int v : p) cout << v << " ";
        cout << "\n";
    }
}