//BT9
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhap cap ma tran vuong n: ";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    cout << "Nhap cac phan tu cua ma tran (" << n*n << " so):\n";
    for (auto &r : a)
        for (auto &x : r)
            cin >> x;

    bool ch = true, up = true, low = true, sym = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i != j && a[i][j] != 0) ch = false;
            if (i > j && a[i][j] != 0) up = false;
            if (i < j && a[i][j] != 0) low = false;
            if (a[i][j] != a[j][i]) sym = false;
        }

    cout << "\n==> Ket qua kiem tra:\n";
    cout << "Ma tran duong cheo: " << (ch ? "Co\n" : "Khong\n");
    cout << "Ma tran tam giac tren: " << (up ? "Co\n" : "Khong\n");
    cout << "Ma tran tam giac duoi: " << (low ? "Co\n" : "Khong\n");
    cout << "Ma tran doi xung: " << (sym ? "Co" : "Khong");
}
