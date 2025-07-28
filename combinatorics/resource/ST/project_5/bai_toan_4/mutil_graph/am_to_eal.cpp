#include <iostream>
#include <vector>

using namespace std;

// Ham chuyen AM sang EAL cho da do thi
vector<vector<pair<int, int>>> amToEAL(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<pair<int, int>>> eal(n); // Tao danh sach rong

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight = matrix[i][j]; // So canh tu i den j
            if (weight > 0) {
                eal[i].emplace_back(j, weight); // Them (j, weight)
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
    cout << "Nhap ma tran ke:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    // Thuc hien chuyen doi
    auto eal = amToEAL(matrix);

    cout << "Danh sach ke mo rong (EAL):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (auto [v, w] : eal[i]) {
            cout << "(" << v << "," << w << ") ";
        }
        cout << endl;
    }

    return 0;
}