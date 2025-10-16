#include <iostream>
using namespace std;
int main() {
    int m, n;
    cout << "Nhap hang va cot: ";
    cin >> m >> n;
    double A[m][n], B[m][n], C[m][n];
    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m ; i++)
        for ( int j = 0; j < n; j++)
            cin >> A[m][n];
    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> B[m][n];

    cout << "A+B= \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
    }
    cout << endl;
    cout << "A-B= \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}