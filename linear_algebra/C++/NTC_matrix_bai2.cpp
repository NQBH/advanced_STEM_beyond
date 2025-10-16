#include <iostream>
using namespace std;

int main() {
    int a[50][50], b[50][50], ans[50][50];
    int hang, cot;
    cout << "Nhập số hàng: ";
    cin >> hang;
    cout << "Nhập số cột: ";
    cin >> cot;

    cout << "\nNhập ma trận A:" << endl;
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << "Nhập a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    cout << "\nNhập ma trận B:" << endl;
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << "Nhập b[" << i << "][" << j << "]: ";
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            ans[i][j] = a[i][j] + b[i][j];
        }
    }
    cout << "\nTổng ma trận A + B:" << endl;
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            ans[i][j] = a[i][j] - b[i][j];
        }
    }
    cout << "\nHiệu ma trận A - B:" << endl;
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}