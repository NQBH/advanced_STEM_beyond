#include <iostream>
using namespace std;

int main() {
    int m, n, p;
    cout << "Nhap so hang = "; cin >> m;
    cout << "Nhap so cot = "; cin >> n;
    cout << "Nhap so cot cua ma tran B (p) = "; cin >> p;

    int A[100][100], B[100][100], C[100][100] = {0};

    cout << "Nhap ma tran A (" << m << "x" << n << "):" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Nhap ma tran B (" << n << "x" << p << "):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Ket qua A * B la:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}