//tính định thức của ma trận THỰC 2 x 2 có dạng (a b; c d ) được định nghĩa bởi det A = ad - bc
#include <iostream>
using namespace std;
int main() {
    int m = 2;
    int n = 2;
    int a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }
    cout << "ma tran vua nhap la: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    cout << "\ndinh thuc cua ma tran la: " << det;
}