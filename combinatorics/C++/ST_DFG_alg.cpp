#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int MAX = 1005;
vector<int> adj[MAX];
bool visited[MAX];
vector<int> path;
int n, vs, vt;

void dfsAllPaths(int u) {
    path.push_back(u);
    visited[u] = true;

    if (u == vt) {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfsAllPaths(v);
            }
        }
    }
    visited[u] = false;
    path.pop_back();
}

int main() {
    cin >> n >> vs >> vt;
    cin.ignore();

    for (int u = 1; u <= n; ++u) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v && v != 0) {
            adj[u].push_back(v);
        }
    }

    cout << "Cac duong di tu " << vs << " den " << vt << ":\n";
    dfsAllPaths(vs);

    return 0;
}