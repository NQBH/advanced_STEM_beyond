#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    // Khai báo ma trận A 
    vector<vector<int>> A(n, vector<int>(n));

    cout << "Nhap ma tran (" << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Hang " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    // In ma trận A
    cout << "Ma tran A:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Tạo ma trận đơn vị B
    vector<vector<int>> B(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        B[i][i] = 1;
    }

    // In ma trận đơn vị B
    cout << "Ma tran don vi:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
