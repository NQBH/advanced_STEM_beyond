#include <iostream>
using namespace std;

int main() {
    int n;
    
    do {
        cout << "Nhap so luong phan tu n (n > 0): ";
        cin >> n;
        if (n <= 0) {
            cout << "Vui long nhap n > 0!\n";
        }
    } while (n <= 0);
    
    int dem_so_0 = 0;
    int dem_so_am = 0;
    int dem_so_duong = 0;
    
    cout << "\nNhap " << n << " so thuc:\n";
    for (int i = 0; i < n; i++) {
        double a;
        cout << "Nhap so thu " << (i + 1) << ": ";
        cin >> a;
        
        if (a == 0) {
            dem_so_0++;
        } else if (a < 0) {
            dem_so_am++;
        } else {
            dem_so_duong++;
        }
    }
    
    cout << "\n===== KET QUA =====\n";
    cout << "So luong so 0: " << dem_so_0 << endl;
    cout << "So luong so am: " << dem_so_am << endl;
    cout << "So luong so duong: " << dem_so_duong << endl;
    return 0;
}