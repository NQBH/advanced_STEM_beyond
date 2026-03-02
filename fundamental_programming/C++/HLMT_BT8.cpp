#include <iostream>
using namespace std;

int main() {
    int n;
    float x;
    int dem0 = 0, demAm = 0, demDuong = 0;

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> x;

        if (x == 0)
            dem0++;
        else if (x < 0)
            demAm++;
        else
            demDuong++;
    }
cout << "So so 0: " << dem0 << endl;
cout << "So so am: " << demAm << endl;
cout << "So so duong: " << demDuong << endl;

    return 0;
}