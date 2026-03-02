#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    // M va tong dung long long cho chac an
    long long M;
    long long tong = 0;

    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap gioi han M: ";
    cin >> M;

    // Duyet tu 1 den n
    for (int i = 1; i <= n; i++) {
        // Tinh so hang hien tai (i mu m)
        long long soHang = pow(i, m);

        // Kiem tra neu cong them ma vuot qua M thi dung lai
        if (tong + soHang <= M) {
            tong = tong + soHang;
        } else {
            // Dung lenh break de thoat vong lap ngay lap tuc
            break;
        }
    }

    cout << "Tong lon nhat tim duoc la: " << tong;

    return 0;
}