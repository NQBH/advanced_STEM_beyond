#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;

    // Khoi tao danh sach ke
    vector<vector<int>> adjList(n);

    cout << "Nhap danh sach ke mo rong (u v w):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(v); // Bo qua trong so w
    }

    cout << "Danh sach ke (AL):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int v : adjList[i])
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}