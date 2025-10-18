#include <iostream>
using namespace std;

int main() {
    int m, n, p;
    int A[100][100], B[100][100], C[100][100];

    cout << "Nhap so hang ma tran A (m): ";
    cin >> m;
    cout << "Nhap so cot ma tran A (n) = so hang ma tran B: ";
    cin >> n;
    cout << "Nhap so cot ma tran B (p): ";
    cin >> p;

    // Nhập A
    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    // Nhập B
    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }

    // Nhân ma trận
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    // In kết quả
    cout << "Ma tran C = A * B:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            cout << C[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
