#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n, p;
    cout << "Nhap so hang, cot cua A va cot cua B: ";
    cin >> m >> n >> p;

    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(p));

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j)
            cin >> B[i][j];

    vector<vector<int>> C(m, vector<int>(p, 0));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];

    cout << "Tich hai ma tran la:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
