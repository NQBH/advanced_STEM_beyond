#include <iostream>
using namespace std;
void demChanLe(int n) {
    int dem_chan = 0;
    int dem_le = 0;

    cout << "\nNhap " << n << " so nguyen:\n";
    for (int i = 0; i < n; i++) {
        int so;
        cout << "Nhap so thu " << (i + 1) << ": ";
        cin >> so;

        if (so % 2 == 0) {
            dem_chan++;
        } else {
            dem_le++;
        }
    }

    cout << "\n===== KET QUA =====\n";
    cout << "So luong so chan: " << dem_chan << endl;
    cout << "So luong so le: " << dem_le << endl;
}

int main() {
    int n;
    do {
        cout << "Nhap so luong phan tu n (n > 0): ";
        cin >> n;
        if (n <= 0) {
            cout << "Vui long nhap n > 0!\n";
        }
    } while (n <= 0);
    demChanLe(n);

    return 0;
}