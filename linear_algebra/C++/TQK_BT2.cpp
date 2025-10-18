#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    int A[100][100], B[100][100], C[100][100];

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }

    // Cộng
    cout << "Ma tran A + B:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    // Trừ
    cout << "Ma tran A - B:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
