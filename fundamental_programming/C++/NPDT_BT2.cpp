#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double d, r;
    cout << "nhap chieu dai: ";
    cin >> d;
    cout << "nhap chieu rong: ";
    cin >> r;
    while (d <= 0 || r <= 0) {
        cout << "loi so, vui long nhap lai " << endl;
        cin >> d >> r;
    }
    
    cout << "chu vi hinh chu nhat: " << (d + r)*2 << endl;
    cout << "dien tich hinh chu nhat: " << d*r << endl;
    cout << "do dai duong cheo: " << sqrt(d*d + r*r) << endl;

}