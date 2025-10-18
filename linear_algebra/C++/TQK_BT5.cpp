#include <iostream>
using namespace std;

int main() {
    int m, n;
    int A[100][100], At[100][100];

    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    // Chuyển vị: A_T[j][i] = A[i][j]
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            At[j][i] = A[i][j];

    cout << "Ma tran chuyen vi A^T:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << At[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
