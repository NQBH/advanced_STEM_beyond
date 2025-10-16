#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;

    cout << "NHẬP SỐ HÀNG DỌC: ";
    cin >> m;
    cout << "NHẬP SỐ HÀNG NGANG: ";
    cin >> n;

    vector<vector<int>> A(m, vector<int>(n));

    cout << "NHẬP GIÁ TRỊ CHO MA TRẬN A (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }


    int p;
    cout << "NHẬP KÍCH THƯỚC VECTOR b: ";
    cin >> p;
    vector<int> b(p);
    cout << "NHẬP GIÁ TRỊ CHO VECTOR b:\n";
    for (int i = 0; i < p; ++i) {
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }


    cout << "\nHÀNG NGANG: " << n << '\n';
    cout << "HÀNG DỌC: " << m << '\n';

    if (m != p) {
        cout << "Impossible";
    } else {
        vector<vector<int>> Ab(m, vector<int>(n + 1));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                Ab[i][j] = A[i][j];
            Ab[i][n] = b[i];
        }

        cout << "\nMA TRẬN BỔ SUNG [A | b]:\n";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= n; ++j)
                cout << Ab[i][j] << " ";
            cout << '\n';
        }
    }

    return 0;
}
