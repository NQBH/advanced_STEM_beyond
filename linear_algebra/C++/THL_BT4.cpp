#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n, p;
    cout << "Nhap kich thuoc ma tran A (m x n): ";
    cin >> m >> n;
    cout << "Nhap so cot cua ma tran B (p): ";
    cin >> p;
    vector<vector<double> > A(m, vector<double>(n));
    vector<vector<double> > B(n, vector<double>(p));
    vector<vector<double> > C(m, vector<double>(p, 0));
    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j)
            cin >> B[i][j];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
    cout << "\nKet qua A * B:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j)
            cout << C[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
