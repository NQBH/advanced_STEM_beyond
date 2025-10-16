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
    vector<vector<double>> B(m, vector<double>(n));
    vector<vector<double>> C(m, vector<double>(n));

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> B[i][j];

    cout << "\nMa tran tong (A + B):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nMa tran hieu (A - B):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
