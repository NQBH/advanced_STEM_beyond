#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;

    // Su dung map de luu AMap
    map<int, vector<pair<int, int>>> adjMap;

    cout << "Nhap danh sach ke mo rong (u v w):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjMap[u].push_back({v, w});
    }

    cout << "Adjacency Map (AMap):\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        if (adjMap.count(u)) {
            for (auto [v, w] : adjMap[u]) {
                cout << "(" << v << ", " << w << ") ";
            }
        }
        cout << "\n";
    }

    return 0;
}