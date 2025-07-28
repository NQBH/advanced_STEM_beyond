#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, num_keys;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so dinh co trong AMap: ";
    cin >> num_keys;

    // Khoi tao ma tran n x n voi 0
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    cout << "Nhap AMap (u, so dinh ke, cac cap v w):\n";
    for (int i = 0; i < num_keys; ++i) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            int v, w;
            cin >> v >> w;
            adjMatrix[u][v] = w; // Gan w cho canh tu u den v
        }
    }

    cout << "Ma tran ke (AM):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}