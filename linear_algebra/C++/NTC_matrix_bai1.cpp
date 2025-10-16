#include <iostream>
using namespace std;

int main() {
    int a[50][50];
    int hang, cot;
    cout << "Nhập số hàng: ";
    cin >> hang;
    cout << "Nhập số cột: ";
    cin >> cot;

    cout << "Hãy nhập ma trận:" << endl;
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << "Nhập a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    cout << "\nMa trận bạn vừa nhập là:" << endl;
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}