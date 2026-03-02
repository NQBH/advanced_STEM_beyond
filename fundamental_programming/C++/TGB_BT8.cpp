#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "nhap n: " << '\n';
    cin >> n;
    int So_0 = 0, So_Am = 0, So_Duong = 0;
    for (int i = 1; i <= n; ++i) {
        double a;
        cout << "so thuc thu " << i << '\n';
        cin >> a;
        if (a > 0)
            So_Duong++;
        else if (a < 0)
            So_Am++;
        else
            So_0++;

    }
    cout << "ket qua BT8" << '\n';
    cout << "so luong so duong: " << So_Duong << '\n';
    cout << "so luong so am: " << So_Am << '\n';
    cout << "so luong so khong: " << So_0 << '\n';
}
