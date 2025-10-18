#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m, so cot n: ";
    cin >> m >> n;
    vector<vector<double > > A(m, vector<double>(n));
    vector<vector<double > > T(n, vector<double>(m));
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            T[j][i] = A[i][j];
    cout << "\nMa tran chuyen vi A^T:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << T[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
