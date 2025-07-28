#include <iostream>
#include <vector>

using namespace std;

// Ham chuyen AM sang AL
vector<vector<int>> amToAl(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> al(n);

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (matrix[u][v] == 1) {
                al[u].push_back(v); // Neu co canh tu u den v thi them v vao danh sach ke cua u
            }
        }
    }

    return al;
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

    vector<vector<int>> al = amToAl(matrix);

    cout << "Danh sach ke (AL):\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (int v : al[u])
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}