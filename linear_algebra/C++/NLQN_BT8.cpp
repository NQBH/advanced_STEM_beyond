// nhập vào số n nguyên dương rồi lưu trữ & xuất ra ma trận 0 (gồm toàn số 0) & ma trận đơn vị (phần tử = 1 trên đường chéo chính, còn lại đều là 0) kích thước n x n
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "nhap n: ";
    cin >> n;
    int a[n][n], b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
            if (i == j) {
                b[i][j] = 1;
            } else {
                b[i][j] = 0;
            }
        }
    }
    cout << "ma tran 0: " << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "ma tran don vi: " << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}