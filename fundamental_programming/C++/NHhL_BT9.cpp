#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Nhập N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: n Phải > 0. Chương Trình Kết Thúc!";
        return 0;
    }

    int a;
    int demChan = 0;
    int demLe = 0;

    cout << "Nhập " << n << " Số Nguyên:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Nhập số thứ " << i << ": ";
        cin >> a;

        if (a % 2 == 0) {
            demChan = demChan + 1;
        } else {
            demLe = demLe + 1;
        }
    }

    cout << "Kết Quả" << endl;
    cout << "số lượng số chẵn: " << demChan << endl;
    cout << "số lượng số lẻ:   " << demLe << endl;

    return 0;
}
