/*
Bài toán 4 (Nhân 2 ma trận). Viết chương trình Python, C++ để nhân 2 ma trận A thuộc R mxn, B thuộc R nxp
*/

#include <iostream>

using namespace std;

int main() {
    int m, n, p;
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    cout << "Nhap so cot cua ma tran B: ";
    cin >> p;
    cout << "\nKhong can nhap hang cua ma tran B vi hang cua ma tran B = cot cua ma tran A (quy luat)" << endl;

    int A[m][n], B[n][p];
    int ketqua[m][p];

    cout << "\nNhap cac phan tu cua ma tran A: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nNhap cac phan tu cua ma tran B: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            ketqua[i][j] = 0; // khoi tao gia tri ban dau
            for (int k = 0; k < n; k++) {
                ketqua[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMa tran sau khi nhan A * B la: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << ketqua[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}