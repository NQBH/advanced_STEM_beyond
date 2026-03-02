#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n (n > 0): ";
    cin >> n;

    int dem_duong = 0;
    int dem_am = 0;
    int dem_khong = 0;
    for (int i = 1; i <= n; ++i) {
        float a;
        cout << "Nhap so thuc thu " << i << ": ";
        cin >> a;
        if (a > 0) {
            dem_duong++;
        } else if (a < 0) {
            dem_am++;
        } else {
            dem_khong++;
        }
    }
    cout << "-------------------------" << endl;
    cout << "So so duong: " << dem_duong << endl;
    cout << "So so am: " << dem_am << endl;
    cout << "So so 0: " << dem_khong << endl;

    return 0;
}