#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n, p;
    cout << "Nhap so hang ma tran A: ";
    cin >> m;
    cout << "Nhap so cot ma tran A (va so hang ma tran B): ";
    cin >> n;
    cout << "Nhap so cot ma tran B: ";
    cin >> p;

    vector<vector<double>> A(m, vector<double>(n));
    vector<vector<double>> B(n, vector<double>(p));
    vector<vector<double>> C(m, vector<double>(p, 0));

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j)
            cin >> B[i][j];

    // Tính tích C = A * B
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];

    cout << "\nMa tran tich C = A * B:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
