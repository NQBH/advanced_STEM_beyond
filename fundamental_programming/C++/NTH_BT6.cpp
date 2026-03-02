#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
    double a, b, c;

    cout << "--- Giai phuong trinh ax^2 + bx + c = 0 ---" << endl;
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap b: "; cin >> b;
    cout << "Nhap c: "; cin >> c;

    cout << fixed << setprecision(2);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Phuong trinh co vo so nghiem." << endl;
            else cout << "Phuong trinh vo nghiem." << endl;
        } else {
            cout << "Phuong trinh bac nhat co nghiem: x = " << -c / b << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Phuong trinh vo nghiem thuc." << endl;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x = " << x << endl;
        } else {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }

    return 0;
}