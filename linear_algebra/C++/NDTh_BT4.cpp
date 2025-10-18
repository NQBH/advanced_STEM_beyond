#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int m, n, p;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    cout << "Nhap so hang cua ma tran A: ";
    cin >> m;
    cout << "Nhap so cot cua ma tran A (dong cua B): ";
    cin >> n;
    cout << "Nhap so cot cua ma tran B: ";
    cin >> p;

    cout << "Nhap ma tran A (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Nhap ma tran B (" << n << "x" << p << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];

    // Nhân A (m x n) v?i B (n x p) = C (m x p)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nA x B = \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}