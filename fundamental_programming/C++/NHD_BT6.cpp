//Bai Tap 6
#include <bits/stdc++.h>
using namespace std;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << " Nhap a= " << a << endl;
    cout << "Nhap b=" << b << endl;
    cout << "Nhap c=" << c << endl;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh da cho co vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh da cho vo nghiem" << endl;
            }
        } else {
            double x = -c / b;
            cout << "Phuong trinh da cho co nghiem x = " << x << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh da cho vo nghiem" << endl;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh da cho co nghiem kep x = " << x << endl;
        } else {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout.precision(2);
            cout.setf(ios::fixed);
            cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }
    return 0;
}