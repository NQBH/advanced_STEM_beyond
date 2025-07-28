#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Ham chuyen AM sang AMap
map<int, map<int, int>> amToAmap(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    map<int, map<int, int>> amap; // Su dung map long nhau

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int count = matrix[i][j];
            if (count > 0) {
                amap[i][j] = count; // Gan so canh vao amap[i][j]
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
    cout << "Nhap ma tran ke:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    // Chuyen doi va in ket qua
    auto amap = amToAmap(matrix);

    cout << "Ban do ke (AMap):\n";
    for (const auto& [u, neighbors] : amap) {
        cout << u << ": ";
        for (const auto& [v, w] : neighbors) {
            cout << "(" << v << "," << w << ") ";
        }
        cout << endl;
    }

    return 0;
}