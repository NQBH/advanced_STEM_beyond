#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Ham chuyen tu ma tran ke sang adjacency map
map<int, map<int, int>> amToAmap(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    map<int, map<int, int>> amap;

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (matrix[u][v] == 1) {
                amap[u][v] = 1; // Gan trong so la 1
            }
        }
    }

    return amap;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Nhap ma tran ke (AM):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    auto amap = amToAmap(matrix);

    cout << "Adjacency Map (AMap):\n";
    for (auto& [u, inner] : amap)
        for (auto& [v, w] : inner)
            cout << u << " -> " << v << ": " << w << "\n";

    return 0;
}