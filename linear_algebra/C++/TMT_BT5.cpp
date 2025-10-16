#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    vector<vector<double>> AT(n, vector<double>(m));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            AT[j][i] = A[i][j];

    cout << "\nMa tran chuyen vi A^T:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << AT[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
