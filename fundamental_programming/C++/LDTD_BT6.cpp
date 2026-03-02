#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a = -1;
    double b = -5;
    double c = -7;

    cout << "Nhap so a: "; cin >> a;
    cout << "Nhap so b: "; cin >> b;
    cout << "Nhap so c: "; cin >> c;

    cout << "\nPhuong trinh: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

    if (a == 0) {
        // Nếu a = 0, phương trình trở thành bậc nhất: bx + c = 0
        if (b == 0) {
            if (c == 0) cout << "Phuong trinh vo so nghiem." << endl;
            else cout << "Phuong trinh vo nghiem." << endl;
        } else {
            cout << "Phuong trinh co nghiem duy nhat x = " << -c / b << endl;
        }
    } else {
        // Giải phương trình bậc hai
        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Phuong trinh vo nghiem (nghiem phuc)." << endl;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep x1 = x2 = " << x << endl;
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