#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c;

    cout << "--- Giai phuong trinh bac 2 (Ho tro nghiem phuc) ---" << endl;
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap b: "; cin >> b;
    cout << "Nhap c: "; cin >> c;

    cout << fixed << setprecision(2);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Phuong trinh co vo so nghiem." << endl;
            else cout << "Phuong trinh vo nghiem." << endl;
        } else {
            cout << "Nghiem duy nhat: x = " << -c / b << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;

        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem thuc phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep thuc: x = " << -b / (2 * a) << endl;
        } else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-delta) / (2 * a);

            cout << "Phuong trinh co 2 nghiem phuc:" << endl;
            cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
            cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }

    return 0;
}