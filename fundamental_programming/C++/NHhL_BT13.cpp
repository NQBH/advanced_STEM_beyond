#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long M, tong = 0;

    cout << "giới hạn số phần tử";
    cout << "Nhập N: ";
    cin >> n;
    cout << "Số mũ";
    cout << "Nhập m: ";
    cin >> m;
    cout << "giá trị trần của tổng";
    cout << "Nhập M: ";
    cin >> M;

    for (int i = 1; i <= n; ++i) {
        long long sohang = pow(i, m); 
        if (tong + sohang > M) {
            break;
        }
        tong += sohang;
    }
    cout << "Tổng Sm lớn Nhất (<= " << M << ") là: " << tong << endl;

    return 0;
}
