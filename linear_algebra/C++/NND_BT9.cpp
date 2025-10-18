#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cout << "Nhap n:";
    cin >> n;
    if (n <= 0) {
        cout << "Nhap lai khong duoc so nho hon hoac bang 0 nha!!!!!!!!!!!!";
        return 1;
    }
    vector<vector<int>> a(n, vector<int>(n, 0));
    cout << "Ma tran (" << n << "x" << n << ")\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    bool cheo = true, tren = true, duoi = true, doixung = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = a[i][j];
            if (i != j && x != 0) cheo = false;
            if (i > j && x != 0) tren = false;
            if (i < j && x != 0) duoi = false;
            if (a[i][j] != a[j][i]) doixung = false;
        }
    }
    cout << (cheo ? "matrix duong cheo\n" : "khong phai matrix duong cheo\n");
    cout << (tren ? "matrix duong tren\n" : "khong phai matrix duong tren\n");
    cout << (duoi ? "matrix duong duoi\n" : "khong phai matrix duong duoi\n");
    cout << (doixung ? "doi xung\n" : "khong doi xung\n");
    return 0;
}