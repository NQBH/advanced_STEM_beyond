#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang m = "; cin >> m;
    cout << "Nhap so cot n = "; cin >> n;

    int A[100][100];
    cout << "Nhap ma tran A:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Ma tran chuyen vi A^T la:" << endl;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
