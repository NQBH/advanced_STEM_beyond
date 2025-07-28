#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// Ham chuyen danh sach ke sang adjacency map
map<int, map<int, int>> alToAmap(const vector<vector<int>>& adjList) {
    map<int, map<int, int>> amap;

    for (int u = 0; u < adjList.size(); ++u) {
        for (int v : adjList[u]) {
            amap[u][v] = 1; // Gan trong so 1 cho canh u -> v
        }
    }

    return amap;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    cin.ignore(); // Bo ky tu xuong dong

    vector<vector<int>> adjList(n);
    cout << "Nhap danh sach ke (AL):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v)
            adjList[i].push_back(v);
    }

    auto amap = alToAmap(adjList);

    cout << "Adjacency Map (AMap):\n";
    for (const auto& [u, inner] : amap)
        for (const auto& [v, w] : inner)
            cout << u << " -> " << v << ": " << w << "\n";

    return 0;
}