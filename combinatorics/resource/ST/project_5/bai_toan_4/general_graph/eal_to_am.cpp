#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;

    // Khoi tao ma tran ke n x n toan 0
    vector<vector<int>> am(n, vector<int>(n, 0));

    cout << "Nhap danh sach ke mo rong (u v w):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        am[u][v] = w;  // Gan so luong canh tu u den v
    }

    // In ma tran ke
    cout << "Ma tran ke (AM):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << am[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
