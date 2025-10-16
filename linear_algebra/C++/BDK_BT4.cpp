#include <iostream>
using namespace std;

int main() {
    int m, n, p;
    double A[100][100], B[100][100], C[100][100];

    cout << "Nhap 3  phan tu  ";
    cin >> m >> n >> p;

    cout << "ma tran A (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "bo vao day  ma tran B (" << n << "x" << p << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];


    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    cout << "su dung day la Ma tran A * B \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
