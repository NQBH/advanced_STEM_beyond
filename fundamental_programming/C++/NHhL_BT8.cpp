#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    cout << "Nhập số lượng n: ";
    cin >> n;

    if (n <= 0) {
        cout << "error: n phải là số dương (> 0). Kết Thúc Chương Trình!";
        return 0;
    }

    int demduong = 0;
    int demam = 0;
    int dekhong = 0;
    double val;

    cout << "bắt đầu nhập " << n << " số " << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Nhập số thứ " << i << ": ";
        cin >> val;

        if (val > 0) {
            demduong = demduong + 1;
        } else if (val < 0) {
            demam = demam + 1;
        } else {
            dekhong = dekhong + 1;
        }
    }

    cout << endl << "Kết Quả" << endl;
    cout << "Số Dương: " << demduong << endl;
    cout << "Số Âm:    " << demam << endl;
    cout << "Số 0:     " << dekhong << endl;

    return 0;
}
