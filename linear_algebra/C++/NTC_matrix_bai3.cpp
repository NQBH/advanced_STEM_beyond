#include <iostream>
using namespace std;

int main() {
    int a[50][50];
    int hang, cot;
    int c;
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

    cout << "\nNhập hằng số c cần nhân: ";
    cin >> c;

    cout << "\nKết quả ma trận A x " << c << " là:" << endl;
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << a[i][j] * c << "\t";
        }
        cout << endl;
    }

    return 0;
}