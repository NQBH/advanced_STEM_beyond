#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));

    cout << "Nhap ma tran (" << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Hang " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    bool duongcheo = true, tamgiactren = true, tamgiacduoi = true, doixung = true;

    // Kiểm tra các tính chất
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && A[i][j] != 0)
                duongcheo = false;
            if (i < j && A[i][j] != 0)
                tamgiactren = false;
            if (i > j && A[i][j] != 0)
                tamgiacduoi = false;
            if (A[i][j] != A[j][i])
                doixung = false;
        }
    }

    // In ma trận
    cout << "Ma tran A:";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Xuất kết quả
    cout << "**** Ket qua kiem tra ****";
    cout << "Ma tran duong cheo: " << (duongcheo ? "Co" : "Khong") << endl;
    cout << "Ma tran tam giac tren: " << (tamgiactren ? "Co" : "Khong") << endl;
    cout << "Ma tran tam giac duoi: " << (tamgiacduoi ? "Co" : "Khong") << endl;
    cout << "Ma tran doi xung: " << (doixung ? "Co" : "Khong") << endl;

    return 0;
}
