// 2
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang = "; cin >> m;
    cout << "Nhap so cot = "; cin >> n;

    int A[100][100], B[100][100];

    cout << "Ma tran E:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Ma tran F:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    cout << "Ma tran E + F:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Ma tran E - F:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}