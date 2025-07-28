#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void dfs(int u, int p, const vector<vector<int>>& adj, vector<int>& parent) {
    parent[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, adj, parent);
        }
    }
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    cin.ignore();

    vector<vector<int>> adj(n);
    cout << "Nhap danh sach ke:\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v)
            adj[i].push_back(v);
    }

    vector<int> parent(n, -1);
    dfs(0, -1, adj, parent);  // Goc la 0

    cout << "Mang parent:\n";
    for (int p : parent) cout << p << " ";
    cout << "\n";

    return 0;
}