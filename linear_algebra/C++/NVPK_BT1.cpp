#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m va so cot n cua ma tran A: ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap ma tran A (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    vector<double> b(m);
    cout << "Nhap vector b (" << m << " phan tu):\n";
    for (int i = 0; i < m; ++i)
        if (!(cin >> b[i])) {
            cout << "Impossible\n";
            return 0;
        }
    cout << "Ma tran bo sung [A|b]:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << A[i][j] << " ";
        cout << "| " << b[i] << "\n";
    }

    return 0;
}