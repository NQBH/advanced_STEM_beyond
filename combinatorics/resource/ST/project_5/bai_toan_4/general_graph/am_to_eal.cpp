#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Ham chuyen ma tran ke AM sang danh sach ke mo rong EAL
vector<tuple<int, int, int>> amToEal(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<tuple<int, int, int>> eal;

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (matrix[u][v] == 1) {
                eal.emplace_back(u, v, 1);  // Them canh (u, v, 1)
            }
        }
    }

    return eal;
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

    vector<tuple<int, int, int>> eal = amToEal(matrix);

    cout << "Danh sach ke mo rong (EAL):\n";
    for (auto [u, v, w] : eal)
        cout << u << " " << v << " " << w << "\n";

    return 0;
}