#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << "nhap n:" << n << endl;

    double a;
    int soChan = 0, soDuong = 0, soAm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > 0) {
            soDuong++;
        } else if (a < 0) {
            soAm++;
        } else {
            soChan++;
        }
    }
    cout << "so duong: " << soDuong << endl;
    cout << "so am: " << soAm << endl;
    cout << "so chan: " << soChan << endl;
    return 0;
}
