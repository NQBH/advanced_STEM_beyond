#include <iostream>
using namespace std;
int main () {
    int n;
    double x;
    double dem0 = 0, demAm = 0, demDuong = 0;
    double num;
    cout << "nhap vao so n thuc: " << endl;
    for (int i = 0; i <= n; i++) {
        cout << "nhap so: ";
        cin >> num;
        if (num == 0) {
            dem0 += 1;
        }
        if (num > 0) {
            demDuong += 1;
        }
        if (num < 0) {
            demAm += 1;
        }
    }
    cout << "so duong: " << demDuong << endl;
    cout << "so am: " << demAm << endl;
    cout << "so 0: " << dem0 << endl;
}