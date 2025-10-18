#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang va cot cua ma tran: ";
    cin >> m >> n;

    vector<vector<int>> A(m, vector<int>(n)), B(m, vector<int>(n));
    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> B[i][j];

    vector<vector<int>> C(m, vector<int>(n));

    cout << "Chon phep toan (+ hoac -): ";
    char op;
    cin >> op;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = (op == '+') ? (A[i][j] + B[i][j]) : (A[i][j] - B[i][j]);

    cout << "Ket qua la:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
