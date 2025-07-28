#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, num_keys;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so dinh co trong AMap: ";
    cin >> num_keys;

    // Khoi tao danh sach ke
    vector<vector<int>> adjList(n);

    cout << "Nhap AMap (u, so dinh ke, cac cap v w):\n";
    for (int i = 0; i < num_keys; ++i) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            int v, w;
            cin >> v >> w; // Bo qua w
            adjList[u].push_back(v);
        }
    }

    cout << "Danh sach ke (AL):\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (int v : adjList[u]) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}